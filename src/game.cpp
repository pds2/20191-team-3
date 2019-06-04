#include <iostream>
#include <time.h>  

#include "game.h"

/*Esta classe controla o movimento dos seu heróis. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 10 monstros e seu heróis dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

CRolePlayingGame::CRolePlayingGame()
{
    //Cria um objeto terreno vazio para realizar comparação e setar o personagem
    Terreno TerraVazia;
    TerraVazia.set_ocupacao(false);
   
    //Pega valor do tamanho de lihas e Colunas do Mapa 
    int num_linhas = map.get_num_linhas();
    int num_colunas = map.get_num_colunas();
    
    //Não entendi essa função mas estava no codigo do Vinicius 
    map.cria_lista_personagens();
    
    //Cria os personagens e setam eles em uma posicao aleatoria no mapa
    bool bFoundSpot = false;
    unsigned int uiHero = 0; 
    while (!bFoundSpot) { 
        unsigned int uiRow = 1 + ( rand ()% num_linhas); 
        unsigned int uiCol = 1 + ( rand ()% num_colunas); 
    
        Terreno Retorno; //Recebe valor de Retorno da função Query Location para saber se Terreno está 
        Retorno = QueryLocation(uiRow,uiCol); //Ocupado ou não
        if (Retorno == TerraVazia) { /*Não sei como compara classe com classe!!!!! */
            Personagem P = map.get_personagem("Marcus");
            mqHero[uiHero] = P;
            ++uiHero;
            bFoundSpot = true;
            mqpaaCreatures[uiRow][uiCol] = &mqHero[uiHero];
            if (uiHero == 5) {
                bFoundSpot = true;
            }
            // P.imprime_status();
            // P.imprime_iventario();
        }
    } 
    //Cria 10 Monstros e seta ele em posiçoes aleatorias no mapa 
    bFoundSpot = false;
    unsigned int uiMonster = 0;
    while (!bFoundSpot) {
        unsigned int uiRow = 1 + (rand() % num_linhas);
        unsigned int uiCol = 1 + (rand() % num_colunas);

        Terreno Retorno; //Recebe valor de Retorno da função Query Location para saber se Terreno está 
        Retorno = QueryLocation(uiRow,uiCol); //Ocupado ou não
        if (Retorno == TerraVazia) { /*Não sei como compara classe com classe!!!!! */
            Personagem M = map.get_personagem("Monstro/Vilão");
            mqaMonsters[uiMonster] = M;
            mqpaaCreatures[uiRow][uiCol] = &mqaMonsters[uiMonster];
            ++uiMonster;
            if (uiMonster == 10) {
                bFoundSpot = true;
            }
        }
    }
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



Terreno CRolePlayingGame::QueryLocation(unsigned int uiRow, unsigned int uiCol)
{
    Terreno t;
    t.set_ocupacao(true);
    for (unsigned int uIndex = 0; uIndex < 10; ++uIndex)
    {
        if (mqpaaCreatures[uiRow][uiCol] == &mqaMonsters[uIndex]) {
            return t;
        }
    }
    for (unsigned int uIndex = 0; uIndex < 10; ++uIndex){
        if (mqpaaCreatures[uiRow][uiCol] == mqHero) {
            return t;
        }
    }
    return map.GetMazeSquare(uiRow, uiCol);
}

// PAREI DE IMPLEMENTAR ATÉ AQUI...

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
