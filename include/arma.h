#ifndef ARMA_H_
#define ARMA_H_
#include <string>
using namespace std;

class Arma
{
	private:
		string _nome;//Nome da Arma
		string _tipo;//Tipo da Arma (espada, machado, lança, arco, tomo)
		int _attack;//Pontos de ataque da arma
  		int _hit;//Pontos de hit (chance de acertar)
  		int _crit;//pontos de crítico (chance do ataque desconsiderar defesa) 
  		int _range_min;//alcance mínimo da arma
  		int _range_max;//alcance máximo da arma
		
	public:
		virtual void exibir_status();//Exibe status para o jogador
};

#endif
