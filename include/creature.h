#pragma once
#include "iostream"

using namespace std;

/*Esta classe inicializa os três atributos: ataque, defesa e hit - points. 
Em seguida, ela usa um algoritmo de ataque para determinar se o ataque foi bem sucedido , 
o dano do ataque e os restantes pontos atingidos . */

class CCreature
{
    private:
        unsigned int muiAttack; //Valor de ataque
        unsigned int muiDefense; //Valor de defesa
        unsigned int muiHitPoints; // "Score Points" do objeto
    public:
        CCreature();
        //Função que calcula o valor de ataque e se foi bem sucedido
        void Ataque(CCreature &qrDefender);
        //Função que retorna se o objeto (Monstro ou Heroi) foi eliminado
        bool IsDead();
}
;
