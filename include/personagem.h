#ifndef PERSONAGEM_H_
#define PERSONAGEM_H_

#include <iostream>
#include <string>
#include <vector>
#include "arma.h"
#include "healingitem.h"

using namespace std;

class Personagem
{
  private:
	string _nome;
	vector<HealingItem> _iventario_item; //Max 2 Itens
	vector<Arma> _iventario_arma;		 //Max 3 Armas
	int _hpmax;
	int _armaequipada;
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
	void Add_Arma(string nome);
	void Mudar_Arma_Equipada(string nome);
	
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
	bool is_alive() const;

	//Calculo dos parametros de batalha
	int Atk();
	int Hit();
	int Crit();
	int Avo();
};

#endif