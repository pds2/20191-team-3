#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <istream>

#include "mapa.h"
#include "arma.h"
#include "healingitem.h"
#include "personagem.h"

using namespace std;

int main()
{
    Mapa ch12 = Mapa("mapa_ch12.txt");
    ch12.cria_lista_personagens();
    //ch12.imprime();
    Personagem P = ch12.get_personagem("Marcus");
    P.imprime_status();
    P.imprime_iventario();
    return 0;
}