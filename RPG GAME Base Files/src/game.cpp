#include <iostream>
#include <time.h>  

#include "creature.h"
#include "mapa.h"
#include "game.h"

/*Esta classe controla o movimento do seu herói. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 5 monstros e seu herói dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

bool CRolePlayingGame::LocateCreature(unsigned int& uirRow, unsigned int& uirCol, CCreature* qpCreature)
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

CRolePlayingGame::CRolePlayingGame()
{ 
    //Inicializar o mapa de objetos inicialmente vazio
    for (unsigned int uiRow = 0; uiRow < 10; ++uiRow ) 
    {
        for (unsigned int uiCol = 0; uiCol < 10; ++uiCol) 
        { 
            mqpaaCreatures [ uiRow ] [ uiCol ] = 0 ;
        }
    }
    //Cria um heroi seta ele em uma posicao aleatoria no mapa 
    bool bFoundSpot = false; 
    while (!bFoundSpot) { 
        unsigned int uiRow = 1 + ( rand ()% 9); 
        unsigned int uiCol = 1 + ( rand ()% 9); 
        if ( QueryLocation ( uiRow , uiCol ) == '*') {
            bFoundSpot = true;
            mqpaaCreatures [ uiRow ] [ uiCol ] = &mqHero;
        }
    } 
    //Cria 5 Monstros e seta ele em posiçoes aleatorias no mapa 
    bFoundSpot = false;
    unsigned int uiMonster = 0;
    while (!bFoundSpot) {
        unsigned int uiRow = 1 + (rand() % 9);
        unsigned int uiCol = 1 + (rand() % 9);
        if (QueryLocation(uiRow, uiCol) == '*') {
            mqaMonsters[uiMonster] = CCreature();
            mqpaaCreatures[uiRow][uiCol] = &mqaMonsters[uiMonster];
            ++uiMonster;
            if (uiMonster == 5) {
                bFoundSpot = true;
            }
        }
    }
}   

char CRolePlayingGame::QueryLocation(unsigned int uiRow, unsigned int uiCol)
{
    for (unsigned int uIndex = 0; uIndex < 10; ++uIndex)
    {
        if (mqpaaCreatures[uiRow][uiCol] == &(mqaMonsters[uIndex])) {
            return 'M';
        }
    }
    if (mqpaaCreatures[uiRow][uiCol] == &mqHero) {
        return 'H';
    }
    else {
        return mqDungeon.GetMazeSquare(uiRow, uiCol);
    }
}

bool CRolePlayingGame::MoveHero(char const kcDirection)
{
    unsigned int uiHeroRow;
    unsigned int uiHeroCol;
    LocateCreature(uiHeroRow, uiHeroCol, &mqHero);
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
    // Trata o tamanho do mapa diponivel em 10x10
    if (uiNextRow > 10 || uiNextCol > 10)
        return false;
    
    //Faz as iterações do personagem dependendo das instancias do mapa
    char cNextLoc = QueryLocation(uiNextRow, uiNextCol);
    if (cNextLoc == '*') {
        mqpaaCreatures[uiNextRow][uiNextCol] = &mqHero;
        mqpaaCreatures[uiHeroRow][uiHeroCol] = 0;
        return true;
    }
    else if (cNextLoc == 'M') {
        mqHero.Ataque(*mqpaaCreatures[uiNextRow][uiNextCol]);
        return true;
    }

    return false;
}

void CRolePlayingGame::printboard()
{
    for (unsigned int uiRow = 0; uiRow < 10; ++uiRow) {
        for (unsigned int uiCol = 0; uiCol < 10; ++uiCol) {
            cout << QueryLocation(uiRow, uiCol);
        }
        cout << endl;
    }
}

bool CRolePlayingGame::HeroIsDead() { 
    return mqHero.IsDead(); 
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
bool CRolePlayingGame::AllMonstersDead()
{
    bool bAllDead = true;
    for (unsigned int uiIndex = 0; uiIndex < 10; ++uiIndex) {
        if(!mqaMonsters[uiIndex].IsDead()) 
            bAllDead = false; 
    }
    return bAllDead;
}
