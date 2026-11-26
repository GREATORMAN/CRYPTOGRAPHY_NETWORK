#include <stdio.h>
#include <ctype.h>
long long modpow(long long a,long long e,long long n){long long r=1;for(;e;e>>=1,a=a*a%n)if(e&1)r=r*a%n;return r;}
int main(void){char s[200],recovered[200];long long c[200],dict[26];int n=3599,e=31,i;
    printf("Message: ");fgets(s,sizeof s,stdin);
    for(int x=0;x<26;x++)dict[x]=modpow(x,e,n);
    for(i=0;s[i]&&i<199;i++){
        if(isalpha((unsigned char)s[i])){
            c[i]=modpow(toupper((unsigned char)s[i])-'A',e,n);recovered[i]='?';
            for(int k=0;k<26;k++)if(dict[k]==c[i]){recovered[i]='A'+k;break;}
        }else {c[i]=-1;recovered[i]=s[i];}
    }recovered[i]=0;
    printf("Recovered with 26-entry public-key lookup: %s",recovered);
    return 0;
}
