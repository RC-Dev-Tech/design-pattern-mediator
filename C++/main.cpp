/*
 * Design Pattern - Mediator 中介者模式
 * 
 * 在這個範例中，我們實現了一個簡單的聊天系統，其中Colleague（同事類）之間的通信需要通過Mediator（中介者）進行。
 * Colleague類定義了一個純虛函式Send()和Receive()，用於發送和接收訊息。
 * ConcreteColleague是具體的同事類，實現了Send()和Receive()函式。
 * Mediator類定義了一個向所有同事分發訊息的DistributeMessage()函式，並維護了一個同事類的向量。
 * 
 * 在客戶端，我們創建了一個Mediator對象和兩個ConcreteColleague對象。
 * 將Colleague對象添加到Mediator中。
 * 然後，我們使用Send()函式向同事發送訊息，該訊息將通過中介者進行分發，並由其他同事接收。
 */

#include <iostream>
#include <string>
#include <vector>

// Forward declaration
class Mediator;

// Colleague 同事類
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator) : mediator(mediator) {}

    virtual void Send(const std::string& message) = 0;
    virtual void Receive(const std::string& message) = 0;
};

// ConcreteColleague 具體同事類
class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* mediator) : Colleague(mediator) {}

    void Send(const std::string& message) override {
        std::cout << "Sending message: " << message << std::endl;
        mediator->DistributeMessage(this, message);
    }

    void Receive(const std::string& message) override {
        std::cout << "Received message: " << message << std::endl;
    }
};

// Mediator 中介者
class Mediator {
protected:
    std::vector<Colleague*> colleagues;

public:
    void AddColleague(Colleague* colleague) {
        colleagues.push_back(colleague);
    }

    void DistributeMessage(Colleague* sender, const std::string& message) {
        for (Colleague* colleague : colleagues) {
            if (colleague != sender) {
                colleague->Receive(message);
            }
        }
    }
};

int main() {
    Mediator mediator;

    Colleague* colleague1 = new ConcreteColleague(&mediator);
    Colleague* colleague2 = new ConcreteColleague(&mediator);

    mediator.AddColleague(colleague1);
    mediator.AddColleague(colleague2);

    colleague1->Send("Hello, colleague2!");
    colleague2->Send("Hi, colleague1!");

    delete colleague1;
    delete colleague2;

    return 0;
}

