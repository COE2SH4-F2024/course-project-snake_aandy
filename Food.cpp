#include "Food.h"
#include <cstdlib> 

Food::Food(GameMechs* gameMechsRef) {
    mainGameMechsRef = gameMechsRef;
    generateFood(nullptr); 
}

void Food::generateFood(objPos* playerPos) {
    int xSize = mainGameMechsRef->getBoardSizeX() - 2; 
    int ySize = mainGameMechsRef->getBoardSizeY() - 2; 

    while (true) {
        int x = rand() % xSize + 1; 
        int y = rand() % ySize + 1; 

        if (playerPos == nullptr || (x != playerPos->pos->x || y != playerPos->pos->y)) {
            foodPos.setObjPos(x, y, '@'); 
            break; 
        }
    }
}

objPos Food::getFoodPos() const {
    return foodPos; 
}
