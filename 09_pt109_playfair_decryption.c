#include "../common/playfair.h"
int main(void){
    const char *key="ROYAL NEW ZEALAND NAVY";char t[4096];
    const char *cipher="KXJEY UREBE ZWEHE WRYTU HEYFS "
      "KREHE GOYFI WTTTU OLKSY CAJPO "
      "BOTEI ZONTX BYBNT GONEY CUZWR "
      "GDSON SXBOU YWRHE BAAHY USEDQ";
    build_square(key);prepare_pf(cipher,t,1);run_pf(t,1);
    printf("Historical keyword: %s\n",key);
    printf("PT-109 decoded without word spaces:\n%s\n",t);
    puts("The provided BYBNT section appears to be a transcription error: sources show BYBWT.");
    return 0;
}
