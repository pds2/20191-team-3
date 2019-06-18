#include <iostream>
#include <time.h>  
#include <map>
#include "game.h"
#include "color.h"

using namespace std;

/*Esta classe controla o movimento dos seu heróis. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 10 monstros e seu heróis dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

CRolePlayingGame::CRolePlayingGame()
{
	//Seta jogo para jogando
    gameOver = false;
    //Cria os personagens e setam eles em uma posicao aleatoria no mapa
    this->map = Mapa("mapa_ch12.txt");
}   

int CRolePlayingGame::QueryLocation(unsigned int uiRow, unsigned int uiCol)
{
    return map.GetMazeSquare(uiRow, uiCol).get_tipo_ocupado();
}

void CRolePlayingGame::printboard(int _i, int _j)
{
    // for(unsigned int uiRow = 0; uiRow < (unsigned)map.get_num_linhas(); ++uiRow){
    //     for(unsigned int uiCol = 0; uiCol < (unsigned)map.get_num_colunas(); ++uiCol){
    //         QueryLocation(uiRow, uiCol);
    //     }
    //     cout<<endl;
    // }
    for (unsigned int uiRow = 0; uiRow < (unsigned)map.get_num_linhas(); ++uiRow) {
        for (unsigned int uiCol = 0; uiCol < (unsigned)map.get_num_colunas(); ++uiCol) {
            int tipoOcupacao = QueryLocation(uiRow, uiCol);
            if(tipoOcupacao == 0){
                cout << cor.greenPrint("*");
            }
            else if(tipoOcupacao == 1){
                if(uiRow == (unsigned)_i && uiCol == (unsigned)_j){
                    cout << cor.BbluePrint(map.getHeroiPorPosicao(uiRow, uiCol)->get_nome().substr(0,1));
                }else{
                    cout << cor.bluePrint(map.getHeroiPorPosicao(uiRow, uiCol)->get_nome().substr(0,1));
                }
                
            }
            else if(tipoOcupacao == 2){
                cout << cor.redPrint("M");
            }
        }
        cout << endl;
    }
}

void CRolePlayingGame::AllMonstersDead()
{
    if(map.get_lista_personagens(false).size() == 0){
        std::cout << "Você Venceu! " << std::endl;
        this->gameOver = true;
    }
}

void CRolePlayingGame::AllHeroesisDead()
{
    if(map.get_lista_personagens(true).size() == 0){
        std::cout << "Você Perdeu! " << std::endl;
        this->gameOver = true;
    }
}

bool CRolePlayingGame::TerrenoComparator(Terreno &terreno1, Terreno &terreno2) {
    if (terreno1.get_tipo_ocupado() == terreno2.get_tipo_ocupado())
        return true;
    return false;
}

Mapa CRolePlayingGame::getMapa() {
    return this->map;
}