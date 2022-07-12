#include <iostream>
#include <cpr/cpr.h>

int main()
{

    std::string request{};
    do {
        std::cin >> request;
        if (request == "get")
        {
            cpr::Response response = cpr::Get(cpr::Url("http://httpbin.org/get"));
            std::cout << response.text << std::endl;
        }
        if (request == "post")
        {
            cpr::Response response = cpr::Post(cpr::Url("http://httpbin.org/post"));
            std::cout << response.text << std::endl;
        }
        if (request == "put")
        {
            cpr::Response response = cpr::Put(cpr::Url("http://httpbin.org/put"));
            std::cout << response.text << std::endl;
        }
        if (request == "delete")
        {
            cpr::Response response = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
            std::cout << response.text << std::endl;
        }
        if (request == "patch")
        {
            cpr::Response response = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
            std::cout << response.text << std::endl;
        }
    } while (request != "exit");

}