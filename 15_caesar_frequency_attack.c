#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
static double eng[]={8.17,1.49,2.78,4.25,12.70,2.23,2.02,6.09,6.97,0.15,0.77,4.03,2.41,6.75,7.51,1.93,0.10,5.99,6.33,9.06,2.76,0.98,2.36,0.15,1.97,0.07};
int main(void){char s[1000],out[1000];int top,count=0;double score[26];int used[26]={0};
    printf("Ciphertext: ");fgets(s,sizeof s,stdin);
    printf("Top how many (1-26): ");scanf("%d",&top);
    if(top<1)top=1;if(top>26)top=26;
    for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))count++;
    if(!count){puts("Enter alphabetic ciphertext.");return 1;}
    for(int k=0;k<26;k++){int f[26]={0};
        for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i])){
            int x=toupper((unsigned char)s[i])-'A';f[(x-k+26)%26]++;}
        score[k]=0;for(int i=0;i<26;i++){
            double e=count*eng[i]/100.,d=f[i]-e;score[k]+=d*d/e;
        }
    }
    for(int rank=0;rank<top;rank++){
        int best=-1;for(int k=0;k<26;k++)if(!used[k]&&(best<0||score[k]<score[best]))best=k;
        used[best]=1;for(int i=0;s[i];i++)out[i]=isalpha((unsigned char)s[i])?
           (char)('A'+(toupper((unsigned char)s[i])-'A'-best+26)%26):s[i];
        out[strlen(s)]=0;printf("%2d. shift=%2d score=%7.2f %s",rank+1,best,score[best],out);
    }return 0;
}
