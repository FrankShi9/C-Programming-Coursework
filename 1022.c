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
 * Student ID: 201600830
 * Student Name: Yunfan Shi
 * Email: sgyshi31@liverpool.ac.uk
 *
 * User: sgyshi31
 *
 * Problem ID: 1022
 * RunID: 43985
 * Result: Accepted
 */
