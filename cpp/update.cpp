#include "../src/include/curl/curl/curl.h"
#include <string>
#include <windows.h>
#include <iostream>

static size_t curlWriter(char *buffer, size_t size, size_t nmemb, std::string *html){
  int result = 0;

  if(buffer != NULL){
    html->append(buffer, size*nmemb);
    result = size*nmemb;
  }
  return result;
}

void update(std::string currentVer){
    CURL *curl;
    std::string inputData;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl=curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, true);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2); 
    curl_easy_setopt(curl, CURLOPT_CAINFO,"src/bin/cacert.pem");
    curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/vSEK1RO/AutoDofai");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.0.3705; .NET CLR 1.1.4322)");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,&inputData);
    res=curl_easy_perform(curl);
    if (res != CURLE_OK)fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    inputData.erase(0,inputData.find("Download: <a href="));    
    inputData.erase(0,inputData.find("<strong>")+8);    
    if(currentVer!=inputData.substr(0,inputData.find("</strong>"))){
        MessageBox(GetActiveWindow(), "Update available", "Notification", MB_OK);
        ShellExecute(0,"open","https://github.com/vSEK1RO/AutoDofai/releases/download/v0.6/AutoDofai_v0.6.rar",NULL,NULL,SW_SHOWDEFAULT);
        exit(1);
    }
}
