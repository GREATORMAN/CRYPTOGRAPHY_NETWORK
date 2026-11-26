#include "../common/deskey.h"
int main(void){int left=0,right=0;
    for(int i=0;i<48;i++){
        if(i<24){if(PC2[i]<=28)left++;}
        else if(PC2[i]>28)right++;
    }
    printf("First 24 subkey bits selected from C (positions 1..28): %d/24\n",left);
    printf("Last 24 subkey bits selected from D (positions 29..56): %d/24\n",right);
    puts("C and D were disjoint 28-bit halves after PC1; rotations stay within each half.");
    return 0;
}
