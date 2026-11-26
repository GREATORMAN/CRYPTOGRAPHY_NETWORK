#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
    const int a=9,b=4,c=5,d=7; /* given matrix; det=43 = 17 mod 26; 17^-1=23 */
    const int ia=5,ib=12,ic=15,id=25; /* inverse of [9 4;5 7] modulo 26 */
    const char *plain="meet me at the usual place at ten rather than eight oclock";
    char s[256],ct[256],out[256];int n=0;
    for(int i=0;plain[i];i++)if(isalpha((unsigned char)plain[i]))s[n++]=(char)toupper((unsigned char)plain[i]);
    if(n%2)s[n++]='X';s[n]=0;
    for(int i=0;i<n;i+=2){int x=s[i]-'A',y=s[i+1]-'A';
        ct[i]='A'+(a*x+b*y)%26;ct[i+1]='A'+(c*x+d*y)%26;
    }ct[n]=0;
    for(int i=0;i<n;i+=2){int x=ct[i]-'A',y=ct[i+1]-'A';
        out[i]='A'+(ia*x+ib*y)%26;out[i+1]='A'+(ic*x+id*y)%26;
    }out[n]=0;
    puts("Matrix: [9 4; 5 7] (column vectors)");
    printf("Plaintext:  %s\nCiphertext: %s\nRecovered:  %s\n",s,ct,out);
    return 0;
}
