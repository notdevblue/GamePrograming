// 20219 한우엽


// 난이도 문제 번호 <== 순으로 찾아가실 수 있어요.

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
#define BULLET_POSITION_X 6
#define BULLET_POSITION_Y 20
#define GAMEOVER_X 8
#define SAFE_Y DINO_BOTTOM_Y - 4

bool bLegFlag       = false;
bool isJumping      = false;
bool isBottom       = false;
bool isGameOver     = false;
bool isFiredRight   = false;
bool isFiredUp      = false;
bool bHit           = false;
bool bUpHit         = false;
const int gravity = 3;

int dinoY = DINO_BOTTOM_Y;
int treeX = THREE_BOTTOM_X;
int birdY = 2;
int birdX = THREE_BOTTOM_X;
int bulletX = GAMEOVER_X;
int bulletY = DINO_BOTTOM_Y;
int score = 0;

unsigned int frame = 0;
unsigned int hitframe = 0;
unsigned int uphitframe = 0;

void setConsoleView();
void drawDino(int);
void drawBird(int);
void drawTree(int);
void drawBulletY(int);
void drawBulletX(int);
void drawScore();
void drawGameOver();

int getkey();

int main()
{
    setConsoleView();
    
    while (!isGameOver)
    {
        switch (getkey())
        {
        case 'j':
            if (isBottom)
            {
                isJumping = true;
                isBottom = false;
            }
            break;

        case 'a': // 기본 문제 1
            if (!isFiredRight)
            {
                isFiredRight = true;
            }
            break;

        case 'u': // 심화 문제 2
            if (!isFiredUp)
            {
                isFiredUp = true;
            }
            break;
        }


        
        if (treeX <= GAMEOVER_X && dinoY >= SAFE_Y)
        {
            isGameOver = true;
        }

       
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
        birdX -= 2;
		if (treeX <= 0 || bHit) // 기본 문제 1
		{
			treeX = THREE_BOTTOM_X;
		}
        if (birdX <= 0 || bUpHit) // 심화 문제 2
		{
			birdX = THREE_BOTTOM_X;
		}

        if (bulletX >= THREE_BOTTOM_X) // 기본 문제 1
        {
            bulletX = GAMEOVER_X;
            isFiredRight = false;
        }
        if (bulletY <= 0) // 심화 문제 2
        {
            bulletY = DINO_BOTTOM_Y;
            isFiredUp = false;
        }

        if (isFiredRight) // 기본 문제 1
        {
            bulletX += 2;
            
            drawBulletX(bulletX);

            if (treeX >= bulletX - 1 && treeX <= bulletX + 1)
            {
                hitframe = frame;
                ++score;
                bHit = true;
                isFiredRight = false;
                bulletX = GAMEOVER_X;
            }
        }

        if (isFiredUp) // 심화 문제 2 : 새 충돌 체크
        {
            --bulletY;

            drawBulletY(bulletY);

            if (bulletY == birdY && BULLET_POSITION_X <= birdX + 8 && BULLET_POSITION_X >= birdX)
            {
                uphitframe = frame;
                ++score;
                bUpHit = true;
                isFiredUp = false;
                bulletY = DINO_BOTTOM_Y;
            }
        }


        if (hitframe + 10 <= frame)
            bHit = false;
        if (uphitframe + 10 <= frame)
            bUpHit = false;


        drawScore();
        drawDino(dinoY);

        if (!bHit)
        {
            drawTree(treeX);
        }
        if (!bUpHit)
        {
            drawBird(birdX);
        }
        
        
        
        ++frame;
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

void drawBird(int posX) // 심화 문제 1 : 새 구현
{
    gotoXY(posX, 1);
    std::cout << "--BIRD--";
}

void drawBulletY(int posY) // 심화 문제 2 : 총알 위로 발사
{
    gotoXY(BULLET_POSITION_X, posY);
    std::cout << "B";
    gotoXY(BULLET_POSITION_X, posY + 1);
    std::cout << "U";
    gotoXY(BULLET_POSITION_X, posY + 2);
    std::cout << "L";
    gotoXY(BULLET_POSITION_X, posY + 3);
    std::cout << "L";
    gotoXY(BULLET_POSITION_X, posY + 4);
    std::cout << "E";
    gotoXY(BULLET_POSITION_X, posY + 5);
    std::cout << "T";
}

void drawBulletX(int posX) // 기본 문제 1 : 총알 발사
{
    gotoXY(posX, BULLET_POSITION_Y);
    std::cout << "BULLET>";
}

void drawScore()
{
    gotoXY(40, 3);
    std::cout << "Score: " << score;
} // 기본 문제 2 : 점수 표시

void drawGameOver()
{
    gotoXY(15, 25);
    std::cout << "\r\n게임 오버" << std::endl;
    std::cout << "점수 : " << score << std::endl;
}

int getkey()
{
    if (_kbhit())
    {
        return _getch();
    }
}