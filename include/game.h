#include <iostream>
#include <time.h> 
#include <vector>
#include <map>
#include <string>

#include "mapa.h"
#include "personagem.h"
#include "heroi.h"
#include "terreno.h"
#include "monstro.h"
#include "color.h"
#include <exception>

/*Esta classe controla o movimento do seu herói. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 5 monstros e seu herói dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

class CRolePlayingGame
{
    private:
        Mapa map; //Um um objeto da classe Mapa para construir o mapa
        Color cor;
        std::map<string, Heroi *> _lista_herois;
        std::map<string, Monstro *> _lista_monstros;
        void CriarListaHerois(bool heroi);
    public:
        bool gameOver;
        CRolePlayingGame();   
        //int QueryLocation(unsigned int uiRow, unsigned int uiCol); // Retorna na matriz de terrenos o tipo de ocupação da posição desejada
        //void printboard(int _i, int _j); // Printa os valores retonado por QueryLocation() 
        void AllMonstersDead(); // Verifica se todos os monstros ja foram derrotados 
        void AllHeroesisDead();
       // bool TerrenoComparator(Terreno &terreno1, Terreno &terreno2); // Compara as classes terreno para ver se estao ocupadas
        Mapa getMapa();
	    std::map<string, Heroi*> get_lista_herois();
        std::map<string, Monstro*> get_lista_monstros();
        Heroi *getHeroiPorPosicao(int x, int y);
        Monstro *getMonstroPorPosicao(int x, int y);
        void printboard(int _i, int _j);
        void AtualizarDestinoMovimentacao(int &uiNextRow, int &uiNextCol, char kcDirection);
        void RealizarMovimentacao(string nomeHeroi, int x, int y);
        bool Batalha(string nomeHeroi, int x, int y);
        void MovimentarMonstros();
};
