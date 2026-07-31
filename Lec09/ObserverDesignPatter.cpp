#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Channel;

class ISubscriber {
public:
    virtual void update() = 0;
    virtual void setChannel(Channel* c) = 0;
    ~ISubscriber() {}
};

class IChannel {
public:
    virtual void Subscribe(ISubscriber* s) = 0;
    virtual void Unsubscribe(ISubscriber* s) = 0;
    virtual void notify() = 0;
    ~IChannel() {}
};


class Channel : public IChannel {
private:
    string name;
    vector<ISubscriber*> subscribers;
    string latestVideo;

public:
    Channel(string name) {
        this -> name = name;
    }

    void Subscribe(ISubscriber* s) {
        if (find(subscribers.begin(), subscribers.end(), s) == subscribers.end()) {
            subscribers.push_back(s);
            s -> setChannel(this);
        }
    }

    void Unsubscribe(ISubscriber* s) {
        auto it = find(subscribers.begin(), subscribers.end(), s);

        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notify() override{
        for (auto it : subscribers) {
            it -> update();
        }
    }

    void uploadVideo(const string& title) {
        latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]\n"<<endl;
        notify();
    }

    string getLatestVideo() {
        return latestVideo;
    }

    string getName() {
        return name;
    }
};

class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;

public:

    Subscriber(string name) {
        this -> name = name;
    }

    void update() override {
        string latestVideo = channel -> getLatestVideo();
        cout<<"Hii "<<name<<", The latest video of "<<channel->getName()<<" is "<<latestVideo<<endl;
    }

    void setChannel(Channel* channel) {
        this -> channel = channel;
    }
};

int main() {
    Channel* Youtuber1 = new Channel("ThinkSchool");
    Channel* Youtuber2 =  new Channel("Khan sir");
    
    Subscriber* sub1 = new Subscriber("Pranav");
    Subscriber* sub2 = new Subscriber("Pratik");
    Subscriber* sub3 = new Subscriber("Aniket");
    
    Youtuber1 -> Subscribe(sub1);
    Youtuber2 -> Subscribe(sub2);
    Youtuber1 -> Subscribe(sub3);

    Youtuber1 -> uploadVideo("USA vs China");
    Youtuber2 -> uploadVideo("Pakistan ki mkc");

    Youtuber1 -> Unsubscribe(sub3);
    Youtuber1 -> uploadVideo("US Iran War");
}