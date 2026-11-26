#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
    char key[100],s[300],out[300];int seen[26]={0};
    printf("26-letter substitution alphabet: ");scanf("%99s",key);
    if(strlen(key)!=26){puts("Key must have 26 letters.");return 1;}
    for(int i=0;i<26;i++){key[i]=(char)toupper((unsigned char)key[i]);
        if(key[i]<'A'||key[i]>'Z'||seen[key[i]-'A']++){puts("Invalid key");return 1;}}
    getchar();printf("Plaintext: ");fgets(s,sizeof s,stdin);
    int i;for(i=0;s[i];i++)out[i]=isalpha((unsigned char)s[i])?key[toupper((unsigned char)s[i])-'A']:s[i];out[i]=0;
    printf("Encrypted: %s",out);
    for(i=0;out[i];i++)if(isalpha((unsigned char)out[i])){
        for(int j=0;j<26;j++)if(key[j]==out[i]){out[i]='A'+j;break;}}
    printf("Decrypted: %s",out);return 0;
}
