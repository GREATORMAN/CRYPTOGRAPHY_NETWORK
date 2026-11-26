#include <stdio.h>
#include <string.h>
int main(void){char s[100];unsigned char b[120]={0};
    printf("Message: ");fgets(s,sizeof s,stdin);int n=(int)strcspn(s,"\n");
    int pad=8-(n%8);memcpy(b,s,n);b[n]=0x80; /* 1-bit then zero bits */
    printf("Length=%d bytes, padded=%d bytes (%d bytes added)\n",n,n+pad,pad);
    printf("Last block: ");for(int i=n+pad-8;i<n+pad;i++)printf("%02X ",b[i]);puts("");
    puts("Even full blocks need padding to distinguish data endings from padding.");return 0;
}
