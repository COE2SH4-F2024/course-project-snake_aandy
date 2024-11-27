#include "Player.h"


Player::Player(GameMechs* thisGMRef)
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

    // switch(input)        
    // {
    //     case 'w':
    //             if (myDir != DOWN)
    //             {
    //                 myDir = UP;
    //             }
    //             break;

    //         case 'a':
    //             if (myDir != RIGHT)
    //             {
    //                 myDir = LEFT;
    //             }
    //             break;

    //         case 's':
    //             if (myDir != UP)
    //             {
    //                 myDir = DOWN;
    //             }
    //             break;

    //         case 'd':
    //             if (myDir != LEFT)
    //             {
    //                 myDir = RIGHT;
    //             }
    //             break;

    //         default:
    //             break;
}


void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added