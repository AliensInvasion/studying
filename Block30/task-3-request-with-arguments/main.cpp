#include <iostream>
#include <sstream>
#include <map>
#include <cpr/cpr.h>

void get(std::map<std::string, std::string> &args)
{
    std::stringstream stream;
    stream << "http://httpbin.org/get";
    if (!args.empty())
    {
        for (auto it = args.begin(); it != args.end(); ++it) {
            char prefix;
            if (it == args.begin()) prefix = '?';
            else prefix = '&';
            stream << prefix << it->first << "=" << it->second;
        }
    }
    cpr::Response getResponse = cpr::Get(cpr::Url(stream.str()));
    std::cout << getResponse.text << std::endl;
}

void post(std::map<std::string, std::string> &args)
{
    std::vector<cpr::Pair> argVec;
    for (auto it = args.begin(); it != args.end(); ++it) {
        argVec.emplace_back((std::string)it->first, (std::string)it->second);
    }
    cpr::Payload payload(argVec.begin(), argVec.end());
    cpr::Response postResponse = cpr::Post(cpr::Url("http://httpbin.org/post"), payload);
    std::cout << postResponse.text << std::endl;
}


int main()
{
    std::map<std::string, std::string> args{};
    std::string request{};

    while(true)
    {
        std::cout << "Enter request:" << std::endl;
        std::cin >> request;
        if (request == "get")
        {
            get(args);
            args.clear();
            continue;
        }
        if (request == "post")
        {
            post(args);
            args.clear();
            continue;
        }
        if (request == "exit") break;

        std::cout << "Enter the value of '" << request << "':" << std::endl;
        std::string value{};
        std::cin >> value;
        args.insert(std::make_pair(request, value));

    }

}