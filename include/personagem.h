#pragma once
#ifndef PERSONAGEM_H_
#define PERSONAGEM_H_

#include <iostream>
#include <string>
#include <vector>

#include "healingitem.h"
#include "arma.h"

using namespace std;

class Personagem
{
private:
	string _nome;   //Nome do personagem
	string _classe; //Classe de batalha

	/*	Atributos de batalha	*/
	int _hp_Max;   //HP Maximo
	int _hp_Atual; //HP Atual

	int _strengh;
	int _skill;
	int _speed;
	int _luck;
	int _defense;
	int _resistence;

	int _move;							 //Número de movimentos máximos
	int _armaequipada;					 //Posição da arma equipada no iventário
	vector<Arma> _iventario_arma;		 //Iventário de Armas, Max 3
	vector<HealingItem> _iventario_item; //Iventário de Itens, Max 2
	bool _player;						 //Define se é player ou não

	//Parametros de localizacao no mapa
	int _pos_i;
	int _pos_j;
	bool _usavel; //Define se pode ser utilizado no turno

public:
	//Construtor
	Personagem(string nome, string classe, int HP, int strength, int skill, int speed, int luck, int defense, int resistence, bool jogador);
	Personagem();

	//Conjunto de métodos get para os atributos
	char get_Nome();
	string get_nome() const;
	string get_Classe() const;
	int get_Max_HP() const;
	int get_HP() const;
	int get_Str() const;
	int get_Skill() const;
	int get_Spd() const;
	int get_Lck() const;
	int get_Def() const;
	int get_Res() const;
	int get_Move() const;

	void Add_Arma(Arma arma);
	void Mudar_Arma_Equipada(Arma arma);
	Arma Arma_Equipada() const;
	void Usar_Item(HealingItem curativo);

	/*	Calculo dos parâmetros de batalha	*/
	int Atk();  //Força
	int Hit();  //Chance de acertar
	int Crit(); //Chance de ataque crítico
	int Avo();  //Chance de desviar de ataque

	//Parametros de localizacao no mapa
	void set_i(int pos_i);
	void set_j(int pos_j);
	void set_usavel(bool usavel);

	int get_i() const;
	int get_j() const;
	bool is_usavel() const;

	//Impressão de dados na tela
	void imprime_status() const;
	void imprime_iventario() const;

	//Função que calcula o valor de ataque e se foi bem sucedido
    void Ataque(Personagem &qrDefender);
    //Função que retorna se o objeto (Monstro ou Heroi) foi eliminado
    bool IsDead();
};

#endif