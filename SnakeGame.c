// Header Files
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

// Constants and Macros
#define ROWS 25
#define COLUMNS 100
#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

// Move up X lines, 1 -> means move up 1 line
#define UP    printf("\033[1A")
// Move down X lines, 1 -> means move down 1 line
#define DOWN     printf("\033[1C") 
// Move right X column , 1 -> means move right 1 column
#define RIGHT     printf("\033[1D") 
// Move left X column, 1 -> means move left 1 column
#define LEFT    printf("\033[1B") 

// Global Declarations      
int posX = 20, posY = 20;  // intial position starts at (0,0) and (1,1)  and is same
                             // first asterisk position is (1,2)    // given board name (A>B>C>D) in clockwise direction
                             //point A of board position is (1,2)   //point B of board position is (100,2)
                             //point D of board position is (1,26)  //point C of board position is (100,26) 
char playerinput;
char inputchecker;

// Functions Declarations
void Border();
void Snake(int posX, int posY);
void GameOver();

int main()
{
    
    int n = 100, i = 1;
    char input = '0';

    clear();
    Border();
    inputchecker = 'd';

    while((_kbhit() && (input = getch())) || i++ != n )
    {
            playerinput = input;
            if(playerinput == 'w')
            {
               if(posY == 2) break;

                if(inputchecker == 'a' || inputchecker == 'd')
                {         
                UP;
                posY--;
                Snake(posX, posY);
                inputchecker = playerinput;
                }
                else if(inputchecker == 'w')
               { 
                 Snake(posX, posY);
                 posY--;
               }
               else
               {
                  Snake(posX, posY);
                  posY++;
               }
            }
            else if (playerinput == 's')
            {
                if(posY == 26) break;

                if(inputchecker == 'a' || inputchecker == 'd'){
                DOWN;
                 posY++;
                Snake(posX, posY);
                 inputchecker = playerinput;
                }
                else if(inputchecker == 's')
                { 
                   Snake(posX, posY);
                   posY++;
                }
                else
               {
                 Snake(posX, posY);
                 posY--;
               }
            }
            else if (playerinput == 'a')
            {
                if(posX == 1) break;
                 
                if(inputchecker == 'w' || inputchecker == 's'){
                  LEFT;
                  posX--;
                  Snake(posX, posY);
                  inputchecker = playerinput;
                }
                 else if(inputchecker == 'a')
                { 
                   Snake(posX, posY);
                   posX--;
                }
                else
               {
                 Snake(posX, posY);
                 posX++;
               }
            }
            else if (playerinput == 'd')
            {
                 if(posX == 100) break;

                 if(inputchecker == 'w' || inputchecker == 's'){
                   RIGHT;
                   posX++;
                   Snake(posX, posY);
                   inputchecker = playerinput;
                 }
                  else if(inputchecker == 'd')
                { 
                   Snake(posX, posY);
                   posX++;
                }
                else
               {
                 Snake(posX, posY);
                 posX--;
               }
            }
            else
            {
              Snake(posX, posY);
              posX++;
             }
     }

    GameOver();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return 0;
}


void GameOver()
{
   clear();
       char underscore[] = "____________________________________________";

   printf("%s SNAKE GAME %s\n", underscore, underscore);
    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 1; j <= COLUMNS; j++)
        {
           if(i == 1 || i == ROWS || j == 1 || j == COLUMNS)
            {
                
                printf("*");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }

    int x = 36,y = 11;
    gotoxy(x,y);
     for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
           if(i == 1 || i == 5 || j == 1 || j == 30)
            {
                
                printf("*");
            }
            else
            {
                printf(" ");
            }

        }
        y++;
        gotoxy(x,y);
    }
    
    // Moves cursor to X,Y position to print gaveover screen
    gotoxy(46,13);          
    printf("GAME OVER\n");
}


void Border()
{
    char underscore[] = "____________________________________________";

   printf("%s SNAKE GAME %s\n", underscore, underscore);
    
    //printf("\n  U+1FB0x : \u25b3 \n");

    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 1; j <= COLUMNS; j++)
        {
           if(i == 1 || i == ROWS || j == 1 || j == COLUMNS)
            {
                
                printf("*");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }

}


void Snake(int posXX, int posYY)
{
    char snake = '#';
    gotoxy(posXX, posYY);
    printf("%c", snake);
    Sleep(100);
    
}
