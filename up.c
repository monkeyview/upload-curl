#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(int argc, char **argv) {
    CURL *curl = curl_easy_init();
    if(!curl) {
      fprintf(stderr, "init failed\n");
      return EXIT_FAILURE;
    }
    char* jsonObj = "{ \"name\" : \"Pedro\" , \"age\" : \"22\" }";

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8");

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/get.php");
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonObj);

    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
      fprintf(stderr, "upload failed %s\n", curl_easy_strerror(result));
    }
    curl_easy_cleanup(curl);
    return EXIT_SUCCESS;
}
