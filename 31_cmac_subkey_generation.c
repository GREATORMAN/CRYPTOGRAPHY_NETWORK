#include "../common/evp_demo.h"
static void dbl(const unsigned char *a,unsigned char *b,int n,unsigned char rb){
    int carry=(a[0]>>7)&1;
    for(int i=0;i<n;i++)b[i]=(unsigned char)((a[i]<<1)|(i+1<n?a[i+1]>>7:0));
    if(carry)b[n-1]^=rb;
}
int main(void){unsigned char key[16]={0},z[16]={0},L[16],k1[16],k2[16];
    if(crypt_evp(EVP_aes_128_ecb(),key,NULL,z,16,L,1)!=16)return 1;
    dbl(L,k1,16,0x87);dbl(k1,k2,16,0x87);
    puts("CMAC Rb for 64-bit blocks: 0x1B");
    puts("CMAC Rb for 128-bit blocks: 0x87");
    printf("AES-CMAC L: ");hexprint(L,16);
    printf("\nK1:         ");hexprint(k1,16);
    printf("\nK2:         ");hexprint(k2,16);puts("");
    return 0;
}
