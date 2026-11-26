#include <stdio.h>
long long powmod(long long a,long long e,long long p){long long r=1;for(;e;e>>=1,a=a*a%p)if(e&1)r=r*a%p;return r;}
int inverse(int a,int n){for(int x=1;x<n;x++)if(a*x%n==1)return x;return -1;}
int main(void){int p=23,q=11,g=4,x=3,h=5,ks[]={3,7};
    for(int i=0;i<2;i++){int k=ks[i],r=(int)(powmod(g,k,p)%q);
        int s=inverse(k,q)*(h+x*r)%q;
        printf("DSA nonce k=%d -> signature (r,s)=(%d,%d)\n",k,r,s);
    }
    long long sig=powmod(5,3031,3599);
    printf("Textbook RSA signing twice (same hash): %lld and %lld\n",sig,sig);
    puts("DSA random/non-repeated k causes varied signatures; nonce reuse leaks the key.");
    puts("Textbook RSA is deterministic; modern RSA-PSS uses randomized padding.");return 0;
}
