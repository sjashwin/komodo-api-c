#include <curl/curl.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "/usr/local/Cellar/nlohmann-json/3.7.1/include/nlohmann/json.hpp"
#include "komodo.hpp"

using json = nlohmann::json;

class Komodo::Kmd{
    public:
        std::string str_buffer;
        json response;
        void getinfo(std::vector<std::string>);
        void stop(std::vector<std::string>);
        CURL *curl;
        struct curl_slist *headers;
        std::string host, username, password;
        long port;
    Kmd(std::string host, std::string username, std::string password, long port){
        curl = curl_easy_init();
        headers = NULL;
        this->host = host;
        this->password = password;
        this->username = username;
        this->port = port;
    }
    static std::size_t write_callback(char *in, size_t size, size_t nmemb, std::string *out){ 
        std::size_t total_size = size * nmemb;
        if(total_size){
            out->append(in, total_size);
            return total_size;
        }
        std::cout << "from callback" << out << std::endl;
        return 0;
    }

    void getCurl(std::string method, std::vector<std::string> params){
        CURLcode errorResponse;
        json data;
        data["jsonrpc"] = "1.0";
        data["id"] = "curltest";
        data["method"] = method;
        data["params"] = params;
        std::string dataString = data.dump();
        headers = curl_slist_append(headers, "content-type: text/plain");
        curl_easy_setopt(curl, CURLOPT_URL, "127.0.0.1");
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_PORT, 14355L);
        curl_easy_setopt(curl, CURLOPT_USERPWD, "user:pass");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->str_buffer);
        
        // allocating space for the curl data binary and copying the data into location using CURLOPT_COPYPOSTFIELDS
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, dataString.length());
        curl_easy_setopt(curl, CURLOPT_COPYPOSTFIELDS, dataString.c_str());
        errorResponse = curl_easy_perform(curl);
        if(errorResponse != 0){
                std::cerr << curl_easy_strerror(errorResponse) << std::endl;
                return;
        }else{
            this->response = json::parse(this->str_buffer);
        }
    }
};