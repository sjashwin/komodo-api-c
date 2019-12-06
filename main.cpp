#include <curl/curl.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "/usr/local/Cellar/nlohmann-json/3.7.1/include/nlohmann/json.hpp"
#include "komodo.hpp"
#include "base.hpp"
#include "network.hpp"
int main(){
    std::cout << "Getting data from komodo server" << std::endl;
    Komodo::Kmd *obj = new Komodo::Kmd(
        "127.0.0.1",
        "user",
        "pass",
        14355L
    );
    json params;
    obj->getCurl("stop", params);
    std::cout << obj->str_buffer << std::endl;
    std::cout << obj->response << std::endl;
    return 0;
}