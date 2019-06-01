#include <iostream>
#include <time.h>  
#include "mapa.h"
#include "creature.h"

/*Esta classe controla o movimento do seu herói. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 10 monstros e seu herói dentro de sua " masmorra " e controla as interações 
entre eles , como mortes e posições.*/

class CRolePlayingGame
{
     private:
        bool LocateCreature(unsigned int& uirRow, unsigned int& uirCol, CCreature* qpCreature);
        CDungeon mqDungeon;
        CCreature mqHero;
        CCreature mqaMonsters[10];
        CCreature* mqpaaCreatures[10][10];
    public:
        CRolePlayingGame();   
        char QueryLocation(unsigned int uiRow, unsigned int uiCol);
        bool MoveHero(char const kcDirection);
        void printboard();
        bool HeroIsDead();
        void RemoveDeadMonsters();
        bool AllMonstersDead();
    };
