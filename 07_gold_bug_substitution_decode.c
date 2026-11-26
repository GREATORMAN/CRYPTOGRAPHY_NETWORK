#include <stdio.h>
#include <string.h>
int main(void){
    /* Edgar Allan Poe's Gold-Bug, substitution symbols in UTF-8. */
    const char *sym[]={"5","3","‡","†","0",")","6","*",";","4","8","(","9","2",":","?","¶","1", "]",".","—"};
    const char *letter[]={"a","g","o","d","l","s","i","n","t","h","e","r","m","b","y","u","v","f","w","p","c"};
    const char *cipher=
      "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
      "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*"
      ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81"
      "(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    printf("Decoded (word spaces omitted by cipher):\n");
    while(*cipher){int found=0;for(int i=0;i<21;i++){
        size_t z=strlen(sym[i]);if(strncmp(cipher,sym[i],z)==0){fputs(letter[i],stdout);cipher+=z;found=1;break;}}
        if(!found){putchar('?');cipher++;}
    }
    puts("\n\nInterpretation: A good glass in the bishop's hostel in the devil's seat ...");
    puts("Note: the question's copied ciphertext contains some changed symbols.");return 0;
}
