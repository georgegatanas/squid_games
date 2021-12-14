void printGame(int levels, char *row1, char *row2)          /* George G */
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
    
















