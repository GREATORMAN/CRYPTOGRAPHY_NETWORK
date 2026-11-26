#include <stdio.h>
#include <string.h>
int main(void){
    char p[]="SENDMOREMONEY",target[]="CASHNOTNEEDED",c[20],fake[20];
    int key[]={9,0,1,7,23,15,21,14,11,11,2,8,9};
    int n=(int)strlen(p);for(int i=0;i<n;i++){
        c[i]='A'+(p[i]-'A'+key[i])%26;
        fake[i]='A'+(c[i]-target[i]+26)%26;
    }c[n]=fake[n]=0;
    printf("Ciphertext: %s\nAlternate key for %s: ",c,target);
    for(int i=0;i<n;i++)printf("%d%s",fake[i]-'A',i==n-1?"\n":" ");
    puts("One-time pad ambiguity: a different key can yield a different plaintext.");return 0;
}
