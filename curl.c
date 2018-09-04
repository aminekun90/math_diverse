#define CURL_STATICLIB
#include <stdio.h>
#include <curl/curl.h>
#include <math.h>
#include <curl/easy.h>
#include <string.h>
#include <windows.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}
int progress_func(void* ptr, double TotalToDownload, double NowDownloaded, 
                    double TotalToUpload, double NowUploaded)
{
    // how wide you want the progress meter to be
    int totaldotz=40;
    double fractiondownloaded = NowDownloaded / TotalToDownload;
    // part of the progressmeter that's already "full"
    int dotz = round(fractiondownloaded * totaldotz);

    // create the "meter"
    int ii=0;
    printf("%3.0f%% [",fractiondownloaded*100);
    // part  that's full already
    for ( ; ii < dotz;ii++) {
        printf("=");
    }
    // remaining part (spaces)
    for ( ; ii < totaldotz;ii++) {
        printf(" ");
    }
    // and back to line begin - do not forget the fflush to avoid output buffering problems!
    printf("]\r");
    fflush(stdout);
    // if you don't return 0, the transfer will be aborted - see the documentation
    return 0; 
}

int main(void) {
	printf("Telechargement en cours...");
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = "http://eheio.ma/mathdiv/MathDiverse-v1.05b.exe";
    curl = curl_easy_init();
    
    if (curl) {
        fp = fopen("MathDiverse-v1.05b.exe","wb");
        
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);  // already there
// Internal CURL progressmeter must be disabled if we provide our own callback
curl_easy_setopt(curl, CURLOPT_NOPROGRESS, FALSE);
// Install the callback function
curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_func);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
printf("Fin du telechargement");
system("start MathDiverse-v1.05b.exe");
}
