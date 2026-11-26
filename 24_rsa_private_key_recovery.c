#include <stdio.h>
long long egcd(long long a,long long b,long long *x,long long *y){
    if(!b){*x=1;*y=0;return a;}
    long long x1,y1,g=egcd(b,a%b,&x1,&y1);*x=y1;*y=x1-(a/b)*y1;return g;
}
int main(void){int n=3599,e=31,p=0,q=0;
    for(int i=2;i*i<=n;i++)if(n%i==0){p=i;q=n/i;break;}
    if(!p){puts("No factors found");return 1;}
    int phi=(p-1)*(q-1);long long x,y;
    if(egcd(e,phi,&x,&y)!=1)return 1;
    int d=(int)((x%phi+phi)%phi);
    printf("p=%d q=%d phi(n)=%d d=%d\n",p,q,phi,d);return 0;
}
