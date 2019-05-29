#include "mercenary.h"

using namespace std;

Mercenary::Mercenary(string nome, int HP, int strength, int skill, int speed, int luck, int defense, int resistence)
    : Personagem(nome, HP, strength, skill, speed, luck, defense, resistence)
{
    _classe = "Mercenary";
    _move = 6;
    _armaequipada = -1; //Sem arma equipada
}

int Mercenary::Atk() //Atack = Strength + Arma(Attack)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_attack() + get_Str();
}

int Mercenary::Crit() //Crit = (Skill / 2) + Arma(Crit)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_crit() + (get_Skill() / 2);
}

int Mercenary::Hit() //Hit = (Skill * 2) + (Luck / 2) + Arma(Hit)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_hit() + (get_Skill() * 2) + (get_Lck() / 2);
}

int Mercenary::Avo() //Avoid = (Speed * 2) + Luck
{
    return (get_Spd() * 2) + get_Lck();
}

void Mercenary::Add_Arma(Arma arma)
{
    if (_iventario_arma.size() >= 3)
    {
        //Iventario cheio
        return;
    }

    else
    {
        _iventario_arma.push_back(arma);
        if (_armaequipada == -1)
            //Equipa a primeira arma
            _armaequipada = 0;
    }
}

void Mercenary::Mudar_Equip(Arma arma)
{
    if (arma.get_tipo() != "Sword")
        return;
        
    for (int i = 0; i < _iventario_arma.size(); i++)
        if (_iventario_arma[i].get_nome() == arma.get_nome())
        {
            _armaequipada = i;
            return;
        }
}