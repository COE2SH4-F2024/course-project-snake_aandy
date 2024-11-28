#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


Player *myplayer;
GameMechs *game;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(game -> getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    game = new GameMechs();
    myplayer = new Player(game);
    
}

void GetInput(void)
{
   game -> getInput();
}

void RunLogic(void)
{
    myplayer -> updatePlayerDir();
    myplayer -> movePlayer();
}

void DrawScreen(void)
{
    objPos border;
    objPos space;
    objPos rand1 (3,3,'!');
    objPos rand2(2,2,'&');
    objPos rand3(5,6,'@');
    objPos currentplayer = myplayer -> getPlayerPos();
    
    MacUILib_clearScreen();    
    int i, k;
    int j;
    for (j = 0; j < 10; j++)
    {
        for(i = 0; i < 20; i++)
        {

                if (i == 0 || i == 19)
                {
                    border.setObjPos(i,j,'#');
                    MacUILib_printf("%c", border.symbol);
                     
                }

                else if ((j == 0 || j == 9))
                {
                    border.setObjPos(i,j,'#');
                    MacUILib_printf("%c", border.symbol);  
                }

                else if (i == rand1.pos -> x && j == rand1.pos -> y)
                {
                    MacUILib_printf("%c", rand1.symbol);
                }

                else if (i == rand2.pos -> x && j == rand2.pos -> y)
                {
                    MacUILib_printf("%c", rand2.symbol);
                    
                }

                else if (i == rand3.pos -> x && j == rand3.pos -> y)
                {
                    MacUILib_printf("%c", rand3.symbol);
                }

                else if (i == currentplayer.pos -> x && j == currentplayer.pos -> y)
                {
                    MacUILib_printf("%c", currentplayer.symbol);
                }

                else
                {
                    space.setObjPos(i, j, ' ');
                    MacUILib_printf("%c", space.symbol); 
                }
        
        }
        printf("\n");

        
        }
        MacUILib_printf("Current Player Character = %c, with coordinates [%d,%d]", currentplayer.symbol, currentplayer.pos -> x, currentplayer.pos -> y);
        MacUILib_printf("\nCurrent key pressed = %c", game -> getInput());


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete myplayer;
    delete game;
    MacUILib_uninit();
}
