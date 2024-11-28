#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
    : input(0), exitFlag(false), loseFlag(false), score(0), boardSizeX(30), boardSizeY(15), food()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 20;
    boardSizeY = 10;

}

GameMechs::GameMechs(int boardX, int boardY)
    
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

bool GameMechs::getExitFlagStatus() const 
{
    return exitFlag;
}

void GameMechs::setExitTrue() 
{
    exitFlag = true;
}

bool GameMechs::getLoseFlagStatus() const 
{
    return loseFlag;
}

void GameMechs::setLoseFlag() 
{
    loseFlag = true;
}

char GameMechs::getInput()  
{
    return input;
}

void GameMechs::setInput(char this_input) 
{
    input = this_input;
}

void GameMechs::clearInput() 
{
    input = 0; 
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

// More methods should be added here