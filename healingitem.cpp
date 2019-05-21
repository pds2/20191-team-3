#include <iostream>
#include "healingitem.h"
using namespace std;

HealingItem::HealingItem(string nome)
{
	if(nome=="Potion")
	{
		_nome=nome;
		_HealPts=10;
	}
	else if(nome=="Elixir")
	{
		_nome=nome;
		_HealPts=20;
	}
}

void HealingItem::exibir_status()
{
	if(_nome=="Potion")
		return "Use este item para recuperar 10 pontos de HP";
	else if(_nome=="Elixir")
		return "Use este item para recuperar 20 pontos de HP";
}

