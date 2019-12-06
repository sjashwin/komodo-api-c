## Komodo C/C++ API
![logo](./logo.png)
<p>
Komodo's blockchain technology enables developers to create a fully independent blockchains in s a secure and highly competitive environment.
</p>
<p>
Each independent blockchain built on the komodo framework has a wide range of capabilities, including:
<li>Bitcoin-hash rate supported security</li>
<li>Enterprise-level scalability</li>
<li>Consensus customization</li>
<li>Blockchain clustering</li>
<li>...and more!</li>
</p>
<p>
Because a komodo-based blockchain is independently managed, the developer has complete freedom, so long as the essential connections to the komodo ecosystem chain.
</p>
<p>
This package allows developers to interact with a komodo server. This is a simple package that takes in a method name and corresponding parameters to get a response from the server.
</p>

## Getting Started
<p>
First, download the readliy availble executables from this link [komodo](https://github.com/KomodoPlatform/komodo/releases)
</p>
<p>
Once, you've downloaded extract and run the komodod. Follow the steps in this [link](https://developers.komodoplatform.com/basic-docs/smart-chains/smart-chain-tutorials/smart-chain-api-basics.html#api-tutorials-introduction) to get the port, username and password for the asser chain you want to interact with.
</p>
<p>
Make sure you have g++8 and [lib curl](https://github.com/nlohmann/json). This package uses [nlohmann/json](https://github.com/nlohmann/json)
</p>
<ol>
    <li>
    git clone the repository.
    </li>
    <li>
    Go to the directory: <code>$ cd komodo-api</code>
    </li>
    <li>
    Enter your credentials (host, username, password and port): <code>$ nano main.cpp</code>
    </li>
    <li>
    To compile: <code>$ g++-8 main.cpp -o a.out -lcurl -I{$path to includes}
    </li>
</ol>

### Writing your first code
```C++
#include <curl/curl.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "nlohmann/json.hpp"
#include "komodo.hpp"
#include "base.hpp"
#include "network.hpp"
int main(){
    std::cout << "Getting data from komodo server" << std::endl;
    Komodo::Kmd *obj = new Komodo::Kmd(
        "127.0.0.1", // replace hostname.
        "user", // replace username.
        "pass", // replace password.
        14355L // replace port number.
    );
    json params;
    obj->getCurl("stop", params);
    std::cout << obj->response << std::endl;
    return 0;
}
```

This will produce a json response

```json
{
    "result":"Asset server stopping",
    "error":null,
    "id":"curltest"
}
```