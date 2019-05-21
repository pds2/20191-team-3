#include <iostream>
#include "healingitem.h"
using namespace std;

HealingItem::HealingItem(string nome)//Construtor
{
	if(nome=="Potion")//Caso o HealingItem seja Potion
	{
		_nome=nome;
		_HealPts=10;
	}
	else if(nome=="Elixir")//Caso o HealingItem seja Elixir
	{
		_nome=nome;
		_HealPts=20;
	}
}

void HealingItem::exibir_status()
{
	if(_nome=="Potion")//Mensagem caso Potion
		return "Use este item para recuperar 10 pontos de HP";
	else if(_nome=="Elixir")//Mensagem caso Elixir
		return "Use este item para recuperar 20 pontos de HP";
}

