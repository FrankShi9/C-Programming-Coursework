#include <stdio.h>

void cntCharInStr();


int main() {

    cntCharInStr();
    return 0;
}

void cntCharInStr(){
    /* use getchar() to get one char only including EOF */
    char bufChar = getchar();
    int cntChar=0, cntDigit=0, cntSpace=0, cntOther=0;
    while(bufChar != EOF){
        /* use ASCII value of boundary chars to compare */
        if((bufChar>='A' && bufChar<='Z')||(bufChar>='a' && bufChar<='z')){
            cntChar++;
        }else if(bufChar>='0' && bufChar<='9'){
            cntDigit++;
        }else if(bufChar == ' '){
            cntSpace++;
        }else{
            cntOther++;
        }
        /* get next char for loop condition check */
        bufChar = getchar();
    }
    printf("%d %d %d %d\n", cntChar, cntDigit, cntSpace, cntOther);
}


/*
 * Result: Accepted
 */
