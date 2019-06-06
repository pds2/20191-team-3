#include <iostream>
#include <time.h>  

#include "game.h"

using namespace std;

/*Esta classe controla o movimento dos seu heróis. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 10 monstros e seu heróis dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

CRolePlayingGame::CRolePlayingGame()
{
    //Cria um objeto terreno vazio para realizar comparação e setar o personagem
    Terreno TerraVazia;
    TerraVazia.set_tipo_ocupacao(0);
   
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
        if (TerrenoComparator(Retorno,TerraVazia)) { /*Comparando o Terreno gerado aletorio com vazio */
            Personagem P = map.get_personagem("Marcus");
            mqHero[uiHero] = P;
            ++uiHero;
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
        if (TerrenoComparator(Retorno,TerraVazia)) { /*Comparando o Terreno gerado aletorio com vazio */
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
    for (unsigned int uIndex = 0; uIndex < 10; ++uIndex)
    {
        if (mqpaaCreatures[uiRow][uiCol] == &mqaMonsters[uIndex]) {
            t.set_tipo_ocupacao(2);
            return t;
        }
    }
    for (unsigned int uIndex = 0; uIndex < 5; ++uIndex){
        if (mqpaaCreatures[uiRow][uiCol] == &mqHero[uIndex]) {
             t.set_tipo_ocupacao(1);
            return t;
        }
    }
    return map.GetMazeSquare(uiRow, uiCol);
}


bool CRolePlayingGame::MoveHero(char const kcDirection, int numPersonagem)
{
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
    if (uiNextRow > map.get_num_linhas || uiNextCol > map.get_num_colunas)
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
    for (unsigned int uiRow = 0; uiRow < map.get_num_linhas; ++uiRow) {
        for (unsigned int uiCol = 0; uiCol < map.get_num_colunas; ++uiCol) {
            Terreno TerrenoPrint;
            TerrenoPrint = QueryLocation(uiRow, uiCol);
            if(TerrenoPrint.get_tipo_ocupado() == 0){
                cout << TerrenoPrint.get_nome() << endl;
            }
            if(TerrenoPrint.get_tipo_ocupado() == 1){
                Personagem p = *mqpaaCreatures[uiRow][uiCol];
                cout << p.get_Nome();
            }
            if(TerrenoPrint.get_tipo_ocupado() == 2){
                Personagem p = *mqpaaCreatures[uiRow][uiCol];
                cout << p.get_Nome();
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

