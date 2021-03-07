#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char **argv) {
    CURL *curl = curl_easy_init();
    if(!curl) {
      fprintf(stderr, "init failed\n");
      return EXIT_FAILURE;
    }

    FILE *fil = fopen("packages.csv", "rb");
    char jsonObj[255];// = "malloc(sizeof(char) * 255)";
    if(fil != NULL) {
       char buffer[255];

       //fread(buffer, sizeof(fil), 1, fil), !feof(fil) -- first tes for while
       while(fgets(buffer, sizeof buffer, fil) != NULL) {
         //fputs ( buffer, stdout );
         strcat(jsonObj, "{\"name\": \"");
         strcat(jsonObj, strtok(buffer, ","));
         strcat(jsonObj, "\", \"address\": \"");
         strcat(jsonObj, strtok(NULL, ","));
         strcat(jsonObj, "\", \"mail\": \"");
         strcat(jsonObj, strtok(NULL, ","));
         strcat(jsonObj, "\", \"volume\": \"");
         strcat(jsonObj, strtok(NULL, ","));
         strcat(jsonObj, "\", \"price\": \"");
         strcat(jsonObj, strtok(NULL, ",\n"));
         strcat(jsonObj, "\"}");
       }
       fclose(fil);
     } else {
       perror("packages.csv");
     }
     printf("%s\n", jsonObj);
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
