#include <stdio.h>
#include <stdint.h>
static uint64_t rot(uint64_t x){return (x<<1)|(x>>63);}
static void theta(uint64_t a[25]){
    uint64_t c[5]={0},d[5];for(int x=0;x<5;x++)for(int y=0;y<5;y++)c[x]^=a[x+5*y];
    for(int x=0;x<5;x++)d[x]=c[(x+4)%5]^rot(c[(x+1)%5]);
    for(int x=0;x<5;x++)for(int y=0;y<5;y++)a[x+5*y]^=d[x];
}
int main(void){uint64_t A[25]={0};
    /* Rate=1024 bits => 16 input lanes; capacity=576 bits => 9 initially zero lanes. */
    for(int i=0;i<16;i++)A[i]=((uint64_t)1<<i) | ((uint64_t)i<<24);
    int remain=9;printf("Capacity lanes initially zero: %d\n",remain);
    for(int round=1;round<=4;round++){
        theta(A);remain=0;for(int i=16;i<25;i++)if(!A[i])remain++;
        printf("After theta %d: %d of 9 tracked capacity lanes still zero\n",round,remain);
    }
    puts("Theta-only illustration. Nonzero input lanes do not guarantee nonzero output for ALL messages (XOR can cancel).");
    return 0;
}
