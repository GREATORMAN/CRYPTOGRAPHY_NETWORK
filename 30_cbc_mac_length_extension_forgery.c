#include "../common/evp_demo.h"
int main(void){unsigned char key[16]="0123456789ABCDEF",zero[16]={0};
    unsigned char X[16]="HELLO_FROM_ALICE",T[16],b2[16],mac2[16],t[16];
    if(crypt_evp(EVP_aes_128_ecb(),key,NULL,X,16,T,1)!=16)return 1;
    for(int i=0;i<16;i++)b2[i]=X[i]^T[i];
    for(int i=0;i<16;i++)t[i]=b2[i]^T[i]; /* t = X */
    crypt_evp(EVP_aes_128_ecb(),key,NULL,t,16,mac2,1);
    printf("MAC(K,X):             ");hexprint(T,16);
    printf("\nMAC(K,X || (X xor T)): ");hexprint(mac2,16);
    printf("\nSame tag? %s\n",memcmp(T,mac2,16)==0?"yes":"no");
    puts("Raw CBC-MAC is not safe across variable message lengths. Use CMAC.");return 0;
}
