#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

char word[50][20], guess[20];
int len[20], guesslen[20];

void list();

int main () {
    int a, i, attempt, found=0;
    char ch;
    srand(time(NULL));
    list();
    a = rand() % 6 + 1;
    printf("%d", a);
    for(i=0;i<len[a];i++)
    {
        guess[i] = '_';
    }
    guess[len[a]] = '\0';

    printf("==== HANGMAN GAME ====");

    attempt = 6;
    while(attempt > 0)
    {
        printf("\nWord: ");
        for(i=0;i<len[a];i++)
        {
            printf("%c", guess[i]);
            printf(" ");
        }
        printf("Attempts Left: %d", attempt);
        found = 0;
        printf("\nEnter Letter: ");
        scanf(" %c", &ch);
        ch = toupper(ch);

        for(i=0;i<len[a];i++)
        {
            if(word[a][i] == ch && guess[i]=='_')
            {
                guess[i] = ch;
                found = 1;
            }
        }
        if(found==0)
        {
            printf("Wrong Guess!\n");
            attempt--;
        }
        else
        {
            printf("Correct Guess.\n");
        }
        if(strcmp(word[a], guess) == 0)
        {
            printf("CONGRATS! YOU WON 😀\n");
            break;
        }
        
    }
    if(attempt == 0)
    {
        printf("You Lost!\n");
        printf("Word was %s", word[a]);
    }
    
    return 0;
}

// Word List
void list() {
    strcpy(word[0], "PYTHON");
    len[0] = strlen(word[0]);
    strcpy(word[1], "BEAR");
    len[1] = strlen(word[1]);
    strcpy(word[2], "LION");
    len[2] = strlen(word[2]);
    strcpy(word[3], "ELEPHANT");
    len[3] = strlen(word[3]);
    strcpy(word[4], "PEACOCK");
    len[4] = strlen(word[4]);
    strcpy(word[5], "TIGER");
    len[5] = strlen(word[5]);
    strcpy(word[6], "DONKEY");
    len[6] = strlen(word[6]);
    strcpy(word[7], "RABBIT");
    len[7] = strlen(word[7]);
    strcpy(word[8], "GOAT");
    len[8] = strlen(word[8]);
    strcpy(word[9], "DEER");
    len[9] = strlen(word[9]);
    strcpy(word[10], "PIG");
    len[10] = strlen(word[10]);
    strcpy(word[11], "COW");
    len[11] = strlen(word[11]);

}