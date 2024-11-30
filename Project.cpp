#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000


Player *myplayer;
GameMechs *game;
Food* food = nullptr;

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
    game = new GameMechs(30,30);
    myplayer = new Player(game, food);
    food = new Food(game);

    food->generateFood(&myplayer->getPlayerPos()); 
    
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
    delete food;
    food = nullptr;
    MacUILib_uninit();
}