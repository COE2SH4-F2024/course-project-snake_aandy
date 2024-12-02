#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10;

    food.setObjPos(-10,-10, 'o');

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

    food.setObjPos(-10,-10, 'o');
}

GameMechs::~GameMechs() {
    
}
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

int GameMechs::getScore() const 
{
    return score;
}

void GameMechs::incrementScore() 
{
    score++;
}

int GameMechs::getBoardSizeX() const 
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const 
{
    return boardSizeY;
}

void GameMechs::generateFood(objPosArrayList* blockOff)
{
    srand(time(NULL));

    int candidate = 0;
    int count = 0;

    int vector_x[boardSizeX - 1] = {0};

    int i;

    for (i = 0; i < boardSizeX - 1; i++)
    {

        for (int k = 0; k < blockOff -> getSize(); k++)
        {
            if (i == (blockOff -> getElement(k)).pos -> x)
            {
                vector_x[i]+=2;
            }
        }
        if (i == 0)
        {
            vector_x[i]+=2;
        }
    }

    while (count < 1)
    {
        candidate = rand() % (boardSizeX - 1);

        if (vector_x[candidate] == 0)
        {
            vector_x[candidate]++;
            count++;

        }
    }

    for (i = 0; i < boardSizeX - 1; i++)
    {
        if (vector_x[i] == 1)
        {
            food.pos -> x = i;
        }
    }



    
    candidate = 0;
    count = 0;
    i = 0;
    int vector_y[boardSizeY - 1] = {0};
    for (i = 0; i < boardSizeY - 1; i++)
    {
        for (int k = 0; k < blockOff -> getSize(); k++)
        {
            if (i == (blockOff -> getElement(k)).pos -> y)
            {
                vector_y[i]+=2;
            }
        }
        if (i == 0)
        {
            vector_y[i]+=2;
        }
    }

    while (count < 1)
    {
        candidate = rand() % (boardSizeY - 1);

        if (vector_y[candidate] == 0)
        {
            vector_y[candidate]++;
            count++;

        }
    }
 
    for (i = 0; i < boardSizeY - 1; i++)
    {
        if (vector_y[i] == 1)
        {
            food.pos -> y = i;
        }
    }

    

}


objPos GameMechs::getFoodPos() const
{
    return food;
}

// More methods should be added here
