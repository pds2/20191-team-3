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
        int cPersonagem;
        cout << "Escolha o personagem para mover ou 0 para sair"  << endl;
        std::cin >> cPersonagem;
        while(cPersonagem != 0){
            cout << " Use W, A , S ou D para mover : " << endl;
            std::cin >> cMove; 
            if (qGame.MoveHero(cMove, cPersonagem)) { //Verifica se o movimento é valido e a iteração do personagem com monstro perto dele
                if (qGame.HeroIsDead(cPersonagem)) { //Se o herói é morto
                    cout << " Você morreu! " << endl;
                    qGame.RemoveDeadHeroes();
                    if (qGame.AllHeroesisDead()) { //Se todos os monstros são eliminados
                        cout << "Você Perdeu! " << endl;
                        bGameOver = true;
                    }
                }
                else { 
                    qGame.RemoveDeadMonsters(); //Limpa os Monstros eliminados do game
                    if (qGame.AllMonstersDead()) { //Se todos os monstros são eliminados
                        cout << "Você Venceu! " << endl;
                        bGameOver = true;
                    }
                }
            }
        }
    } while (!bGameOver);
    return 0;
}
