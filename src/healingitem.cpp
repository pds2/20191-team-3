#include <iostream>
#include "healingitem.h"

using namespace std;

HealingItem::HealingItem(string nome) //Construtor
{
	if (nome == "Potion") //Caso o HealingItem seja Potion
	{
		_nome = nome;
		_heal_pts = 10;
	}
	else if (nome == "Elixir") //Caso o HealingItem seja Elixir
	{
		_nome = nome;
		_heal_pts = 20;
	}
}

void HealingItem::exibir_status()
{
	if (_nome == "Potion") //Mensagem caso Potion
		cout << "Use este item para recuperar 10 pontos de HP" << endl;
	else if (_nome == "Elixir") //Mensagem caso Elixir
		cout << "Use este item para recuperar 20 pontos de HP" << endl;
}

int HealingItem::Heal_Pts(){
	return _heal_pts;
}