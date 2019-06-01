#include <iostream>
#include <time.h>  
#include "mapa.h"
#include "creature.h"

/*Esta classe controla o movimento do seu herói. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 5 monstros e seu herói dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

class CRolePlayingGame
{
     private:
        // Compara na matriz de objetos o objeto passado instaciado que pode ser monstro, heroi ou mapa
        bool LocateCreature(unsigned int& uirRow, unsigned int& uirCol, CCreature* qpCreature);
        CDungeon mqDungeon; //Um um objeto da classe CDungeon para construir o mapa
        CCreature mqHero; // /Um objeto da classe CCreature para construir o heroi
        CCreature mqaMonsters[10]; // 10 objetos da classe CCreature para construir os monstros
        CCreature* mqpaaCreatures[11][11]; //Uma matriz de 11x11 para amarzenar a localização dos objetos no mapa
    public:
        CRolePlayingGame();   
        char QueryLocation(unsigned int uiRow, unsigned int uiCol); // Retorna na matriz de objetos o objeto instaciado que pode ser monstro, heroi ou mapa
        bool MoveHero(char const kcDirection); // Move o personagem no mapa respeitando as condições
        void printboard(); // Printa os valores retonado por QueryLocation() 
        bool HeroIsDead(); // Verifica se os hit-points  do heroi acabaram 
        void RemoveDeadMonsters(); // Remove Monstro da matriz de objetos quando o mesmo e derrotado
        bool AllMonstersDead(); // Verifica se todos os monstros ja foram derrotados 
};
