#include "../common/evp_demo.h"
int main(void){
    unsigned char key[24]="ABCDEFGHIJKLMNOPQRSTUVWX",iv[8]="12345678";
    unsigned char plain[16]="ABCDEFGHABCDEFGH",ecb[32],cbc[32];
    int a=crypt_evp(EVP_des_ede3_ecb(),key,NULL,plain,16,ecb,1);
    int b=crypt_evp(EVP_des_ede3_cbc(),key,iv,plain,16,cbc,1);
    if(a!=16||b!=16){puts("3DES unavailable in crypto library");return 1;}
    printf("3DES ECB block1: ");hexprint(ecb,8);printf("\n3DES ECB block2: ");hexprint(ecb+8,8);
    printf("\n3DES CBC block1: ");hexprint(cbc,8);printf("\n3DES CBC block2: ");hexprint(cbc+8,8);
    printf("\nECB blocks equal? %s\nCBC blocks equal? %s\n",memcmp(ecb,ecb+8,8)?"no":"yes",memcmp(cbc,cbc+8,8)?"no":"yes");
    puts("Security: CBC with unpredictable IV; performance/parallel encryption: ECB (insecure for patterns).");
    puts("For real systems use authenticated AES-GCM, not 3DES or ECB.");return 0;
}
