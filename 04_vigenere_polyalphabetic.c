#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){char text[400],key[100],enc[400];int j=0;
    printf("Plaintext: ");fgets(text,sizeof text,stdin);
    printf("Key: ");scanf("%99s",key);int len=(int)strlen(key);
    if(!len)return 1;for(int i=0;i<len;i++)if(!isalpha((unsigned char)key[i]))return 1;
    int i;for(i=0;text[i];i++){
        int c=toupper((unsigned char)text[i]);
        if(c>='A'&&c<='Z')enc[i]='A'+(c-'A'+toupper((unsigned char)key[j++%len])-'A')%26;
        else enc[i]=text[i];
    }enc[i]=0;printf("Encrypted: %s",enc);
    j=0;for(i=0;enc[i];i++)if(isalpha((unsigned char)enc[i])){
        enc[i]='A'+(enc[i]-'A'-(toupper((unsigned char)key[j++%len])-'A')+26)%26;
    }printf("Decrypted: %s",enc);return 0;
}
