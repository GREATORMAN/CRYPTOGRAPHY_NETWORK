#include <stdio.h>
#include <ctype.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int main(void){char s[300];int a,b,inv=0;
    printf("Text: ");fgets(s,sizeof s,stdin);
    printf("a b: ");if(scanf("%d%d",&a,&b)!=2)return 1;
    a=(a%26+26)%26;b=(b%26+26)%26;
    if(gcd(a,26)!=1){puts("Invalid a: must be coprime with 26.");return 1;}
    for(int x=1;x<26;x++)if(a*x%26==1)inv=x;
    for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){
        int z=toupper((unsigned char)s[i])-'A';s[i]='A'+(a*z+b)%26;
    }
    printf("Encrypted: %s",s);
    for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){
        int z=s[i]-'A';s[i]='A'+(inv*(z-b+26))%26;
    }
    printf("Decrypted: %sAllowed a: 1,3,5,7,9,11,15,17,19,21,23,25. Any b (mod 26).\n",s);
    return 0;
}
