#include <iostream>
#include <cpr/cpr.h>

int main()
{
    cpr::Response response = cpr::Get(cpr::Url("http://httpbin.org/html"),
                                      cpr::Header({{"accept", "text/html"}}));

    std::string html = response.text;
    std::size_t h1Begin = html.find("<h1>");
    std::size_t h1End = html.find("</h1>", h1Begin);

    std::string h1 = html.substr(h1Begin+4, h1End-h1Begin-4);

    std::cout << h1 << std::endl;
}