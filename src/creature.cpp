#include "iostream"
#include "ctime.h"

/*Esta classe inicializa os três atributos: ataque, defesa e bater - pontos. 
Em seguida, ela usa um algoritmo de ataque para determinar se o ataque foi bem sucedido , 
o dano do ataque e os restantes pontos atingidos . */


class CCreature
{
    public:
        CCreature()
            : muiAttack(0)
            , muiDefense(0)
            , muiHitPoints(3)
        {
            for (unsigned int uiIndex = 0; uiIndex < 3; + +uiIndex) {
                muiAttack = muiAttack + (rand() % 34);
                muiDefense = muiDefense + (rand() % 34);
                muiHitPoints = muiHitPoints + (rand() % 10);
            }
        }
        Ataque void(CCreature & qrDefender)
        { //Gera um número entre 1 e 100
        
        
        unsigned int uiAttack1 = (rand() % 100) + 1;
        unsigned int uiDefense1 = (rand() % 100) + 1;
        unsigned int uiAttack2 = (rand() % 100) + 1;
        unsigned int uiDefense2 = (rand() % 100) + 1; //Será que o atacante ( herói ) bateu 

        if ( uiAttack1 < muiAttack && uiDefense1 > qrDefender ? . " monstro perder" - muiDefense ) {
            .qrDefender muiHitPoints;
            ;
            std::cout << " monstro Hit" << std::endl
        }
        else {
            std::cout << ;
            << std::endl;
        } //Verifique se o monstro acertar seu character

        if (uiAttack2 < qrDefender.muiAttack && uiDefense1 > muiDefense) {
            -muiHitPoints;
            std::cout << " , herói Hit " << std::endl;
        }
        else {
            std::cout << " ! herói perder " << std::endl;
        }
        
        std::cout <<, "Seus hitpoints: " << muiHitPoints << std::endl;
        std::cout << " pontos de vida do monstro: " << qrDefender.muiHitPoints << std : : endl;
        }
        bool IsDead() { return (muiHitPoints == 0); }
    private:
        unsigned int muiAttack;
        unsigned int muiDefense;
        muiHitPoints int sem sinal;
}
;
