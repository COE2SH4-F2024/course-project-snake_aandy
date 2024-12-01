#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    myDir = STOP;

    objPos headPos(mainGameMechsRef -> getBoardSizeX() / 2, mainGameMechsRef -> getBoardSizeY() / 2, '*');
    // objPos test1(11,5,'*');
    // objPos test2(12,5,'*');
    // playerPos.pos -> x = mainGameMechsRef -> getBoardSizeX() / 2;
    // playerPos.pos -> y = mainGameMechsRef -> getBoardSizeY() / 2;
    // playerPos.symbol = '*';
    playerPosList->insertHead(headPos);
    // playerPosList -> insertTail(test1);
    // playerPosList -> insertTail(test2);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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

    objPos temp = playerPosList -> getHeadElement();
    switch(myDir)
    {
        
        case STOP:
        default:
            temp.pos -> x = mainGameMechsRef -> getBoardSizeX()/2;
            temp.pos -> y = mainGameMechsRef -> getBoardSizeY()/2;
            break;


        case UP:
            temp.pos -> y--;
            if (temp.pos -> y <= 0)
            {
                temp.pos -> y = mainGameMechsRef -> getBoardSizeY() - 2 ;
            }
            break;

        case DOWN:
            temp.pos -> y++;
            if (temp.pos -> y >= mainGameMechsRef -> getBoardSizeY() - 1)
            {
                temp.pos -> y = 1;
            }
            break; 
            

        case RIGHT:
            temp.pos -> x++;
            if (temp.pos -> x >= mainGameMechsRef -> getBoardSizeX() - 1)
            {
                temp.pos -> x = 1;
            }
            break;

        case LEFT:
            temp.pos -> x--;
            if (temp.pos -> x <= 0)
            {
                temp.pos -> x = mainGameMechsRef -> getBoardSizeX() - 2;
            }
            break;    
            
    }


    if (myDir != STOP)
    {
        for (int k = 0; k < playerPosList ->getSize(); k++)
        {
            objPos reference = playerPosList -> getElement(k);
            objPos* referenceptr = &reference;
            if (temp.isPosEqual(referenceptr))
            {
                mainGameMechsRef -> setExitTrue();
                mainGameMechsRef -> setLoseFlag();
                break;
                
            }
        }
        if (mainGameMechsRef -> getLoseFlagStatus() == false)
        {

        
            objPos food = (mainGameMechsRef -> getFoodPos());
            objPos *foods = &food;
            if (!temp.isPosEqual(foods))
            {   
                playerPosList -> insertHead(temp);
                playerPosList -> removeTail();
            }

            else
            {
                playerPosList -> insertHead(temp);
                mainGameMechsRef -> generateFood(playerPosList);
                mainGameMechsRef -> incrementScore();
            }
        }

    }
   
        

}

// More methods to be added