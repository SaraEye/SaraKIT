#ifndef _CJSONPOST_HPP_
#define _CJSONPOST_HPP_

#include <curl/curl.h>
#include <string>


class CJSONPost{
public:
    CJSONPost(std::string url);
    ~CJSONPost();
    CJSONPost();
    void init();
    void setUrl(std::string url);
    std::string send(std::string jsonstr);
    static size_t write_data(void *ptr, size_t size, size_t nmemb, std::string *streamData);
private:
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL; // init to NULL is important
    std::string url;
};

#endif
