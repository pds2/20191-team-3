#ifndef ARMA_H_
#define ARMA_H_

#include <string>
#include "item.h"

using namespace std;

class Arma : public Item
{
private:
	string _nome;   //Nome da Arma
	string _tipo;   //Tipo da Arma (Sword, Axe, Lance, Bow, Tome)
	int _attack;	//Pontos de ataque da arma
	int _hit;		//Pontos de hit (chance de acertar)
	int _crit;		//pontos de crítico (chance do ataque desconsiderar defesa)
	int _range_min; //alcance mínimo da arma
	int _range_max; //alcance máximo da arma

public:
	Arma(string arquivo);
	Arma(string nome, string tipo, int att, int hit, int crit, int rmin, int rmax); //Construtor paramêtros resgatados de um txt
	virtual void exibir_status() const override;									//Exibe status para o jogador

	//Conjunto de métodos get para os atributos
	string get_nome() const;
	string get_tipo() const;
	int get_attack() const;
	int get_hit() const;
	int get_crit() const;
	int get_range_min() const;
	int get_range_max() const;
};

#endif