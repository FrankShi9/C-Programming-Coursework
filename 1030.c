#include <stdio.h>

void nDigit();


int main() {
    nDigit();
    return 0;
}

void nDigit(){
    /* same as in the problem description */
    int a=0, b=0, n=0;
    scanf("%d %d %d", &a, &b, &n);
    /* int division to double trick */
    double result = (double) (a)/b;

    for(int i=1; i<=n; i++){
        /* keep multiply 10 to get to the digit position */
        result *= 10;
    }
    /* use % to get the digit, use long long for precision */
    int digit = (long long) (result) % 10;
    printf("%d\n", digit);

}


/*
 * Result: Accepted
 */





