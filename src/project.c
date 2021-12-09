/*
 * project.c
 */

#include "project.h"

/*
 * init_platform()
 */
void init_platform(int platform[], int levels) {
    for (int i = 0; i < levels; i++) { 
        platform[i] = rand() % 2;
    }   
}   

/*
 * init_rows()
 */
void init_rows(char row1[], char row1[]) {
    for (int i = 0; i < levels; i++) {
        row1[i] = '?';
        row2[i] = '?';
    }   
} 

/*
 * runSquidGame()
 */
void runSquidGame(void) {
    int lives = 16;

    printf("\n Welcome to the infamous Game 5 from the hit Netflix show “Squid Games”. You will be tasked with the challenge of crossing a bridge to safety, however the bridge is no ordinary platform. The bridge has two long rows, each consisting of 20 glass squares. In each column of the rows, one square is made of a weak glass that cannot hold the weight of one individual, while the other square can hold up to two individuals. The aim of the game is to make it past all 20 levels by choosing either the left or right square on each level. Since there were 16 contestants left in the show, you are granted 16 lives. You will have the option to play on “easy” (graphic) or “hard” (memory) mode. Good luck! \n");
    
    int levels = 20;
    int  platform[levels];

    srand(time(NULL));


    init_platform(platform, levels);

/*                                          Progress check 1
    for (int i = 0; i < levels; i++)
    {
        printf("\n %d", platform[i]);
    }

*/ 

    int progress = 0;
    
    int response;
    int difficulty;
    
    char row1[levels];
    char row2[levels];

    init_rows(row1, row2, levels);

    printf("\n Would You Like To Play Easy Mode (Birds Eye View) Or Hard Mode (Memory)?");
    printf("\n Easy Mode = 0 and Hard Mode = 1 \n");
    scanf("%d", & difficulty);

    while (lives > 0)
    {
        if (progress == levels)
        {
            printf("\n You Win! \n");
            return;
        }
        
        if (difficulty == 0)
        {
            printf("\n0:  |");
            for(int i = 0; i < levels; i++)
            { 
                printf("%c|", row1[i]);
            }

            printf("\n    +");
            for(int i = 0; i < levels; i++)
            {
                printf("-+");
            }

            printf("\n1:  |");
            for(int i = 0; i < levels; i++)
            {
                printf("%c|", row2[i]);
            }

         }

        printf("\n Platform: %d ", progress);
        printf("\n Lives Remaining: %d ", lives);
        printf("\n Please select left or right (left = 0 and right = 1): ");   

        scanf("%d", & response);

       /* printf("\n response %d \n", response);        Progress check 2
       */

        if (response == platform[progress])
        { 
            printf("\n You Pass \n");

            if (response == 0)
            {
                row1[progress] = 'O';
                row2[progress] = 'X';
            }
            
            else
            {
                row1[progress] = 'X';
                row2[progress] = 'O';
            }
            
            progress++;
        }
        
        else 
        { 
            printf("\n You Fall \n");
            lives--;
            if (response == 0)
            { 
                row1[progress] = 'X';
            }

            else
            {
                row2[progress] = 'X';
            }
            progress = 0;
        }

            
    }


    printf("\n You Ran Out Of Lives! Game Over. \n");   

 }    
    
















