#include <iostream>

#include "game.h"
#include "color.h"

/* Cria o programa principal que chama as várias classes 
e funções e interage com o utilizador . Aqui controla vários aspectos do jogo */

using namespace std;  //Limpar o dungeon

int main()
{
    
    Color corM;
    cout << corM.redPrint("***FIRE EMBLEM***") << endl;
    // Cria um objeto do jogo 
    CRolePlayingGame qGame;
    
    // Cria uma variavel de iteração se o jogo acaba ou não
    bool bGameOver = false;
    do {
        map<string, Personagem*> listaPersonagens = qGame.getMapa().get_lista_personagens(true);
        for (std::map<string, Personagem*>::iterator it = listaPersonagens.begin(); it != listaPersonagens.end(); it++){
            int qtdMovimentos = it->second->get_Move();
            for (int i = 0; i < qtdMovimentos; i++) {
                qGame.printboard(); //Printa o mapa na tela
                cout << " Use W, A , S ou D para mover o personagem " + it->first + ": " << endl;
                // Pega a entrada do usuário
                char cMove;
                std::cin >> cMove; 
                if (qGame.MoveHero(cMove, it->first)) { //Verifica se o movimento é valido e a iteração do personagem com monstro perto dele
                    qGame.AllHeroesisDead(); //Se todos os Heróis forem eliminados -> Game Over
                    
                    qGame.AllMonstersDead(); //Se todos os Monstros forem eliminados -> Win
                }
            }
        }
    } while (!qGame.gameOver);
    return 0;
}