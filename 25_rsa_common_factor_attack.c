#include <stdio.h>
long long power(long long a,long long e,long long n){long long r=1;for(;e;e>>=1,a=a*a%n)if(e&1)r=r*a%n;return r;}
long long gcd(long long a,long long b){while(b){long long t=a%b;a=b;b=t;}return a;}
int main(void){long long n=3599,e=31,unknown_plain=59;
    long long cipher=power(unknown_plain,e,n),factor=gcd(cipher,n);
    printf("Ciphertext block: %lld\ngcd(ciphertext,n)=%lld\n",cipher,factor);
    if(factor>1&&factor<n)printf("RSA factor discovered: %lld x %lld\n",factor,n/factor);
    puts("Because gcd(M^e,n)=gcd(M,n), checking ciphertext blocks can reveal a factor.");return 0;
}
