#include "../common/playfair.h"
int main(void){char key[200],s[4096],t[4096];
    printf("Keyword: ");fgets(key,sizeof key,stdin);
    printf("Plaintext: ");fgets(s,sizeof s,stdin);
    build_square(key);prepare_pf(s,t,0);
    printf("Prepared: %s\n",t);run_pf(t,0);printf("Encrypted: %s\n",t);
    run_pf(t,1);printf("Decrypted (with filler X): %s\n",t);
    return 0;
}
