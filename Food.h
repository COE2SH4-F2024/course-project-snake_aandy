#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

class Food {
private:
    objPos foodPos;                
    GameMechs* mainGameMechsRef;   

public:
    explicit Food(GameMechs* gameMechsRef);
    void generateFood(objPos* playerPos); 
    objPos getFoodPos() const;            
};

#endif
