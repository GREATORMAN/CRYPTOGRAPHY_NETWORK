#include "../common/evp_demo.h"
int main(void){unsigned char key[16]="0123456789ABCDEF",iv[16]={0};
    unsigned char p[48]="BLOCK_ONE_123456BLOCK_TWO_123456BLOCK_THREE_1234";
    unsigned char c[48],bad[48],recv[48],pc[48],changed[48],recover[48];
    if(crypt_evp(EVP_aes_128_cbc(),key,iv,p,48,c,1)!=48)return 1;
    memcpy(bad,c,48);bad[0]^=1;
    if(crypt_evp(EVP_aes_128_cbc(),key,iv,bad,48,recv,0)!=48)return 1;
    printf("Corrupt transmitted C1: P1=%s P2=%s P3=%s\n",
      memcmp(p,recv,16)?"changed":"same",memcmp(p+16,recv+16,16)?"changed":"same",memcmp(p+32,recv+32,16)?"changed":"same");
    memcpy(pc,p,48);pc[0]^=1;
    crypt_evp(EVP_aes_128_cbc(),key,iv,pc,48,changed,1);
    printf("Source bit error in P1: C1=%s C2=%s C3=%s\n",
      memcmp(c,changed,16)?"changed":"same",memcmp(c+16,changed+16,16)?"changed":"same",memcmp(c+32,changed+32,16)?"changed":"same");
    crypt_evp(EVP_aes_128_cbc(),key,iv,changed,48,recover,0);
    printf("Receiver gets altered P1 only? %s\n",!memcmp(pc,recover,48)?"yes":"no");return 0;
}
