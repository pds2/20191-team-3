#ifndef TERRENO_H_
#define TERRENO_H_

#include <string>

using namespace std;

class Terreno
{
private:
    string _nome;  //Tipo de terreno: (Plain, Forest, Mountain, Fort)
    int _avoid;    //Bonus de desvio de ataque
    int _defense;  //Bonus de defesa
    bool _ocupado; //Se está ocupado por um personagem ou não
public:
    //Construtor:
    Terreno(char nome);

    //Conjunto de métodos get para os atributos
    char get_nome();
    int get_avo();
    int get_def();
    bool is_ocupado();

    void muda_ocupacao(bool ocupado);
};

#endif