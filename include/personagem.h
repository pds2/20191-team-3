#include <iostream>
#include <string>

using namespace std;

class Personagem
{
    private:
        std::string _nome;     
        //Item _iventario[5];
        int _hpmax;      
        int _armaequipada;
        int _hpAtual;    
        bool _player;
        int _strengh;
        int _skill;
        int _speed;
        int _luck;
        int _defense;
        int _resistence;
    public:
        Personagem();
        void Ataque();
        void Usar_Item();
};
