#include <iostream>
#include <time.h> 
#include <vector>

#include "mapa.h"
#include "personagem.h"
#include "terreno.h"

/*Esta classe controla o movimento do seu herói. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 5 monstros e seu herói dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

class CRolePlayingGame
{
    private:
        // Compara na matriz de objetos o objeto passado instaciado que pode ser monstro, heroi ou mapa
        bool LocateCreature(unsigned int& uirRow, unsigned int& uirCol, Personagem* qpCreature);
        Mapa map = Mapa("mapa_ch12.txt"); //Um um objeto da classe Mapa para construir o mapa
    public:
        CRolePlayingGame();   
        int QueryLocation(unsigned int uiRow, unsigned int uiCol); // Retorna na matriz de terrenos o tipo de ocupação da posição desejada
        bool MoveHero(char const kcDirection, int numPersonagem); // Move o personagem no mapa respeitando as condições
        void printboard(); // Printa os valores retonado por QueryLocation() 
        bool HeroIsDead(int numPersonagem); // Verifica se os hit-points  do heroi acabaram 
        void RemoveDeadMonsters(); // Remove Monstro da matriz de objetos quando o mesmo e derrotado
        void RemoveDeadHeroes(); // Remove Herois da matriz de objetos quando o mesmo e derrotado
        bool AllMonstersDead(); // Verifica se todos os monstros ja foram derrotados 
        bool AllHeroesisDead();
        bool TerrenoComparator(Terreno &terreno1, Terreno &terreno2); // Compara as classes terreno para ver se estao ocupadas
};
