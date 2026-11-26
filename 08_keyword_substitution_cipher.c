#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){char key[100],abc[27]={0},text[300];int used[26]={0},n=0;
    printf("Keyword: ");scanf("%99s",key);getchar();
    for(int pass=0;pass<2;pass++){
        const char *p=pass?"ABCDEFGHIJKLMNOPQRSTUVWXYZ":key;
        while(*p){int z=toupper((unsigned char)*p++)-'A';if(z>=0&&z<26&&!used[z]++){abc[n++]=(char)(z+'A');}}
    }
    printf("Alphabet: %s\nPlaintext: ",abc);fgets(text,sizeof text,stdin);
    for(int i=0;text[i];i++)if(isalpha((unsigned char)text[i]))text[i]=abc[toupper((unsigned char)text[i])-'A'];
    printf("Encrypted: %s",text);return 0;
}
