#include <stdio.h>
#include <openssl/des.h>
int main(void){DES_cblock key={0x13,0x34,0x57,0x79,0x9B,0xBC,0xDF,0xF1};
    DES_cblock plain={0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF},cipher,back;
    DES_key_schedule schedule;DES_set_key_unchecked(&key,&schedule);
    DES_ecb_encrypt(&plain,&cipher,&schedule,DES_ENCRYPT);
    DES_ecb_encrypt(&cipher,&back,&schedule,DES_DECRYPT);
    printf("Ciphertext: ");for(int i=0;i<8;i++)printf("%02X",cipher[i]);
    printf("\nRecovered:  ");for(int i=0;i<8;i++)printf("%02X",back[i]);puts("");
    puts("DES is obsolete and must not protect real data.");return 0;
}
