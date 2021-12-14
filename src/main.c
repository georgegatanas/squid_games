#include <stdio.h>
#include "project.h"
#include "make_choice.h"

int main()
{
    int lives = 16;		/* George G */
    
    printf("\n Welcome to the infamous Game 5 from the hit Netflix show “Squid Games”. You will be tasked with the challenge of crossing a bridge to safety, however the bridge is no ordinary platform. The bridge has two long rows, each consisting of 20 glass squares. In each column of the rows, one square is made of a weak glass that cannot hold the weight of one individual, while the other square can hold up to two individuals. The aim of the game is to make it past all 20 levels by choosing either the left or right square on each level. Since there were 16 contestants left in the show, you are granted 16 lives. You will have the option to play on “easy” (graphic) or “hard” (memory) mode. Good luck! \n");         /* George S */
    int levels = 20;		/* George G */
    int  platform[levels];		/* George G */
    
    srand(time(NULL));			/* George G */
    for (int i = 0; i < levels; i++)		/* George G */
    {
        platform[i] = rand() % 2;
    }
    
/*                                         Progress check 1
    for (int i = 0; i < levels; i++)
    {
        printf("\n %d", platform[i]);
    }
*/

    int progress = 0;		/* George G */
    int difficulty;			/* George G */
    
    char row1[levels];         /* George G */
    char row2[levels];          /* George G */

    for (int i = 0; i < levels; i++)            /* George G */
    {
        row1[i] = '?';
        row2[i] = '?';
    }
    
    printf("\n Would You Like To Play Easy Mode (Birds Eye View) Or Hard Mode (Memory)?");	/* George S */
    printf("\n Easy Mode = 0 and Hard Mode = 1 \n");			/* George S */
    scanf("%d", & difficulty);				/* George S */

    while (lives > 0)                            /* George S */
    {
        if (progress == levels)
        {
            printf("\n You Win! \n");
            return 0;
        }
        
        if (difficulty == 0)				
        {
            printGame(levels, row1, row2);
        }
        
        printf("\n Platform: %d ", progress);				
        printf("\n Lives Remaining: %d ", lives);				
        printf("\n Please select left or right (left = 0 and right = 1): ");	
        
        makeChoice(platform, &progress, &lives, row1, row2);

    }
    
    printf("\n You Ran Out Of Lives! Game Over. \n");			/* George S */
    
    return 0;					/* George S */
}
