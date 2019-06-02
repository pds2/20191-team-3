#include <iostream>
#include <string>

#include "creature.h"

using namespace std;

/*Esta classe inicializa os três atributos: ataque, defesa e hit - points. 
Em seguida, ela usa um algoritmo de ataque para determinar se o ataque foi bem sucedido , 
o dano do ataque e os restantes pontos atingidos . */

 //Cria o construtor gerando valores aleatorios
 CCreature::CCreature(){
    muiAttack = 0;
    muiDefense = 0; 
    muiHitPoints = 3;

    for (unsigned int uiIndex = 0; uiIndex < 3; ++uiIndex) {
        muiAttack = muiAttack + (rand() % 34);
        muiDefense = muiDefense + (rand() % 34);
        muiHitPoints = muiHitPoints + (rand() % 10);
    }
}

/* Algoritmo de ataque para determinar se o ataque foi bem sucedido , 
o dano do ataque e os restantes pontos atingidos */

void CCreature::Ataque(CCreature &qrDefender){ 
    //Gera um número entre 1 e 100
    unsigned int uiAttack1 = (rand() % 100) + 1;
    unsigned int uiDefense1 = (rand() % 100) + 1;
    unsigned int uiAttack2 = (rand() % 100) + 1;
    unsigned int uiDefense2 = (rand() % 100) + 1; 
    
    //Verifica se o atacante ( herói ) vence
    if ( uiAttack1 > qrDefender.muiAttack && uiDefense1 < qrDefender.muiDefense) {
     muiHitPoints++;
     std::cout << " Monstro Hit" << std::endl;
    }
    else {
     std::cout << "Monstro Perde" << std::endl;
    } 
    //Verifique se o monstro acerta o herói
    if (uiAttack2 < qrDefender.muiAttack && uiDefense2 > qrDefender.muiDefense) {
        qrDefender.muiHitPoints--;
        std::cout << " Herói Hit " << std::endl;
    }else {
        std::cout << " Herói perde " << std::endl;
    }
    
    std::cout <<  "Seus hitpoints: " << muiHitPoints << std::endl;
    std::cout << " Pontos de vida do monstro: " << qrDefender.muiHitPoints << std::endl;
}

//Verificar se Objeto (Monstro ou Heroi) morreu    
bool CCreature::IsDead(){
    if(muiHitPoints == 0){
        return true;
    } 
    else{
        return false;
    } 
}
