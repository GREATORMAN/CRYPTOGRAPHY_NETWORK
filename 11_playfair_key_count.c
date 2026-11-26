#include <stdio.h>
#include <math.h>
int main(void){double v=0;
    for(int i=2;i<=25;i++)v+=log2((double)i);
    printf("All 5x5 arrangements = 25! ~= 2^%.2f\n",v);
    printf("Distinct ciphers after 25 row/column cyclic shifts = 25!/25 ~= 2^%.2f\n",v-log2(25.0));
    return 0;
}
