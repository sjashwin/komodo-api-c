#include "komodo.hpp"

void Komodo::Kmd::getinfo(json params){
    this->getCurl("getinfo", params);
}

void Komodo::Kmd::stop(json params){
    this->getCurl("stop", params);
}