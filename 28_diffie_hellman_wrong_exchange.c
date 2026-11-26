#include <stdio.h>
long long modpow(long long x,long long a,long long p){long long r=1;for(;a;a>>=1,x=x*x%p)if(a&1)r=r*x%p;return r;}
int main(void){long long q=23,a=3,alice=5,bob=9;
    long long A=modpow(alice,a,q),B=modpow(bob,a,q);
    long long public_key=A*B%q;
    printf("Alice sends x^a mod q=%lld, Bob sends y^a mod q=%lld\n",A,B);
    printf("Their proposed (xy)^a mod q = %lld\n",public_key);
    printf("Eve computes A*B mod q = %lld, without either secret.\n",public_key);
    puts("Replacing g^x with x^a breaks Diffie-Hellman key secrecy.");return 0;
}
