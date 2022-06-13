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

    void putNumber(std::string &str) {
        number = str;
    }

};

class Contact {

    std::string name;
    PhoneNumber number;

public:

    std::string getName() {
        return name;
    }

    std::string getNumber() {
        return number.getNumber();
    }

    bool newContact(std::string &str1, std::string &str2) {
        name = str1;
        number.putNumber(str2);
    }

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
                if (i.getName() == temp) {
                    CALL_NUMBER(i.getNumber())
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
                if (i.getName() == temp) {
                    SEND_SMS(i.getNumber(), temp)
                }
            }
        }
    };

    bool add() {
        Contact contact;
        std::string str1;
        std::string str2;
        std::cout << "Enter the name: " << std::endl;
        std::cin >> str1;
        std::cout << "Enter the number: " << std::endl;
        std::cin >> str2;
        if (CORRECT_NUMBER(str2)) {
            contact.newContact(str1, str2);
            contacts.push_back(contact);
            return true;
        }
        return false;
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
