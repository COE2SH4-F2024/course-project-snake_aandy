#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* thisFDRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.pos -> x = mainGameMechsRef -> getBoardSizeX() / 2;
    playerPos.pos -> y = mainGameMechsRef -> getBoardSizeY() / 2;
    playerPos.symbol = '*';

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
    char input = mainGameMechsRef -> getInput();

    switch(input)        
    {
        case ' ':
                mainGameMechsRef -> setExitTrue();
                break;

        case 'w':
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;

        case 'a':
            if (myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;

        case 's':
            if (myDir != UP)
            {
                myDir = DOWN;
            }
            break;

        case 'd':
            if (myDir != LEFT)
            {
                myDir = RIGHT;
            }
            break;

        default:
            break;
}
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        
        case STOP:
        default:
            playerPos.pos -> x = mainGameMechsRef -> getBoardSizeX()/2;
            playerPos.pos -> y = mainGameMechsRef -> getBoardSizeY()/2;
            break;


        case UP:
            playerPos.pos -> y--;
            if (playerPos.pos -> y <= 0)
            {
                playerPos.pos -> y = mainGameMechsRef -> getBoardSizeY() - 2 ;
            }
            break;

        case DOWN:
            playerPos.pos -> y++;
            if (playerPos.pos -> y >= mainGameMechsRef -> getBoardSizeY() - 1)
            {
                playerPos.pos -> y = 1;
            }
            break;
            

        case RIGHT:
            playerPos.pos -> x++;
            if (playerPos.pos -> x >= mainGameMechsRef -> getBoardSizeX() - 1)
            {
                playerPos.pos -> x = 1;
            }
            break;

        case LEFT:
            playerPos.pos -> x--;
            if (playerPos.pos -> x <= 0)
            {
                playerPos.pos -> x = mainGameMechsRef -> getBoardSizeX() - 2;
            }
            break;

        
            
    }
}

// More methods to be added