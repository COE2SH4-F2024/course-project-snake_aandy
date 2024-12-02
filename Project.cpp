#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


Player *myplayer;
GameMechs *game;
<<<<<<< HEAD
=======
objPos foodPos;
>>>>>>> 9e55b9ec949be747bb99164213970f68777f3f56

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
<<<<<<< HEAD
    game = new GameMechs(30,30);
    myplayer = new Player(game);
=======
    game = new GameMechs(20,10);
    myplayer = new Player(game); 
    game -> generateFood(myplayer -> getPlayerPos());
    
>>>>>>> 9e55b9ec949be747bb99164213970f68777f3f56
    
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
<<<<<<< HEAD
=======

    objPosArrayList* currentplayer = myplayer -> getPlayerPos();
    int playersize = currentplayer->getSize();
>>>>>>> 9e55b9ec949be747bb99164213970f68777f3f56

    objPos currentplayer = myplayer -> getPlayerPos();
    GameMechs gameMechsInstance(30, 15);
    
    
    MacUILib_clearScreen();    
    int i, k;
    int j;
    for (j = 0; j < game ->getBoardSizeY(); j++)
    {
        for(i = 0; i < game ->getBoardSizeX(); i++)
        {

                if (i == 0 || i == game ->getBoardSizeX() - 1)
                {
                    border.setObjPos(i,j,'#');
                    MacUILib_printf("%c", border.symbol);
                }

                else if ((j == 0 || j == game ->getBoardSizeY() - 1 ))
                {
                    border.setObjPos(i,j,'#');
                    MacUILib_printf("%c", border.symbol);  
                }


                else if (i == currentplayer.pos -> x && j == currentplayer.pos -> y)
                {
                    MacUILib_printf("%c", currentplayer.symbol);
                }

<<<<<<< HEAD
                else
                {
                    space.setObjPos(i, j, ' ');
                    MacUILib_printf("%c", space.symbol); 
                }
=======
                    else
                    {
                        space.setObjPos(i, j, ' ');
                        MacUILib_printf("%c", space.symbol); 
                    }
            }

>>>>>>> 9e55b9ec949be747bb99164213970f68777f3f56
        
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
    if (game -> getLoseFlagStatus() == true)
    {
        MacUILib_printf("GAME OVER!");
    }

    else
    {
        MacUILib_printf("I'll see you next time!");
    }
    delete myplayer;
    delete game;
    MacUILib_uninit();
}
