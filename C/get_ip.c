#include <stdio.h>
#include <curl/curl.h>
 
int main(){
        CURL *curl;
        CURLcode res;
        printf("\n\n");
        printf("Recupero dell\'indirizzo IP in corso...\n\n");
        curl = curl_easy_init();
        if (curl){
                curl_easy_setopt(curl, CURLOPT_URL, "kinginfet.net/getip.php");
                printf("IP: ");
                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);
        } else {
                printf("ERRORE nel recupero dell\'indirizzo IP!");
        }
        printf("\n\n");
        return 0;
}

