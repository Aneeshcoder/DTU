#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Used to clear (or flush) the input buffer
#define FLUSH fflush(stdin)

void difficulty( void );
void beginner( void );
void intermediate( void );
void expert( void );
void minefield_generator( void );
void print_minefield( void );
void guess( void );
void boom( void );
void print_final_minefield( void );
void win( void );
void play_again( void );
void game_over( void );

// Global variables
int x, y;
int M, N;
int diff;
int total_mines = 0;
int mines = 0;
int minefield[30][30];                                   
int blank_minefield[30][30];                              
int final_minefield[30][30];

int main()
{
    system("cls");
    printf("Welcome to Minesweeper\n");
    difficulty();
    return 0;
}


void difficulty( void )                                 
{
    diff = 0;
    printf("Choose a difficulty level(1-3): ");
    scanf("%d", &diff);
    FLUSH;

    if( diff == 1 )                                        
    {
        beginner();
    }
    else if( diff == 2 )
    {
        intermediate();
    }
    else if( diff == 3 )
    {
        expert();
    }

}


void beginner( void )                                      
{
    M = 9;
    N = 9;
    total_mines = 10;
    minefield_generator();
    guess();
}


void intermediate( void )                                  
{
    M = 16;
    N = 16;
    total_mines = 40;
    minefield_generator();
    guess();
}


void expert( void )                                        
{
    M = 16;
    N = 30;
    total_mines = 99;
    minefield_generator();
    guess();
}


void minefield_generator( void )                          
{
    int i = 0, j = 0;

    // Seed for random number
    srand( time( NULL ) );                              

    while( j < N )                                         
    {
        while( i < M)
        {
            minefield[i][j] = '-';
            blank_minefield[i][j] = minefield[i][j];
            final_minefield[i][j] = minefield[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    
    mines = 0;
    while( mines < total_mines )                            
    {
        // Random integers
        i = rand()%(M);
        j = rand()%(N);
        if( minefield[i][j] != '*')
        {
            minefield[i][j] = '*';
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < N )                                          
    {
        while( i < M)
        {
            if( minefield[i][j] != '*')
            {
                minefield[i][j] = 0;
            }
            if((minefield[i-1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}


void print_minefield(void)                               
{
    printf("\n");
    int i = 0, j = 0, z = 0;
    while( z < M )                                         
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )                                          
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            if( blank_minefield[i][j] == '-')
            {
                printf("|%c|\t", blank_minefield[i][j]);
            }
            else if( minefield[i][j] == 0 )                
            {
                printf("|%d|\t", blank_minefield[i][j]);
            }
            else
            {
                printf("|%d|\t", blank_minefield[i][j]);
            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void guess( void )
{
    int q = 0, i=0, j=0, match=0;
    print_minefield();
    while( j < N )                                          
    {
        while( i < M )
        {
            if(minefield[i][j] == blank_minefield[i][j])
            {
                match++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if( match == (( M * N ) - total_mines))                 
    {
        win();
    }
    printf("\n\nEnter the x value, then a space, then the y value: ");
    scanf("%d %d", &x, &y);                                 
    FLUSH;
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("\nPlease enter a value inside the grid\n");
        guess();
    }
    if( minefield[x][y] == '*' )                            
    {
        boom();
    }
    if( blank_minefield[x][y] != '-' )
    {
        printf("\nPlease enter a value that has not already been entered\n");
        guess();
    }

    else                                              
    {
        blank_minefield[x][y] = minefield[x][y];
        if( minefield[x][y] == 0 )
        {
            if( minefield[x-1][y-1] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x-1][y] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x][y-1] == 0 )
            {
                blank_minefield[x][y-1] = minefield[x][y-1];
            }
            if( minefield[x-1][y+1] == 0 )
            {
                blank_minefield[x-1][y+1] = minefield[x-1][y+1];
            }
            if( minefield[x+1][y-1] == 0 )
            {
                blank_minefield[x+1][y-1] = minefield[x+1][y-1];
            }
            if( minefield[x+1][y] == 0 )
            {
                blank_minefield[x+1][y] = minefield[x+1][y];
            }
            if( minefield[x][y+1] == 0 )
            {
                blank_minefield[x][y+1] = minefield[x][y+1];
            }
            if( minefield[x+1][y+1] == 0 )
            {
                blank_minefield[x+1][y+1] = minefield[x+1][y+1];
            }
        }
        guess();
    }
}


void boom( void )                                       
{
    print_final_minefield();
    printf("\n\nYou hit a mine at %d,%d\nYOU LOSE !!!!", x, y);
    play_again();
}


void print_final_minefield( void )                      
{
    printf("\n");
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            printf("|%c|\t", final_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void win( void )                                       
{
    printf("\n\n\nYOU WIN !!!!!\n\n\n");
    play_again();
}


void play_again( void )                                
{
    char option[2];
    printf("\n\nWould you like to play again(Y/N)?: ");
    scanf("%c", &option[0]);
    FLUSH;
    if((option[0] == 'Y') || (option[0] == 'y'))       
    {
        difficulty();
    }
    else if( (option[0] == 'N') || (option[0] == 'n'))
    {
        game_over();
    }
    else
    {
        printf("Please enter either Y or N");
        play_again();
    }
}


void game_over( void )                                  
{
    printf("\n\nGame Over !!!!!\n\n\n");
    exit(0);
}
