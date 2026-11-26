#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
/* Educational heuristic: English unigrams + common digrams/trigrams, randomized search. */
static const char *grams[]={"THE","AND","ING","ION","ENT","HER","THA","ERE","HAT","ATE","ALL","ETH","HES","VER","HIS","OFT","ITH","FTH","STH","OTH","FOR","NOT","YOU","WIT","TH","HE","IN","ER","AN","RE","ON","AT","EN","ND","TI","ES","OR","TE","OF","ED","IS","IT","AL","AR","ST","TO","NT","NG","SE","HA","AS","OU","IO","LE","VE","CO","ME","DE","HI","RI","RO","IC","NE","EA","RA","CE","LI","CH","LL","BE","MA","SI","OM","UR"};
static const double freq[]={8.17,1.49,2.78,4.25,12.7,2.23,2.02,6.09,6.97,0.15,0.77,4.03,2.41,6.75,7.51,1.93,0.10,5.99,6.33,9.06,2.76,0.98,2.36,0.15,1.97,0.07};
static int seq[4000],n;
static double score(const char *key){int cnt[26]={0};double result=0;
    for(int i=0;i<n;i++)cnt[key[seq[i]]-'A']++;
    for(int i=0;i<26;i++){double e=n*freq[i]/100.;result-=0.03*(cnt[i]-e)*(cnt[i]-e)/(e+1);}
    for(int i=0;i<n;i++)for(int g=0;g<(int)(sizeof grams/sizeof *grams);g++){
        int L=(int)strlen(grams[g]);if(i+L>n)continue;int j=0;
        while(j<L&&key[seq[i+j]]==grams[g][j])j++;
        if(j==L)result+=(L==3?6.0:2.5);
    }return result;
}
int main(void){char s[4000],bestkey[27]={0};int top;
    printf("Ciphertext (prefer 100+ letters): ");fgets(s,sizeof s,stdin);
    printf("Number of candidates (1-10): ");if(scanf("%d",&top)!=1)return 1;
    if(top<1)top=1;if(top>10)top=10;
    for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))seq[n++]=toupper((unsigned char)s[i])-'A';
    if(!n){puts("No letters.");return 1;}
    srand(2026);double highs[10];char keys[10][27];for(int i=0;i<10;i++)highs[i]=-1e100;
    for(int restart=0;restart<top*4;restart++){
        char key[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=25;i>0;i--){int j=rand()%(i+1);char t=key[i];key[i]=key[j];key[j]=t;}
        double cur=score(key);
        for(int it=0;it<1500;it++){
            int a=rand()%26,b=rand()%26;char t=key[a];key[a]=key[b];key[b]=t;
            double next=score(key),temp=2.0*(1.0-(it%1000)/1100.0);
            double chance=exp(fmax(-30.0,fmin(0.0,(next-cur)/temp)));
            if(next>=cur||(rand()/(double)RAND_MAX)<chance)cur=next;
            else {t=key[a];key[a]=key[b];key[b]=t;}
        }
        int slot=-1;for(int i=0;i<top;i++)if(cur>highs[i]){slot=i;break;}
        if(slot>=0){for(int i=top-1;i>slot;i--){highs[i]=highs[i-1];strcpy(keys[i],keys[i-1]);}
            highs[slot]=cur;strcpy(keys[slot],key);}
    }
    for(int k=0;k<top;k++){
        printf("\n%d. score=%.2f: ",k+1,highs[k]);
        for(int i=0;s[i];i++)putchar(isalpha((unsigned char)s[i])?keys[k][toupper((unsigned char)s[i])-'A']:s[i]);
    }puts("\nHeuristic candidates; short messages may not decrypt correctly.");return 0;
}
