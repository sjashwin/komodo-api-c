#include <curl/curl.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "/usr/local/Cellar/nlohmann-json/3.7.1/include/nlohmann/json.hpp"
#include "komodo.hpp"

using json = nlohmann::json;

class Komodo::Kmd{
    private:
        void getCurl(std::string method, json params);
        long port;
        CURL *curl;
        struct curl_slist *headers;
        std::string host, username, password;
    public:
        std::string str_buffer;
        json response;
        // Komodo Address module: Asset chain API.
        void getAddressBalance(json params);
        void getAddressDeltas(json params);
        void getAddressMemPool(json params);
        void getAddressTxIDs(json params);
        void getAddressUTXOs(json params);
        void getSnapshot(json params);

        // Komodo blockchain module: Asset chain API.
        void coinSupply(json params);
        void getBestBlockHash(json params);
        void getBlochChainInfo(json params);
        void getBlockCount(json params);
        void getBlockHashes(json params);
        void getBlochheader(json params);
        void getChainTips(json params);
        void getChainTXStats(json params);
        void getDifficulty(json params);
        void getLastSegIdDStakes(json params);
        void getMemPoolInfo(json params);
        void getRawMemPool(json params);
        void getSpentInfo(json params);
        void getTxOut(json params);
        void getTxOutProof(json params);
        void getOutSetInfo(json params);
        void kvSearch(json params);
        void kvUpdate(json params);
        void minderIDs(json params);
        void notaries(json params);
        void verifyChain(json params);
        void veriftTXOutProof(json params);

        // Komodo CCLib module: Asset chain API.
        void ccLib(json params);
        void ccLibAddress(json params);
        void ccLibInfo(json params);

        // Komodo control module: Asset chain API.
        void getinfo(json params);
        void help(json params);
        void stop(json params);

        // Komodo cross chain module: Asset Chain API.
        void migrate_createBurnTransactions(json params);
        void migrate_convertToExport(json params);
        void migrate_createImportTransaction(json params);
        void migrate_completeImportTransaction(json params);
        void migrate_checkBurnTransactionSource(json params);
        void migrate_createNotaryApprovalTransaction(json params);
        void selfImport(json params);
        void calc_MoM(json params);
        void MoMoMData(json params);
        void getNotarisationBlockForBlock(json params);
        void scanNotarisationDB(json params);
        void getImports(json params);
        void getWalletBurnTransaction(json params);

        // Komodo Disclosure module: Asset Chain API.
        void z_getPaymentDisclousre(json params);
        void z_validatePaymentDisclosure(json params);

        // Komodo Generate module: Asset Chain API.
        void generate(json params);
        void getGenerate(json params);
        void setGenerate(json params);

        // Komodo Mining module: Asset Chain API.
        void getBlockSubsidy(json params);
        void getBlockTemplate(json params);
        void getLocalSolPS(json params);
        void getMiningInfo(json params);
        void getNetworkHashPS(json params);
        void getNetworkSolPS(json params);
        void prioritiseTransaction(json parmas);
        void submitBlock(json params);

        // Komodo JUMBLR module: Asset chain API.
        void jumblr_deposit(json params);
        void jumblr_pause(json params);
        void jumblr_resume(json params);
        void jumblr_secret(json params);

        // Komodo network module: Asset Chain API.
        void addnode(json params);
        void clearBanned(json params);
        void disconnectNode(json params);
        void getAddedNodeInfo(json params);
        void getConnectionCount(json params);
        void getDeprecationCount(json params);
        void getNetTotals(json params);
        void getNetworkInfo(json params);
        void getPeerInfo(json params);
        void listBanned(json params);
        void ping(json params);
        void setBan(json params);

        // Komodo raw transaction module: Asset Chain API.
        void createRawTransaction(json params);
        void decodeRawTransaction(json params);
        void decodeScript(json params);
        void fundRawTransaction(json params);
        void getRawTransaction(json params);
        void sendRawTransaction(json params);
        void signRawTransaction(json params);

        // Komodo Util module: Asset Chain API.
        void createMultiSig(json params);
        void decodeCCopRet(json params);
        void estimateFee(json params);
        void estimatePriority(json params);
        void invalidateBlock(json Params);
        void reconsiderBlock(json params);
        void txNotarizedConfirmed(json params);
        void validateAddress(json params);
        void verifyMessage(json params);
        void z_validateAddress(json params);

        // Komodo wallet module: Asset Chain API.
        void addMultiSigAddress(json params);
        void backupWallet(json params);
        void dumpPrivKey(json params);
        void encryWallet(json params);
        void getAccount(json params);
        void getAccountAddress(json params);
        void getAddressByAccount(json params);
        void getBalance64(json params);
        void getNewAddress(json params);
        void getRawChainAddress(json params);
        void getReceivedByAccount(json params);
        void getReceivedByAddress(json params);
        void getTransaction(json params);
        void getUncomfirmedBalance(json params);
        void getWalletInfo(json params);
        void importAddress(json params);
        void importPrivKey(json params);
        void importWalelt(json params);
        void keyPoolRefill(json params);
        void listAccounts(json params);
        void listAddressGrouping(json params);
        void listLockUnspent(json params);
        void listReceivedByAddress(json params);
        void listSinceBlock(json params);
        void lockUnspent(json params);
        void move(json params);
        void resendWalletTransaction(json params);
        void sendFrom(json params);
        void sendMany(json params);
        void sendToAddress(json params);
        void setAccount(json params);
        void getPubKey(json params);
        void setTxFee(json params);
        void signMessage(json params);
        void walletLock(json params);
        void walletPassPhrase(json params);
        
    
    // Komodo class constructor.
    Kmd(std::string host, std::string username, std::string password, long port){
        this->curl = curl_easy_init();
        headers = NULL;
        this->host = host;
        this->password = password;
        this->username = username;
        this->port = port;
        this->headers = curl_slist_append(this->headers, "content-type: text/plain");
        curl_easy_setopt(this->curl, CURLOPT_URL, this->host.c_str());
        curl_easy_setopt(this->curl, CURLOPT_DEFAULT_PROTOCOL, "http");
        curl_easy_setopt(this->curl, CURLOPT_POST, 1L);
        curl_easy_setopt(this->curl, CURLOPT_PORT, this->port);
        curl_easy_setopt(this->curl, CURLOPT_USERPWD, this->username+":"+this->password);
        curl_easy_setopt(this->curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &this->str_buffer);
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
};

void Komodo::Kmd::getCurl(std::string method, json params){
        CURLcode errorResponse;
        json data;
        data["jsonrpc"] = "1.0";
        data["id"] = "curltest";
        data["method"] = method;
        data["params"] = params;
        std::string dataString = data.dump();

        // allocating space for the curl data binary and copying the data into location using CURLOPT_COPYPOSTFIELDS
        curl_easy_setopt(this->curl, CURLOPT_POSTFIELDSIZE, dataString.length());
        curl_easy_setopt(this->curl, CURLOPT_COPYPOSTFIELDS, dataString.c_str());
        errorResponse = curl_easy_perform(this->curl);
        if(errorResponse != 0){
                std::cerr << curl_easy_strerror(errorResponse) << std::endl;
                return;
        }else{
            this->response = json::parse(this->str_buffer);
        }
    }