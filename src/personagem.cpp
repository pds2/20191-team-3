#include <iostream>
#include <string>

#include "personagem.h"


Personagem::Personagem(){
        _nome = "Nome";     
        //_iventario;
        _hpmax = 100;      
        _armaequipada = 10;
        _hpAtual = 5;    
        _player = 1;
        _strengh = 2;
        _skill = 3;
        _speed = 10;
        _luck = 2;
        _defense = 10;
        _resistence = 20;
};

void Personagem::Ataque(){
    cout << "Insira o codigo aqui";
}

