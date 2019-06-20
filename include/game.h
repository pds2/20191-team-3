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

/*Esta classe é a Engine do game contém os metodos para funcionamento do game.*/

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
        void AllMonstersDead(); // Verifica se todos os monstros ja foram derrotados 
        void AllHeroesisDead();
        Mapa getMapa();
	    std::map<string, Heroi*> get_lista_herois();
        std::map<string, Monstro*> get_lista_monstros();
        Heroi *getHeroiPorPosicao(int x, int y);
        Monstro *getMonstroPorPosicao(int x, int y);
        void printboard(int _i, int _j);
        // MOVIMENTAÇÃO
        void AtualizarDestinoMovimentacao(int &uiNextRow, int &uiNextCol, char kcDirection);
        void RealizarMovimentacao(string nomeHeroi, int x, int y);
        bool Batalha(string nomeHeroi, int x, int y);
        void MovimentarMonstros();
        void MoveInv();
        
        // ITEM
        void AddArmasPersonagem(Heroi &p);
        void AddArmasPersonagem(Monstro &p);
};
