#ifndef HEALINGITEM_H_
#define HEALINGITEM_H_
#include <string>
using namespace std;

class HealingItem
{
	private:
		string _nome;//Potion, Elixir
		int _HealPts;//Quanto ele regenera
	public:
		HealingItem(string nome);//Construtor
		virtual void exibir_status();//Exibe status para o jogador
};

#endif