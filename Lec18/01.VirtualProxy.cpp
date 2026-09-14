#include <iostream>
using namespace std;

class IDisplay {
public:
    virtual void display() = 0;
    virtual ~IDisplay() { } ;
};

class ImgDisplay : public IDisplay { 
    string path;
public:
    ImgDisplay(string path) {
        this -> path = path;
        cout<<"doing other heavy task"<<endl;
    }

    void display() override {
        cout<<"Display image path => "<<path<<endl;
    }
};

class ImgProxy : public IDisplay {
    string path;
    ImgDisplay* imgDisplay = nullptr;
public:
    ImgProxy(string path) {
        this -> path = path;
    }

    void display() override {
        if (imgDisplay == nullptr) {
            imgDisplay = new ImgDisplay(path);
        }
        imgDisplay -> display();
    }
};


int main() {
    IDisplay* img = new ImgProxy("pranav.png");

    // img -> display();
    // firstly run this code as it is and then uncomment above line and run then see the difference between output

    cout<<"Program ended";
}