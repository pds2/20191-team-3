#ifndef HEALINGITEM_H_
#define HEALINGITEM_H_

#include <string>
#include "item.h"

using namespace std;

class HealingItem : public Item
{
private:
	string _nome;  //Potion, Elixir
	int _heal_pts; //Quanto ele regenera

public:
	HealingItem(string nome);					 //Construtor
	virtual void exibir_status() const override; //Exibe status para o jogador
	int Heal_Pts() const;
};

#endif