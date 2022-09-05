// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

// Constants and Macros
#define ROWS 25
#define COLUMNS 100
#define clear() printf("\033[H\033[J")
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

// Move up X lines
#define UP printf("\033[1A")
// Move down X lines
#define DOWN printf("\033[1C")
// Move right X column
#define RIGHT printf("\033[1D")
// Move left X column
#define LEFT printf("\033[1B")

// Global Declarations
int posX = 20, posY = 20; // intial position starts at (0,0) and (1,1)  and is same
                          // first asterisk position is (1,2)    // given board name (A>B>C>D) in clockwise direction
                          // point A of board position is (1,2)   //point B of board position is (100,2)
                          // point D of board position is (1,26)  //point C of board position is (100,26)
int flag = 0;
char playerinput;
char inputchecker;

// Functions Declarations
void Border();
void Snake(int posX, int posY);
void GameOver();
void Food();
int PlayerMove(char *input);

int main()
{
    int n = 100, i = 1;
    char input = '0';

    clear();
    Border();

    inputchecker = 'd';
    int gameover = 0;
    while ((_kbhit() && (input = getch())) || i++ != n)
    {
        Food();
        gameover = PlayerMove(&input);
        if(gameover == 1) break;
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
            if (i == 1 || i == ROWS || j == 1 || j == COLUMNS)
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
    
    int x = 36, y = 11;
    gotoxy(x, y);
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            if (i == 1 || i == 5 || j == 1 || j == 30)
            {

                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        y++;
        gotoxy(x, y);
    }

    gotoxy(46, 13);
    printf("GAME OVER\n");
}

void Border()
{
    char underscore[] = "____________________________________________";

    printf("%s SNAKE GAME %s\n", underscore, underscore);

    // printf("\n  U+1FB0x : \u25b3 \n");

    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 1; j <= COLUMNS; j++)
        {
            if (i == 1 || i == ROWS || j == 1 || j == COLUMNS)
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

int PlayerMove(char *input)
{
    playerinput = *input;

    // ________ INPUT TESTING _________
    // for(; i <= 23;)
    // {
    //    if(i >= 1 && i <= 5)
    //    {
    //          input = 'w';
    //          playerinput = input;

    //          break;
    //    }
    //    else if(i >= 6 && i <= 11)
    //    {
    //          input = 's';
    //           playerinput = input;

    //    break;
    //    }
    //    else if(i >=12 && i <= 17)
    //    {
    //          input = 'd';
    //          playerinput = input;

    //    break;
    //    }
    //    else if(i >=18 && i <= 23)
    //    {
    //          input = 'a';
    //          playerinput = input;

    //    break;
    //    }
    // }

    // printf("%c", playerinput);
    if (playerinput == 'w')
    {
        if (posY == 2)
            return 1;

        if (inputchecker == 'a' || inputchecker == 'd')
        {
            UP;
            posY--;
            Snake(posX, posY);
            inputchecker = playerinput;
        }
        else if (inputchecker == 'w')
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
        if (posY == 26)
            return 1;

        if (inputchecker == 'a' || inputchecker == 'd')
        {
            DOWN;
            posY++;
            Snake(posX, posY);
            inputchecker = playerinput;
        }
        else if (inputchecker == 's')
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
        if (posX == 1)
            return 1;

        if (inputchecker == 'w' || inputchecker == 's')
        {
            LEFT;
            posX--;
            Snake(posX, posY);
            inputchecker = playerinput;
        }
        else if (inputchecker == 'a')
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
        if (posX == 100)
            return 1;

        if (inputchecker == 'w' || inputchecker == 's')
        {
            RIGHT;
            posX++;
            Snake(posX, posY);
            inputchecker = playerinput;
        }
        else if (inputchecker == 'd')
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

void Snake(int posXX, int posYY)
{
    char snake = '#';
    gotoxy(posXX, posYY);
    printf("%c", snake);
    Sleep(100);
}

void Food()
{
    // srand(time(0));
    // const int  minYCrd = 3, maxYCrd = 25, minXCrd = 2, maxXCrd = 99;
    // int randXCrd = (rand() % (maxXCrd - minXCrd + 1)) + minXCrd;
    // int randYCrd = (rand() % (maxYCrd - minYCrd + 1)) + minYCrd;

    // gotoxy(randXCrd, randYCrd);

    char food = '@';
    if (flag == 0)
    {
        gotoxy(70, 8);
        printf("%c", food);
        flag++;
    }
}
