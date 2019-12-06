#include "komodo.hpp"

void Komodo::Kmd::getinfo(std::vector<std::string> params){
    this->getCurl("getinfo", params);
}

void Komodo::Kmd::stop(std::vector<std::string> params){
    this->getCurl("stop", params);
}