#ifndef MERCENARY_H_
#define MERCENARY_H_

#include <string>
#include <vector>
#include "personagem.h"
#include "arma.h"

using namespace std;

class Mercenary : public Personagem
{
  private:
    string _classe;
    int _move;
    int _armaequipada;
    vector<Arma> _iventario_arma; //Max 3 Armas
  public:
    Mercenary(string nome, int HP, int strength, int skill, int speed, int luck, int defense, int resistence);
    void Add_Arma(Arma arma);
    void Mudar_Equip(Arma arma);

    //Calculo dos parametros de batalha
	int Atk();
	int Hit();
	int Crit();
	int Avo();
};

#endif