#include <iostream>
#include <fstream>
#include "arma.h"
using namespace std;

//Construtor paramêtros resgatados de um txt
Arma::Arma(string nome, string tipo, int att, int hit, int crit, int rmin, int rmax)
{
	_nome = nome;
	_tipo = tipo;
	_attack = att;
	_hit = hit;
	_crit = crit;
	_range_min = rmin;
	_range_max = rmax;
}

Arma::Arma(string arquivo)
{
	string pasta = "Entradas/Armas/";
	ifstream infile;
	infile.open(pasta + arquivo + ".txt");
	if (infile.is_open())
	{
		string nome;
		_nome = arquivo;
		infile >> nome >> _tipo >> _attack >> _hit >> _crit;
		if (_tipo == "Sword" || _tipo == "Lance" || _tipo == "Axe")
		{
			_range_min = 1;
			_range_max = 1;
		}
		else if (_tipo == "Bow")
		{
			_range_min = 2;
			_range_max = 2;
		}
		else if (_tipo == "Tome")
		{
			_range_min = 1;
			_range_max = 2;
		}
	}
	infile.close();
}

//retorna string com todos os dados concatenados
void Arma::exibir_status() const
{
	cout << _tipo << ": " << _nome << endl
		 << "Atk: " << _attack << " Hit: " << _hit << " Crit: " << _crit << endl;
	if (_range_min != _range_max)
		cout << "Rng: " << _range_min << "-" << _range_max << endl;
	else
		cout << "Rng: " << _range_min << endl;
}

//Métodos Get
string Arma::get_nome() const
{
	return _nome;
}

string Arma::get_tipo() const
{
	return _tipo;
}

int Arma::get_attack() const
{
	return _attack;
}

int Arma::get_hit() const
{
	return _hit;
}

int Arma::get_crit() const
{
	return _crit;
}

int Arma::get_range_min() const
{
	return _range_min;
}

int Arma::get_range_max() const
{
	return _range_max;
}