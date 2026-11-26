#include <stdio.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int main(void){
    /* Assume most common ciphertext B means E and second U means T. */
    int count=0;
    for(int a=1;a<26;a++)if(gcd(a,26)==1)for(int b=0;b<26;b++){
        if((a*4+b)%26==1&&(a*19+b)%26==20){
            printf("If E->B and T->U, key a=%d, b=%d\n",a,b);count++;
        }
    }
    if(!count)puts("No affine key fits these guesses.");
    puts("Two frequency ranks alone do not uniquely prove the key.");return 0;
}
