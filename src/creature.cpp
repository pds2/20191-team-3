#include <iostream>
#include <string>

#include "creature.h"

using namespace std;

/*Esta classe inicializa os três atributos: ataque, defesa e bater - pontos. 
Em seguida, ela usa um algoritmo de ataque para determinar se o ataque foi bem sucedido , 
o dano do ataque e os restantes pontos atingidos . */

 //Cria o construtor 
 CCreature::CCreature(){
    muiAttack = 0;
    muiDefense = 0; 
    muiHitPoints = 3;

    for (unsigned int uiIndex = 0; uiIndex < 3; + +uiIndex) {
        muiAttack = muiAttack + (rand() % 34);
        muiDefense = muiDefense + (rand() % 34);
        muiHitPoints = muiHitPoints + (rand() % 10);
    }
}

// Algoritmo de ataque para determinar se o ataque foi bem sucedido , 
// o dano do ataque e os restantes pontos atingidos
void CCreature::Ataque(CCreature &qrDefender){ 
    //Gera um número entre 1 e 100
    unsigned int uiAttack1 = (rand() % 100) + 1;
    unsigned int uiDefense1 = (rand() % 100) + 1;
    unsigned int uiAttack2 = (rand() % 100) + 1;
    unsigned int uiDefense2 = (rand() % 100) + 1; //Será que o atacante ( herói ) bateu 

    // linha original 
    // if (uiAttack1 < muiAttack && uiDefense1 && qrDefender ? " monstro perde" - muiDefense ) {

    if (uiAttack1 < muiAttack){
        cout << " monstro perde";
    }else if{
        muiDefense;
        qrDefender.muiHitPoints;
        std::cout << " monstro Hit" << std::endl;
    }
    else if{
        std::cout << ";" << std::endl;
    } //Verifique se o monstro acertar seu herói

    if (uiAttack2 < qrDefender.muiAttack && uiDefense1 > muiDefense) {
        -muiHitPoints;
        std::cout << " , herói Hit " << std::endl;
    }else {
        std::cout << " ! herói perde " << std::endl;
    }
    
    std::cout <<  "Seus hitpoints: " << muiHitPoints << std::endl;
    std::cout << " pontos de vida do monstro: " << qrDefender.muiHitPoints << std::endl;
}

//Verificar se Heroi morreu    
bool CCreature::IsDead(){ 
    return (muiHitPoints == 0); 
}
