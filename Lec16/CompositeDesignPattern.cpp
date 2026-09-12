#include <iostream>
#include <vector>
using namespace std;

class FileSystemItem {
public:
    virtual void Ls(int indent = 0) = 0;
    virtual void openAll(int indent = 0) = 0;
    virtual int getSize() = 0;
    virtual FileSystemItem* cd(const string& name) = 0;
    virtual string getName() = 0;
    virtual bool isFolder() = 0;

    virtual ~FileSystemItem() { }
};

class File : public FileSystemItem {
private:
    string name;
    int size;
public:
    File(string name, int size) {
        this->name = name;
        this -> size = size;
    }

    void Ls(int indent = 0) override {
        cout<<string(indent, ' ') + name << "\n";
    }

    void openAll(int indent = 0) override {
        cout<<string(indent, ' ') + name << "\n";
    }

    int getSize() override {
        return size;
    }

    FileSystemItem* cd(const string& name) override {
        return nullptr;
    }

    string getName() override {
        return name;
    }

    bool isFolder() override {
        return false;
    }
};


class Folder : public FileSystemItem {
private:
    string name;
    vector<FileSystemItem*> children;
public:

    Folder(string name) {
        this->name = name;
    }

    ~Folder() {
        for (auto c : children) delete c;
    }

    void add(FileSystemItem* item) {
        children.push_back(item);
    }

    void Ls(int indent = 0) override {
        for(auto child : children) {
            if (child->isFolder()) {
                cout <<string(indent, ' ') << "+ " << child->getName() << "\n";
            } else {
                cout << string(indent, ' ') << child -> getName() << "\n";
            }
        }
    }

    void openAll(int indent = 0) override {
        cout << string(indent, ' ') << "+ " << name << "\n";
        for (auto child : children) {
            child -> openAll(indent + 4);
        }
    }

    int getSize() override {
        int totalSize = 0;
        for (auto child : children) {
            totalSize += child -> getSize();
        }
        return totalSize;
    }

    FileSystemItem* cd(const string& name) override {
        for (auto child : children) {
            if(child->isFolder() && child ->getName() == name) {
                return child;
            }
        }
    }

    string getName() override {
        return name;
    }

    bool isFolder() override {
        return true;
    }
};


int main() {
    Folder* root = new Folder("root");
    root -> add(new File("file1.txt", 1));
    root -> add(new File("file2.txt", 1));

    Folder* docs = new Folder("docs");
    docs -> add(new File("aadhar.png", 1));
    docs -> add(new File("Pan.png", 1));
    root -> add(docs);

    Folder* images = new Folder("images");
    images -> add(new File("pranav.png", 1));
    images -> add(new File("Pratik.png", 1));
    root -> add(images);

    cout<<"Ls"<<"\n";
    root -> Ls(0);

    cout<<"\nOpen All"<<"\n";
    root -> openAll(0);

    cout<<"\nSize => "<<root ->getSize()<<"\n";

    cout<<"\nName => "<<root ->getName()<<"\n";

    cout<<"\nCd Trying\n";
    FileSystemItem* cdTry = root->cd("images");

    if (cdTry != nullptr) {
        cout<<"Name => "<<cdTry -> getName()<<endl;
        cout<<"Size => " << cdTry -> getSize()<<endl;
        cdTry -> openAll();
    } else {
        cout<<"images doesn't exists";
    }
}