void makeChoice(int *platform, int *progress, int *lives, char *row1, char *row2)
{    
    int response;		/* George G */
    scanf("%d", & response);					/* George G */
    
    if (response == platform[*progress])			/* George G */
    {
        printf("\n You Pass \n");
        
        if (response == 0)
        {
            row1[*progress] = 'O';
            row2[*progress] = 'X';
        }
        
        else
        {
            row1[*progress] = 'X';
            row2[*progress] = 'O';
        }
        
        (*progress)++;
    }

    else			                      	/* George G */	
    {
        printf("\n You Fall \n");
        (*lives)--;
        if (response == 0)
        {
            row1[*progress] = 'X';
        }
        
        else
        {
            row2[*progress] = 'X';
        }
            
        *progress = 0;
    }
}
