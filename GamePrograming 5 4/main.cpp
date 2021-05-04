#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void gotoXY(int x, int y)
{
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x * 2;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}

void clrscr()
{
    system("cls");
}

/*
"        $$$$$$$ "
"       $$ $$$$$$"
"       $$$$$$$$$"
"$      $$$      "
"$$     $$$$$$$  "
"$$$   $$$$$     "
" $$  $$$$$$$$$$ "
" $$$$$$$$$$$    "
"  $$$$$$$$$$    "
"    $$$$$$$$    "
"     $$$$$$     "
"     $    $$$   "
"     $$         "

"        $$$$$$$ "
"       $$ $$$$$$"
"       $$$$$$$$$"
"$      $$$      "
"$$     $$$$$$$  "
"$$$   $$$$$     "
" $$  $$$$$$$$$$ "
" $$$$$$$$$$$    "
"  $$$$$$$$$$    "
"    $$$$$$$$    "
"     $$$$$$     "
"     $$$  $     "
"          $$    "
*/

#define DINO_TOP_Y 1
#define DINO_BOTTOM_Y 12
#define THREE_BOTTOM_X 45
#define THREE_BOTTOM_Y 20
#define GAMEOVER_X 8
#define SAFE_Y DINO_BOTTOM_Y - 4

bool bLegFlag   = false;
bool isJumping  = false;
bool isBottom   = false;
bool isGameOver = false;
const int gravity = 3;

int dinoY = DINO_BOTTOM_Y;
int treeX = THREE_BOTTOM_X;

void setConsoleView();
void drawDino(int);
void drawTree(int);
void drawGameOver();

int getkey();

int main()
{
    setConsoleView();
    
    while (!isGameOver)
    {
        if (getkey() == 'j' && isBottom /*&& !isGameOver*/) 
        {
            isJumping = true;
            isBottom = false;
        }
        
        if (treeX <= GAMEOVER_X && dinoY >= SAFE_Y)
        {
            isGameOver = true;
        }

        if (true/*!isGameOver*/)
        {
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }

            if (dinoY <= DINO_TOP_Y)
            {
                dinoY = DINO_TOP_Y;
                isJumping = false;
            }
            else if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
            }

            treeX -= 2;
            if (treeX <= 0)
            {
                treeX = THREE_BOTTOM_X;
            }
        }
        else
        {
            drawGameOver();
        }

        drawDino(dinoY);
        drawTree(treeX);
        
        
        
        Sleep(80);
        
        if(!isGameOver)
        clrscr();

        bLegFlag = !bLegFlag;
    }
    
    drawGameOver();

    return 0;
}

void setConsoleView()
{
    system("mode con:cols=100 lines=25");
    system("title 인터넷 연결 오류 게임");

    
}

void drawDino(int posY)
{
    gotoXY(0, posY);
    std::cout << "        $$$$$$$ " << std::endl;
    std::cout << "       $$ $$$$$$" << std::endl;
    std::cout << "       $$$$$$$$$" << std::endl;
    std::cout << "$      $$$      " << std::endl;
    std::cout << "$$     $$$$$$$  " << std::endl;
    std::cout << "$$$   $$$$$     " << std::endl;
    std::cout << " $$  $$$$$$$$$$ " << std::endl;
    std::cout << " $$$$$$$$$$$    " << std::endl;
    std::cout << "  $$$$$$$$$$    " << std::endl;
    std::cout << "    $$$$$$$$    " << std::endl;
    std::cout << "     $$$$$$     " << std::endl;


    if (bLegFlag)
    {
        std::cout << "     $$$  $     " << std::endl;
        std::cout << "          $$    ";
    }
    else
    {
        std::cout << "     $    $$$   " << std::endl;
        std::cout << "     $$         ";
    }
}

void drawTree(int posX)
{
    gotoXY(posX, THREE_BOTTOM_Y);
    std::cout << "####";
    gotoXY(posX, THREE_BOTTOM_Y + 1);
    std::cout << " ## ";
    gotoXY(posX, THREE_BOTTOM_Y + 2);
    std::cout << " ## ";
    gotoXY(posX, THREE_BOTTOM_Y + 3);
    std::cout << " ## ";
    gotoXY(posX, THREE_BOTTOM_Y + 4);
    std::cout << " ## ";
}

void drawGameOver()
{
    gotoXY(15, 25);
    std::cout << "게임 오버" << std::endl;
}

int getkey()
{
    if (_kbhit())
    {
        return _getch();
    }
}