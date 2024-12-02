#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000


Player *myplayer;
GameMechs *game;
objPos foodPos;

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
    game = new GameMechs(20,10);
    myplayer = new Player(game); 
    game -> generateFood(myplayer -> getPlayerPos());
    
    
}

void GetInput(void)
{
   
    

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

    objPosArrayList* currentplayer = myplayer -> getPlayerPos();
    int playersize = currentplayer->getSize();

    
    
    MacUILib_clearScreen();    
    int i, k;
    int j;
    int boardX = game ->getBoardSizeX();
    int boardY = game ->getBoardSizeY();
    foodPos = game -> getFoodPos();
    bool proceed;
    

    for (j = 0; j < boardY; j++)
    {
        for(i = 0; i < boardX; i++)
        {
            proceed = true;

            for (k = 0; k < playersize; k++)
            {
                objPos thisseg = currentplayer -> getElement(k);

                if (i == thisseg.pos -> x && j == thisseg.pos -> y )
                {
                    MacUILib_printf("%c", thisseg.symbol);
                    proceed = false;

                }
            }

            if (proceed == true)
            {
                    if (i == 0 || i == boardX - 1)
                    {
                        border.setObjPos(i,j,'#');
                        MacUILib_printf("%c", border.symbol);
                    }

                    else if ((j == 0 || j == boardY - 1 ))
                    {
                        border.setObjPos(i,j,'#');
                        MacUILib_printf("%c", border.symbol);  
                    }

                    else if (i == foodPos.pos -> x && j == foodPos.pos -> y)
                    {
                        MacUILib_printf("%c", foodPos.symbol);
                    }


                    // else if (i == currentplayer.pos -> x && j == currentplayer.pos -> y)
                    // {
                    //     MacUILib_printf("%c", currentplayer.symbol);
                    // }

                    else
                    {
                        space.setObjPos(i, j, ' ');
                        MacUILib_printf("%c", space.symbol); 
                    }
            }

        
        }
        printf("\n");

        
        }
        MacUILib_printf("\nCurrent key pressed = %c", game -> getInput());
        MacUILib_printf("\nScore: %d", game -> getScore());
        
    

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
