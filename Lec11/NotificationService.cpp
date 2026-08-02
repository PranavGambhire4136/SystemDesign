#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class INotification {
public:
    virtual string getContent() const = 0;

    virtual ~INotification() {}
};

class SimpleNotification : public INotification {
    string text;
public:
    SimpleNotification(string text) {
        this -> text = text;
    }

    string getContent() const override {
        return text;
    }
};

class INotificationDecorator : public INotification {
public:
    INotification* notification;
    INotificationDecorator(INotification* n) {
        this -> notification = n;
    }

    virtual ~INotificationDecorator() {}
};

class TimeStampDecorator : public INotificationDecorator {
public:
    TimeStampDecorator(INotification* n) : INotificationDecorator(n){}

    string getContent() const override {
        return "[2026-08-02   11:51:48] " + notification -> getContent();
    }
};

class SignatureDecorator : public INotificationDecorator {
private:
    string Sig;
public:
    SignatureDecorator(INotification* n, string s): INotificationDecorator(n){
        this -> Sig = s;
    }

    string getContent() const override {
        return notification -> getContent() + "\n by" + Sig;
    }
};



//observer Design Pattern

class IObserver {
public:
    virtual void update() const = 0;
    virtual ~IObserver() {}
};

class IObservable {
private:
public:
    virtual void addObserver(IObserver* o) = 0;

    virtual void removeObserver(IObserver* o) = 0;

    virtual void notify() = 0;

    virtual ~IObservable() {}
};

class NotificationObservable : public IObservable {
private:
    INotification* currNotification = nullptr;
    vector<IObserver*> list;

public:
    void addObserver(IObserver* o) override {
        list.push_back(o);
    }

    void removeObserver(IObserver* o) override {
        auto it = find(list.begin(), list.end(), o);
        if (it != list.end()) {
            list.erase(it);
        }
    }

    void notify() override {
        for (auto it : list) {
            it -> update();
        }
    }

    void setNotification(INotification* n) {
        this -> currNotification = n;
        notify();
    }

    INotification* getNotification() {
        return currNotification;
    }

    string getNotificationContent() {
        return currNotification -> getContent();
    }
};

class Logger : public IObserver {
private:
    NotificationObservable* n;

public: 
    void update() const override {
        cout<<"Logging new notification "<<n -> getNotificationContent()<<endl;
    }

    Logger(NotificationObservable* n) {
        this -> n = n;
    }
};


//strategy desing pattern


class INotificationStrategy {
public:
    virtual void sendNotification(string content) const = 0;

    virtual ~INotificationStrategy() {}
};

class NotificationEngine : public IObserver {
private:
    NotificationObservable* n;
    vector<INotificationStrategy*> types;

public:

    void update() const override {
        for (auto it : types) {
            it->sendNotification(n->getNotificationContent());
        }
    }

    NotificationEngine(NotificationObservable* n) {
        this -> n = n;
    }

    void addNotificationStrategy(INotificationStrategy* e) {
        types.push_back(e);
    }
};


class EmailStrategy : public INotificationStrategy {
private:
    string email;
public:
    EmailStrategy(string e) {
        email = e;
    }

    void sendNotification(string content) const override {
        cout<<"sending notification("<<content<<") on "<<email<<endl;
    }
};

class SMSStrategy : public INotificationStrategy {
private:
    string mobNo;
public:
    SMSStrategy(string m) {
        mobNo = m;
    }

    void sendNotification(string content) const override {
        cout<<"sending notification("<<content<<") on "<<mobNo<<endl;
    }
};

class PopUpStrategy : public INotificationStrategy {
public:

    void sendNotification(string content) const override {
        cout<<"sending Pop up ("<<content<<")"<<endl;
    }
};

class NotificationService {
private:
    vector<INotification*> n;
    NotificationObservable* obs;
    static NotificationService* instance;

    NotificationService() {
        obs = new NotificationObservable();
    }

public:
    static NotificationService* getInstance() {
        if (instance == nullptr) {
            instance = new NotificationService();
        }

        return instance;
    }

     void sendNotification(INotification* notification) {
        n.push_back(notification);
        obs->setNotification(notification);
    }

    NotificationObservable* getObservable() {
        return obs;
    }

    ~NotificationService() {
        delete obs;
    }
};

NotificationService* NotificationService::instance = nullptr;

int main() {
    NotificationService* notify = NotificationService::getInstance();

    NotificationObservable* obs = notify -> getObservable();

    Logger* logger = new Logger(obs);

    // Create NotificationEngine observers.
    NotificationEngine* notificationEngine = new NotificationEngine(obs);

    notificationEngine->addNotificationStrategy(new EmailStrategy("random.person@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("+91 9876543210"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

    // Attach these observers.
    obs->addObserver(logger);
    obs->addObserver(notificationEngine);

    // Create a notification with decorators.
    INotification* notification = new SimpleNotification("Your order has been shipped!");
    notification = new TimeStampDecorator(notification);
    notification = new SignatureDecorator(notification, " Pranav Gambhire");
    
    notify->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}