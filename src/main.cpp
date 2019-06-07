#include <iostream>

#include "game.h"

/* Cria o programa principal que chama as várias classes 
e funções e interage com o utilizador . Aqui controla vários aspectos do jogo */

using namespace std;  //Limpar o dungeon

int main()
{
    // Cria um objeto do jogo 
    CRolePlayingGame qGame;
    // Cria uma variavel de iteração se o jogo acaba ou não
    bool bGameOver = false;
    do {
        qGame.printboard(); //Printa o mapa na tela
        // Pega a entrada do usuário
        char cMove;
        map<string, Personagem*> listaPersonagens = qGame.getMapa().get_lista_personagens(true);
        for (std::map<string, Personagem*>::iterator it = listaPersonagens.begin(); it != listaPersonagens.end(); it++){
            int qtdMovimentos = it->second->get_Move();
            for (int i = 0; i < qtdMovimentos; i++) {
                cout << " Use W, A , S ou D para mover : " << endl;
                std::cin >> cMove; 
                if (qGame.MoveHero(cMove, it->first)) { //Verifica se o movimento é valido e a iteração do personagem com monstro perto dele
                    if (qGame.AllHeroesisDead()) { //Se todos os monstros são eliminados
                        cout << "Você Perdeu! " << endl;
                        bGameOver = true;
                    }
                    else if (qGame.AllMonstersDead()) { 
                        cout << "Você Venceu! " << endl;
                        bGameOver = true;
                    }
                }
            }
        }
    } while (!bGameOver);
    return 0;
}