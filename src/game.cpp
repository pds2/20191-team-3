#include <iostream>
#include <time.h>  
#include <map>
#include "game.h"

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

bool CRolePlayingGame::LocateCreature(unsigned int& uirRow, unsigned int& uirCol, Personagem* qpCreature)
{
    for (unsigned int uiRow = 0; uiRow < 10; ++uiRow) {
        for (unsigned int uiCol = 0; uiCol < 10; ++uiCol) {
            if (mqpaaCreatures[uiRow][uiCol] == qpCreature) {
                uirRow = uiRow;
                uirCol = uiCol;
                return true;
            }
        }
    }
    return false;
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

    

    map.set_ocupacao_terreno(uiHeroRow, uiHeroCol, 0);
    map.toggle_ocupado(uiHeroRow, uiHeroCol, false);

    map.set_ocupacao_terreno(uiNextRow, uiNextCol, 1);
    map.toggle_ocupado(uiHeroRow, uiHeroCol, true);
}

void CRolePlayingGame::printboard()
{
    for (unsigned int uiRow = 0; uiRow < (unsigned)map.get_num_linhas(); ++uiRow) {
        for (unsigned int uiCol = 0; uiCol < (unsigned)map.get_num_colunas(); ++uiCol) {
            int tipoOcupacao = QueryLocation(uiRow, uiCol);
            if(tipoOcupacao == 0){
                cout << "*" << endl;
            }
            else if(tipoOcupacao == 1){
                cout << map.getPersonagemPorPosicao(uiRow, uiCol)->get_nome().substr(1) << endl;
            }
            else {
                cout << "M" << endl;
            }
        }
        cout << endl;
    }
}

bool CRolePlayingGame::HeroIsDead(int numPersonagem) { 
    return mqHero[numPersonagem].IsDead();
}

bool CRolePlayingGame::AllMonstersDead()
{
    bool bAllDead = true;
    for (unsigned int uiIndex = 0; uiIndex < 10; ++uiIndex) {
        if(!mqaMonsters[uiIndex].IsDead()) 
            bAllDead = false; 
    }
    return bAllDead;
}

bool CRolePlayingGame::AllHeroesisDead()
{
    bool bAllDead = true;
    for (unsigned int uiIndex = 0; uiIndex < 5; ++uiIndex) {
        if(!mqHero[uiIndex].IsDead()) 
            bAllDead = false; 
    }
    return bAllDead;
}


void CRolePlayingGame::RemoveDeadHeroes()
{
    for (unsigned int uiIndex = 0; uiIndex < 5; ++uiIndex) {
        if (mqHero[uiIndex].IsDead()) {
            unsigned int uiRow;
            unsigned int uiCol;
            if (LocateCreature(uiRow, uiCol, &(mqHero[uiIndex]))) {
                mqpaaCreatures[uiRow][uiCol] = 0;
                std::cout << "Heroi morreu ! " << std::endl;
            }
        }
    }
}

void CRolePlayingGame::RemoveDeadMonsters()
{
    for (unsigned int uiIndex = 0; uiIndex < 10; ++uiIndex) {
        if (mqaMonsters[uiIndex].IsDead()) {
            unsigned int uiRow;
            unsigned int uiCol;
            if (LocateCreature(uiRow, uiCol, &(mqaMonsters[uiIndex]))) {
                mqpaaCreatures[uiRow][uiCol] = 0;
                std::cout << "Monstro morreu ! " << std::endl;
            }
        }
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