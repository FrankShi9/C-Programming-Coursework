#include <stdio.h>
#define MAX_LEN 50

void strSearch();
void arrInit(char input[]);
int subStrCnt(char s1[], char s2[]);
int strlen(char input[]);


int main() {
    strSearch();
    return 0;
}

void strSearch(){
    /* input <= 50 long */
    char s1 [MAX_LEN], s2 [MAX_LEN], s3 [MAX_LEN];
    /* init char array for input string store */
    arrInit(s1);
    arrInit(s2);
    arrInit(s3);
    /* required output */
    int cnt1 = 0, cnt2 = 0;

    /* get 3 lines of input string in target char array */
    fgets(s1, MAX_LEN, stdin);
    fgets(s2, MAX_LEN, stdin);
    fgets(s3, MAX_LEN, stdin);

    cnt1 = subStrCnt(s1, s2);
    cnt2 = subStrCnt(s1, s3);
    printf("%d %d\n", cnt1, cnt2);
}

void arrInit(char input[]){
    for (int i=0; i<MAX_LEN; i++){
       input[i] = 0;
    }
}

/* utility function to count occurrences
 * of s2 in s1 
 */
int subStrCnt(char s1[], char s2[]){
    /* use self-defined strlen to get length */
    int len1 = strlen(s1), len2 = strlen(s2);
    /* qualify is used to confirm a match of s2 in s1
     * cnt is the total count of s2 in s1 
     */
    int qualify=0, cnt=0;
    for(int i=0; i<len1; i++){
        qualify = 0;
        if(s1[i]==s2[0]){
            for(int j=0; j<len2; j++){
                /* number of chars match within s2 in one pass */
                if(s1[i+j]==s2[j]) qualify++;
            }
        }
        /* confirm a match of s2 in s1 */
        if(qualify==len2) cnt++;
    }   
    return cnt;
}

/* utility function to get strlen */
int strlen(char input[]){
    int cnt=0;
    /* input string <= 50 long */
    for (int i=0; i<MAX_LEN; i++){
        /* '\0' is the end mark of string which does not count */
        if (input[i]!='\0') {
            cnt++;
        }
    }
    /* total count minus the last ASCII Line Feed symbol */
    return cnt-1;
}


/*
 * Result: Accepted
 */
