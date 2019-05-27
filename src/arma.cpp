#include <iostream>
#include "arma.h"
using namespace std;

//Construtor paramêtros resgatados de um txt
Arma::Arma(string nome, string tipo, int att, int hit, int crit, int rmin, int rmax):
_nome(nome), _tipo(tipo), _attack(att), _hit(hit), _crit(crit), _range_min(rmin), _range_max(rmax){}

//retorna string com todos os dados concatenados
void Arma::exibir_status()
{
	
}

//Métodos Get
string Arma::get_nome()
{
	return _nome;
}

string Arma::get_tipo()
{
	return _tipo;
}

int Arma::get_attack()
{
	return _attack;
}

int Arma::get_hit()
{
	return _hit;
}

int Arma::get_crit()
{
	return _crit;
}

int Arma::get_range_min()
{
	return _range_min;
}

int Arma::get_range_max()
{
	return _range_max;
}
