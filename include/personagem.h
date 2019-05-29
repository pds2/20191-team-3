#ifndef PERSONAGEM_H_
#define PERSONAGEM_H_

#include <iostream>
#include <string>
#include <vector>
#include "healingitem.h"

using namespace std;

class Personagem
{
  private:
	string _nome;
	vector<HealingItem> _iventario_item; //Max 2 Itens
	int _hpmax;
	int _hpAtual;
	bool _player;
	int _strengh;
	int _skill;
	int _speed;
	int _luck;
	int _defense;
	int _resistence;

  public:
	Personagem(string nome, int HP, int strength, int skill, int speed, int luck, int defense, int resistence);
	void Ataque();
	void Usar_Item(HealingItem curativo);

	//Conjunto de métodos get para os atributos
	string get_nome() const;
	int get_Max_HP() const;
	int get_HP() const;
	int get_Str() const;
	int get_Skill() const;
	int get_Spd() const;
	int get_Lck() const;
	int get_Def() const;
	int get_Res() const;
};

#endif