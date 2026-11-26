#include "../common/sdes.h"
int main(void){int key=0x1FD,plaintext[]={1,2,4};int ct[3];
    printf("CTR ciphertext: ");for(int i=0;i<3;i++){
        ct[i]=plaintext[i]^sdes(i,key,0);bits(ct[i],8);putchar(' ');
    }puts("");printf("Decrypted:      ");for(int i=0;i<3;i++){
        bits(ct[i]^sdes(i,key,0),8);putchar(' ');
    }puts("");return 0;
}
