#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* constants below allow some extra space */
#define MAX_WORD_LEN 33
#define MAX_WORD_CNT 303
#define MAX_LINE_LEN 103


/* struct stores a unique word and its count */
struct List{
    char word[MAX_WORD_LEN];
    int cnt;
};

/* typedef for clarity */
typedef struct List* structPtr;


/* intentional global structPtr array */
structPtr total[MAX_WORD_CNT];


/* inits input char array for
 * string storage */
void arrInit(char input[], int len){
    for (int i=0; i<len; i++){
        input[i] = 0;
    }
}


/* takes a char array in lower case
 * and deletes punctuations anywhere */
void keepAlpha(char input[]){
    int len = strlen(input);
    for (int i=0; i<len; i++){
        if (!(input[i] >='a' && input[i]<='z')){
            if(i==len-1){
                /* punctuation at tail */
                input[i] = '\0';
                /* update length */
                len = strlen(input);
            }else{
                /* punctuation in the middle */
                /* delete by left shift all chars after it */
                for(int j=i; j<len-1; j++){
                    input[j] = input[j+1];
                }

                /* update the new string terminator */
                input[len-1] = '\0';
                /* update length */
                len = strlen(input);
            }
        }
    }
}


/* sort the structPtr array by
 * its word member alphabetical order */
void sort(structPtr in[MAX_WORD_CNT], int len){

    /* bubble sort */
    for(int i=len-1; i>=0; i--){
        for(int j=0; j<i; j++){
            /* check NULL */
            if(in[j] != NULL && in[j+1] != NULL){
                /* compare by strcmp() */
                int ret = strcmp(in[j]->word, in[j+1]->word);

                if(ret > 0){
                    /* if in[j] should be at in[j+1]: swap */
                    structPtr buf = in[j+1];
                    in[j+1] = in[j];
                    in[j] = buf;
                }else{
                    /* do nothing */
                }
            }
        }
    }
}

/* free each ptr to mem space calloc allocated to
 * a struct in wordCnt() for a unique word */
void freeAll(structPtr input[]){
    for(int i=0; i<MAX_WORD_CNT; i++){
        /* check NULL */
        if(input[i] != NULL) free(input[i]);
    }
}

/* count how many unique words in
 * the total[] for later print loop condition */
int uniqueCnt(structPtr input[]){
    int cnt = 0;
    for (int i=0; i<MAX_WORD_CNT; i++){
        /* check NULL */
        if(input[i]!=NULL){
            cnt++;
        }
    }
    return cnt;
}

/* cast each word to lowercase */
void lower(char input[]){
    /* update length */
    int len = strlen(input);

    for(int i=0; i<len; i++){
        /* check is uppercase */
        if(input[i]>='A' && input[i]<='Z'){
            /* add ASCII offset to lowercase range */
            input[i] += 32;
        }
    }
}


void wordCnt(){

    int lineCnt = 0;
    char input [MAX_LINE_LEN]; /* char array for line input */
    arrInit(input, MAX_LINE_LEN); /* init this buffer array */
    fgets(input, MAX_LINE_LEN, stdin); /* get line input */
    lineCnt++;
    /* index i for new unique word struct stored in total[] */
    int i=0;

    /* line by line loop until EOF */
    while(1){

        /* lower case word */
        lower(input);
        /* split line string into tokens without ' ' & '\n' */
        char *token = strtok(input, " \n");

        /* word by word loop until end of sentence */
        while(token!=NULL){

            /* just word no punctuation */
            keepAlpha(token);

            /* for each word, check if already in total */
            for(int m=0; m<i; m++){
                if(total[m] != NULL){
                    if(strcmp(total[m]->word, token) == 0){
                        /* a repetition found, just ++ */
                        total[m]->cnt++;
                        /* go to next token, no new struct */
                        goto label;
                    }
                }
            }

            /* arrange a new struct for the new unique word */
            structPtr ptr = (structPtr) calloc(1, sizeof(struct List));
            /* check for calloc success */
            if (ptr==NULL){
                fprintf(stderr, "out of memory!\n");
                exit(1);
            }

            ptr->cnt = 1;
            strcpy(ptr->word,token);
            total[i] = ptr;

            i++;

            /* goto next token, no new struct */
            label:
            token = strtok(NULL, " \n");
        }

        /* clear line input buffer */
        arrInit(input, MAX_LINE_LEN);
        /* update next line */
        char* ret = fgets(input, MAX_LINE_LEN, stdin);
        /* check if EOF: break */
        if(ret == NULL) break;

        lineCnt++;
    }

    /* sort structPtr array at last, i as array actual length */
    sort(total, i);

    /* count how many unique words to print */
    int uniqueWords = uniqueCnt(total);
    /* print all unique words & its cnt */
    for(int idx=0; idx<uniqueWords; idx++){
        if(total[idx] != NULL) {
            printf("%s => %d\n", total[idx]->word, total[idx]->cnt);
        }
    }
    /* free ptrs in total[] allocated by calloc */
    freeAll(total);
}


int main() {
    wordCnt();


    return 0;
}


/*
 * Result: Accepted
 */
