#include <iostream>
#include <vector>
#define CORRECT_NUMBER(str) (str[0] == '+' && str[1] == '7' && str.length() == 12)
#define CALL_NUMBER(number) std::cout << "CALL " << number << std::endl;
#define SEND_SMS(number, message) std::cout << "Send SMS to " << number << "\nEnter the message: " << std::endl; std::cin.ignore(1); std::getline(std::cin, message); std::cout << "---\n" << message << "\n---\nMessage sent."<< std::endl;

class PhoneNumber {

    std::string number;

public:

    std::string getNumber() {
        return number;
    }

    bool putNumber() {
        std::string str;
        std::cout << "Enter the number: " << std::endl;
        std::cin >> str;
        if (CORRECT_NUMBER(str)) {
            number = str;
            return true;
        }
        return false;
    }

};

class Contact {

    std::string name;
    PhoneNumber number;

    friend class Phone;

};

class Phone {

    std::vector<Contact> contacts;
    std::string temp;

public:

    void call() {
        std::cout << "Enter name or number to CALL: " << std::endl;
        std::cin >> temp;
        if (CORRECT_NUMBER(temp)) {
            CALL_NUMBER(temp)
        } else {
            for (auto &i : contacts) {
                if (i.name == temp) {
                    CALL_NUMBER(i.number.getNumber())
                }
            }
        }
    };

    void sms() {
        std::cout << "Enter name or number to send SMS: " << std::endl;
        std::cin >> temp;
        if (CORRECT_NUMBER(temp)) {
            SEND_SMS(temp, temp)
        } else {
            for (auto &i : contacts) {
                if (i.name == temp) {
                    SEND_SMS(i.number.getNumber(), temp)
                }
            }
        }
    };

    void add() {
        Contact contact;
        std::cout << "Enter the name: " << std::endl;
        std::cin >> contact.name;
        while (!contact.number.putNumber()) {
            std::cout << "Not correct number! Enter again:" << std::endl;
        }
        contacts.push_back(contact);
    }
};

int main() {

    std::string request;
    Phone *phone = new Phone();

    do {
        std::cout << "Enter request: " << std::endl;
        std::cin >> request;

        if (request == "add") {
            phone->add();
        }
        if (request == "call") {
            phone->call();
        }
        if (request == "sms") {
            phone->sms();
        }

    } while (request != "exit");

    delete phone;

}
