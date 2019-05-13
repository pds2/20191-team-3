#include <iostream>

#include "game.h"
#include "creature.h"
#include "mapa.h"
/* Criar o programa principal que chama as várias classes 
e funções e interage com o utilizador . Você pode controlar vários aspectos de seu jogo 
a partir deste programa . Use este código para criá-lo  */

using namespace std;  //Limpar o dungeon

int main()
{
    CRolePlayingGame qGame;
    bool bGameOver = false;
    do {
        qGame.printboard(); //Pega o próximo e move
        char cMove;
        cout << " Use W, A , S ou Z para mover : " << endl;
        std::cin >> cMove; //Verifique se o movimento é valido
        if (qGame.MoveHero(cMove)) { //Se o herói é morto
            if (qGame.HeroIsDead()) {
                cout << " Você morreu! " << endl;
                bGameOver = true;
            }
            else { //remover os monstros mortos do game
                qGame.RemoveDeadMonsters(); //Se todos os monstros são mortos
                if (qGame.AllMonstersDead()) {
                    cout << "Dungeon Cancelado ! " << endl;
                    bGameOver = true;
                }
            }
        }
    } while (!bGameOver);
    return 0;
}