#include <iostream>

#include "game.h"
#include "color.h"
#include "heroi.h"

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
    
    do {
        map<string, Heroi*> listaPersonagens = qGame.get_lista_herois();
        for (std::map<string, Heroi*>::iterator it = listaPersonagens.begin(); it != listaPersonagens.end(); it++){
            int qtdMovimentos = it->second->get_Move();
            for (int i = qtdMovimentos; i > 0; i--) {
                char cMove = ' ';
                do{
                    cout << " Use W, A , S ou D para mover o personagem " + it->first + ": " << endl;
                    cout <<" "<< i <<" movimentos restantes!\n"; // Pega a entrada do usuário
                    qGame.printboard(it->second->get_i(), it->second->get_j()); //Printa o mapa na tela
                    std::cin >> cMove; 
                                            
                }while(cMove != 'w' && cMove != 'a' && cMove != 's' && cMove != 'd' && cMove != 'i');
                if (cMove == 'i' || cMove == 'I') {
                    it->second->imprime_status();
                    i++;
                }
                else {
                    int linhaDestino = it->second->get_i();
                    int colunaDestino = it->second->get_j();
                    qGame.AtualizarDestinoMovimentacao(linhaDestino, colunaDestino, cMove);
                    int validacaoMovimentacao = qGame.getMapa().ValidarMovimentacao(linhaDestino, colunaDestino);
                    if (validacaoMovimentacao == 0) {
                        qGame.RealizarMovimentacao(it->first, linhaDestino, colunaDestino);
                    }
                    else if (validacaoMovimentacao == 2) {
                        qGame.Batalha(it->first, linhaDestino, colunaDestino);
                        qGame.AllHeroesisDead(); //Se todos os Heróis forem eliminados -> Game Over
                        qGame.AllMonstersDead(); //Se todos os Monstros forem eliminados -> Win
                        if (qGame.gameOver==1)
                            break;
                    }
                    else {
                        //tratar exceções (movimento inválido)
                    }
                }
            }
        }
        qGame.MovimentarMonstros();
    } while (!qGame.gameOver);
    return 0;
}