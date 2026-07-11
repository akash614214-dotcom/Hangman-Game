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
    a = rand() % 17 + 1;
    for(i=0;i<len[a];i++)
    {
        guess[i] = '_';
    }
    guess[len[a]] = '\0';

    printf("==== HANGMAN GAME ====\n");

    attempt = 6;
    while(attempt > 0)
    {
        printf("\nWord: ");
        for(i=0;i<len[a];i++)
        {
            printf("%c", guess[i]);
            printf(" ");
        }
        printf("\nAttempts Left: %d", attempt);
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
    int n = 0;
    strcpy(word[n], "PYTHON");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "BEAR");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "LION");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "ELEPHANT");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "PEACOCK");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "TIGER");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "DONKEY");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[7], "RABBIT");
    len[7] = strlen(word[7]);
    n++;
    strcpy(word[8], "GOAT");
    len[8] = strlen(word[8]);
    n++;
    strcpy(word[9], "DEER");
    len[9] = strlen(word[9]);
    n++;
    strcpy(word[10], "PIG");
    len[10] = strlen(word[10]);
    n++;
    strcpy(word[n], "COW");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "LEOPARD");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "SNAKE");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "FOX");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "PANDA");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "SPARROW");
    len[n] = strlen(word[n]);
    n++;
    strcpy(word[n], "EAGLE");
    len[n] = strlen(word[n]);
    n++;

}