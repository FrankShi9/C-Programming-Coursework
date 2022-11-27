#include <stdio.h>

int main() {
    const double PI = 3.14;
    /* minimum loss double inner calculation */
    double area= 0.0, c = 0.0;
    int r1 = 0, r2 = 0;
    scanf("%d %d", &r1, &r2);
    /* handle special cases */
    if(r1<0 || r2<r1){
        return -1;
    }
    for (int i=r1; i<=r2; i++) {
        c += 2 * PI * (i);
        area += PI * i * i;
    }
    /* output based on requirement */
    printf("%.3f\n%.3f\n", area, c);

    return 0;
}


/*
 * Result: Accepted
 */


