#include "CJSONPost.hpp"

CJSONPost::CJSONPost(std::string url) : url(url)
{
    init();
}
CJSONPost::CJSONPost()
{
    url = "";
    init();
}
CJSONPost::~CJSONPost() {}
void CJSONPost::init()
{
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charsets: utf-8");

}
void CJSONPost::setUrl(std::string url)
{
    this->url = url;
}
std::string CJSONPost::send(std::string jsonstr)
{
    curl = curl_easy_init();
    std::string streamdata = "";
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonstr.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &streamdata);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }
    return streamdata;
}
size_t CJSONPost::write_data(void *ptr, size_t size, size_t nmemb, std::string *streamData)
{

    size_t newLength = size * nmemb;
    try
    {
        streamData->append((char *)ptr, newLength);
    }
    catch (std::bad_alloc &e)
    {
        // handle memory problem
        return 0;
    }

    return newLength;
}