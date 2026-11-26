#include "../common/deskey.h"
int main(void){uint64_t k[16];deskeys(0x133457799BBCDFF1ULL,k);
    puts("DES decryption uses subkeys in order K16 ... K1:");
    for(int i=15;i>=0;i--)printf("K%02d = %012llX\n",i+1,(unsigned long long)k[i]);
    puts("For reverse generation: start at C16,D16 (=C0,D0), PC2; then right-rotate by round shifts.");
    return 0;
}
