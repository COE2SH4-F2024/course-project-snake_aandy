#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

class Food {
private:
    objPosArrayList* foodBucket;   
    GameMechs* mainGameMechsRef;   

public:
    explicit Food(GameMechs* gameMechsRef);

    ~Food();

    void generateFood(objPosArrayList* blockOff);

    objPosArrayList* getFoodPos() const;
};

#endif
