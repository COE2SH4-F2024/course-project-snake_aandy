#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodBucket = new objPosArrayList();
}


Food::~Food()
{
    delete foodBucket;
}


void Food::generateFood(objPosArrayList* blockOff)
{
    int i = 0, x = 0, y = 0;
    int xSize = mainGameMechsRef->getBoardSizeX() - 2;
    int ySize = mainGameMechsRef->getBoardSizeY() - 2;

    while (foodBucket->getSize() > 0)
        foodBucket->removeTail();

    while (i < 3)
    {
        x = rand() % xSize + 1;
        y = rand() % ySize + 1;

        bool overlapsWithBlocked = false;
        for (int j = 0; j < blockOff->getSize(); j++)
        {
            objPos bodyPart = blockOff->getElement(j);
            if (bodyPart.pos->x == x && bodyPart.pos->y == y)
            {
                overlapsWithBlocked = true;
                break;
            }
        }

        bool overlapsWithFood = false;
        for (int j = 0; j < i; j++)
        {
            objPos foodPos = foodBucket->getElement(j);
            if (foodPos.pos->x == x && foodPos.pos->y == y)
            {
                overlapsWithFood = true;
                break;
            }
        }

        if (!overlapsWithBlocked && !overlapsWithFood)
        {
            foodBucket->insertTail(objPos(x, y, '@')); 
            i++;
        }
    }
}

objPosArrayList* Food::getFoodPos() const
{
    return foodBucket;
}
