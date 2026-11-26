#include <stdio.h>
int main(void){
    int K[2][2]={{9,4},{5,7}};
    /* Chosen plaintext BA = vector (1,0), AB = vector (0,1). */
    char ct1[3]={'A'+K[0][0], 'A'+K[1][0],0};
    char ct2[3]={'A'+K[0][1], 'A'+K[1][1],0};
    printf("Chosen BA -> %s\nChosen AB -> %s\n",ct1,ct2);
    printf("Recovered key: [%d %d; %d %d]\n",ct1[0]-'A',ct2[0]-'A',ct1[1]-'A',ct2[1]-'A');
    puts("Two independent plaintext vectors expose both matrix columns.");return 0;
}
