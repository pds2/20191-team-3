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
    //Cria os personagens e setam eles em uma posicao aleatoria no mapa
    this->map = Mapa("mapa_ch12.txt");
}   

int CRolePlayingGame::QueryLocation(unsigned int uiRow, unsigned int uiCol)
{
    return map.GetMazeSquare(uiRow, uiCol).get_tipo_ocupado();
}

bool CRolePlayingGame::MoveHero(char const kcDirection, string nomePersonagem)
{
    int num_linhas = map.get_num_linhas();
    int num_colunas = map.get_num_colunas();
    Personagem personagem = map.get_personagem(nomePersonagem);
    unsigned int uiHeroRow = personagem.get_i();
    unsigned int uiHeroCol = personagem.get_j();
    unsigned int uiNextRow = uiHeroRow;
    unsigned int uiNextCol = uiHeroCol;
    switch (kcDirection) {
        case 'w':
        case 'W': {
            --uiNextRow;
            break;
        }
        case 'd':
        case 'D': {
            ++uiNextCol;
            break;
        }
        case 's':
        case 'S': {
            ++uiNextRow;
            break;
        }
        case 'a':
        case 'A': {
            --uiNextCol;
            break;
        }
        default: {
            return false;
        }
    }
    
    // Trata o tamanho do mapa diponivel
    if ((unsigned)uiNextRow > (unsigned)num_linhas || (unsigned)uiNextCol > (unsigned)num_colunas)
        return false;

    int tipoOcupacao = map.GetMazeSquare(uiNextRow, uiNextRow).get_tipo_ocupado();
    if (tipoOcupacao == 0) { //terreno destino vazio
        //esvazia o terreno atual
        map.set_ocupacao_terreno(uiHeroRow, uiHeroCol, 0);
        map.toggle_ocupado(uiHeroRow, uiHeroCol, false);

        //preenche o novo terreno
        map.set_ocupacao_terreno(uiNextRow, uiNextCol, 1);
        map.toggle_ocupado(uiHeroRow, uiHeroCol, true);

        //setando personagem na posição correta
    }
    else if (tipoOcupacao == 1) {
        throw runtime_error("Movimento inválido.");
    }
    else {
        //TODO: Chamar método de batalha
    }
}

void CRolePlayingGame::printboard()
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
                cout << cor.bluePrint(map.getPersonagemPorPosicao(uiRow, uiCol)->get_nome().substr(0,1));
            }
            else {
                cout << cor.redPrint("M");
            }
        }
        cout << endl;
    }
}

bool CRolePlayingGame::AllMonstersDead()
{
    return map.get_lista_personagens(false).size() == 0;
}

bool CRolePlayingGame::AllHeroesisDead()
{
    return map.get_lista_personagens(true).size() == 0;
}

bool CRolePlayingGame::TerrenoComparator(Terreno &terreno1, Terreno &terreno2) {
    if (terreno1.get_tipo_ocupado() == terreno2.get_tipo_ocupado())
        return true;
    return false;
}

Mapa CRolePlayingGame::getMapa() {
    return this->map;
}