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
		Arma(string nome, string tipo, int att, int hit, int crit, int rmin, int rmax);//Construtor paramêtros resgatados de um txt
		virtual void exibir_status();//Exibe status para o jogador
	//Conjunto de métodos get para os atributos
		string get_nome();
		string get_tipo();
		int get_attack();
		int get_hit();
		int get_crit();
		int get_range_min();
		int get_range_max();
};

#endif
