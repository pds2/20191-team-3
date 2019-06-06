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
    map.cria_lista_personagens();
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

bool CRolePlayingGame::MoveHero(char const kcDirection, int numPersonagem)
{
    int num_linhas = map.get_num_linhas();
    int num_colunas = map.get_num_colunas();
    unsigned int uiHeroRow;
    unsigned int uiHeroCol;
    LocateCreature(uiHeroRow, uiHeroCol, &mqHero[numPersonagem]);
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
    
    //Faz as iterações do personagem dependendo das instancias do mapa
    Terreno TerraVazia;
    TerraVazia.set_tipo_ocupacao(0);
    Terreno TerraOcupadaM;
    TerraOcupadaM.set_tipo_ocupacao(2);
    Terreno cNextLoc = QueryLocation(uiNextRow, uiNextCol);
    if (TerrenoComparator(cNextLoc,TerraVazia)) {
        mqpaaCreatures[uiNextRow][uiNextCol] = &mqHero[numPersonagem];
        mqpaaCreatures[uiHeroRow][uiHeroCol] = 0;
        return true;
    }
    else if (TerrenoComparator(cNextLoc,TerraOcupadaM)) {
        mqHero[numPersonagem].Ataque(*mqpaaCreatures[uiNextRow][uiNextCol]);
        return true;
    }

    return false;
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

