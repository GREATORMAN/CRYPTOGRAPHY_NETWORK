#include "../common/playfair.h"
int main(void){
    const char *rows[]={"MFHIK","UNOPQ","ZVWXY","ELARG","DSTBC"};
    const char *s="Must see you over Cadogan West. Coming at once.";
    char t[4096];
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)pf[i][j]=rows[i][j];
    prepare_pf(s,t,0);printf("Prepared: %s\n",t);run_pf(t,0);
    printf("Encrypted: %s\n",t);run_pf(t,1);printf("Decrypted: %s\n",t);
    return 0;
}
