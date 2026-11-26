#include <stdio.h>
int main(void){long long n=3599,e=31,d=3031;
    long long t=e*d-1;
    printf("Leaked (n,e,d) => e*d-1 = %lld, divisible by phi(n).\n",t);
    for(long long p=2;p*p<=n;p++)if(n%p==0){
        printf("For toy n, recover factors p=%lld q=%lld.\n",p,n/p);break;}
    puts("Changing only (e,d) with the same n is NOT safe; replace n and generate a new keypair.");
    puts("Real RSA private-key leakage permits efficient modulus factor recovery.");return 0;
}
