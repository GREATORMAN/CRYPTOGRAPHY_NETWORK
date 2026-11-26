#include <stdio.h>
#include <ctype.h>
int main(void){
    char s[300];int k;
    printf("Text: ");fgets(s,sizeof s,stdin);
    printf("Shift (1-25): ");if(scanf("%d",&k)!=1||k<1||k>25)return 1;
    for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){
        int b=isupper((unsigned char)s[i])?'A':'a';s[i]=(char)(b+(s[i]-b+k)%26);
    }
    printf("Encrypted: %s",s);
    for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){
        int b=isupper((unsigned char)s[i])?'A':'a';s[i]=(char)(b+(s[i]-b+26-k)%26);
    }
    printf("Decrypted: %s",s);return 0;
}
