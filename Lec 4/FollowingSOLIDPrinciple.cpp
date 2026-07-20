#include <iostream>
#include <vector>
using namespace std;

class DocumentElement {
public:
    virtual string render() = 0;
};

class TextElement : public DocumentElement {
public:
    string text;
    TextElement(string t) {
        text = t;
    }

    string render() override {
        return text;
    }
};

class ImgElement : public DocumentElement {
public:
    string img;
    ImgElement(string path) {
        img = path;
    }

    string render() override {
        return "[image: " + img + "]";
    }
};


class Document {
public:
    vector<DocumentElement*> elems;

    void addElem(DocumentElement* el) {
        elems.push_back(el);
    }

    string render() {
        string text;
        for (auto it : elems) {
            text += it -> render();
            text += "\n";
        }

        return text;
    }
};

class Persistance {
public:
    virtual void save(string) = 0;
};

class SaveToFile : public Persistance {
public: 
    void save(string data) {
        cout<<"file saved\n"<<data;
    }
}; 

class SaveToDB : public Persistance {
public: 
    void save(string data) {
        cout<<"Saved to DB\n"<<data;
    }
};

class DocumentEditor {
public:
    Document* doc = new Document();
    Persistance* db = new SaveToFile();

    void addText(string text) {
        DocumentElement* textEl = new TextElement(text);
        doc -> addElem(textEl);
    }

    void addImg(string path) {
        DocumentElement* imgEl = new ImgElement(path);
        doc -> addElem(imgEl);
    }

    string renderDoc() {
        return doc -> render();
    }


    void save(Persistance* pr) {
        pr -> save(doc -> render());
    }
};

int main() {
    DocumentEditor* doc = new DocumentEditor();
    Persistance* pDB = new SaveToDB();
    Persistance* pFile = new SaveToFile();

    doc -> addText("||Shree Ganesya Namah||");
    doc -> addText("this is real document editor");
    doc -> addImg("Ganesh.png");
    pDB->save(doc -> renderDoc());

    cout<<endl<<endl;

    pFile -> save(doc -> renderDoc());
}