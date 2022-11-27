#include <stdio.h>
#include <math.h>
#define MAX_LEN 100 /* max line input length */


/* intentional global array */
char input[MAX_LEN];
int number[MAX_LEN];


void compress(){
    char nextChar = ' ';
    nextChar = getchar();

    if(nextChar == '\n') {
        /* get next line */
        fgets(input, MAX_LEN, stdin);

        /* line by line loop until EOF */
        while (1) {
            /* char by char loop for each line input */
            for (int i=0; i<MAX_LEN; ) {
                /* see '\n': print and jump to next line */
                if (input[i] == '\n') {
                    printf("\n");
                    break;
                }

                /* counter for how many repeats for a char */
                int cnt = 0;

                if (input[i] == input[i + 1]) {
                    /* repetition found */
                    while(input[i] == input[i + 1]){
                        cnt++;
                        i++;
                    }
                    /* add offset 1 to get actual cnt */
                    cnt += 1;
                    /* format output below */
                    printf("%c%c%d*", input[i], input[i], cnt);
                    i++;
                }else{
                    /* no repetition */
                    printf("%c", input[i]);
                    i++;
                }
            }
            /* get next line */
            char *ret = fgets(input, MAX_LEN, stdin);
            /* check EOF */
            if(ret==NULL) return;
        }
    }
}


void expand(){
    char nextChar = ' ';
    nextChar = getchar();

    if(nextChar == '\n') {

        /* get next line */
        fgets(input, MAX_LEN, stdin);

        /* line by line loop until EOF */
        while (1) {
            /* char by char loop for each line input */
            for (int i=0; i<MAX_LEN; ) {
                /* see '\n': print and jump to next line */
                if (input[i] == '\n') {
                    printf("\n");
                    break;
                }

                if (input[i] == input[i + 1]) {
                    /* repetition compression found */
                    i+=2;
                    int j=0;
                    int cnt=0;

                    /* process each digit char */
                    while(input[i] != '*') {
                        int digit = ((int) input[i]) - 48;
                        number[j] = digit;
                        i++, j++;
                    }

                    /* read digits in number[] & restore actual cnt */
                    for(int c=1; c<=j; c++){
                        if(j-c>0) {
                            /* digit weight: 10^(j-c): number[0]: highest weight */
                            cnt += (int) (number[c-1] * pow(10, j-c));
                        }else{
                            /* digit weight: 10^0 */
                            cnt += number[c-1];
                        }
                    }

                    /* end of repeat pattern compression */
                    if(input[i] == '*') i++; 

                    /* print compressed repeat pattern */
                    for (int k=0; k<cnt; k++){
                        printf("%c", input[i-j-2]);
                    }
                }else{
                    /* no repeat: direct print */
                    printf("%c", input[i]);
                    i++; 
                }
            }
            /* get next line */
            char *ret = fgets(input, MAX_LEN, stdin);
            /* check EOF */
            if(ret==NULL) return;
        }
    }
}


int main() {
    /* process first instruction char */
    char inputChar = ' ';
    inputChar = getchar();

    /* check input char to enter compress or expand mode */
    switch(inputChar){
        case('C'):
            compress();
            break;
        case('E'):
            expand();
            break;
        /* any other input including EOF will end program */
        default:
            break;
    }

    return 0;
}



/*
 * Result: Accepted
 */
