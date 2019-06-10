#include <iostream>
#include <time.h> 
#include <vector>

#include "mapa.h"
#include "personagem.h"
#include "terreno.h"
#include "color.h"
#include <exception>

/*Esta classe controla o movimento do seu herói. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 5 monstros e seu herói dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

class CRolePlayingGame
{
    private:
        Color cor;
        Mapa map; //Um um objeto da classe Mapa para construir o mapa
    public:
        bool gameOver;
        CRolePlayingGame();   
        int QueryLocation(unsigned int uiRow, unsigned int uiCol); // Retorna na matriz de terrenos o tipo de ocupação da posição desejada
        bool MoveHero(char const kcDirection, string numPersonagem); // Move o personagem no mapa respeitando as condições
        void printboard(); // Printa os valores retonado por QueryLocation() 
        void AllMonstersDead(); // Verifica se todos os monstros ja foram derrotados 
        void AllHeroesisDead();
        bool TerrenoComparator(Terreno &terreno1, Terreno &terreno2); // Compara as classes terreno para ver se estao ocupadas
        Mapa getMapa();
};
