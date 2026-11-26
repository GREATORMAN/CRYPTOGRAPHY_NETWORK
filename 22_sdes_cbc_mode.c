#include "../common/sdes.h"
int main(void){int key=0x1FD,iv=0xAA,plain[]={0x01,0x23};
    int prev=iv,ct[2];
    for(int i=0;i<2;i++){ct[i]=sdes(plain[i]^prev,key,0);prev=ct[i];}
    printf("CBC ciphertext: ");for(int i=0;i<2;i++){bits(ct[i],8);putchar(' ');}puts("");
    prev=iv;printf("Decrypted:     ");for(int i=0;i<2;i++){
        int p=sdes(ct[i],key,1)^prev;bits(p,8);putchar(' ');prev=ct[i];}
    puts("");return 0;
}
