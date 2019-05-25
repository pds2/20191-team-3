#include <iostream>
#include "arma.h"
using namespace std;

void Arma::exibir_status()
{
	return _nome;//Nome da Arma
	return _tipo;//Tipo da Arma (espada, machado, lança, arco, tomo)
	return _attack;//Pontos de ataque da arma
  	return _hit;//Pontos de hit (chance de acertar)
  	return _crit;//pontos de crítico (chance do ataque desconsiderar defesa) 
  	return _range_min;//alcance mínimo da arma
  	return _range_max;//alcance máximo da arma
}
