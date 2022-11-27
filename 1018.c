#include <stdio.h>

void reverse();


int main() {
    reverse();
    return 0;
}

/* use recursion (LIFO stack) to get reverse */
void reverse(){
    /* use getchar() to get one char only */
    char bufChar = getchar();
    /* recursion base case, EOF is OJ input end symbol */
    if(bufChar != EOF){
        reverse(bufChar);
    }else{
        /* recursive case */
        return;
    }
    /* print each reversed char */
    printf("%c", bufChar);
}

/*
 * Student ID: 201600830
 * Student Name: Yunfan Shi
 * Email: sgyshi31@liverpool.ac.uk
 *
 * User: sgyshi31
 *
 * Problem ID: 1018
 * RunID: 43986
 * Result: Accepted
 */