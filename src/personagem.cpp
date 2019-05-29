#include <iostream>
#include <string>

#include "personagem.h"

using namespace std;

Personagem::Personagem(string Nome, int HP, int Strength, int Skill, int Speed, int Luck, int Defense, int Resistence)
{
    _nome = Nome;
    _hpmax = HP;
    _hpAtual = HP;
    _player = 1;
    _strengh = Strength;
    _skill = Skill;
    _speed = Speed;
    _luck = Luck;
    _defense = Defense;
    _resistence = Resistence;
    _armaequipada = -1; //Sem arma equipada

    /*Criando o iventario de Itens de cura*/
    HealingItem Potion("Potion");
    HealingItem Elixir("Elixir");
    _iventario_item.push_back(Potion);
    _iventario_item.push_back(Elixir);
};

void Personagem::Ataque()
{
    cout << "Insira o codigo aqui";
}

void Personagem::Usar_Item(HealingItem curativo)
{
    _hpAtual += curativo.Heal_Pts();
    if (_hpAtual > _hpmax)
        _hpAtual = _hpmax;
}

int Personagem::Atk() //Atack = Strength + Arma(Attack)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_attack() + _strengh;
}

int Personagem::Crit() //Crit = (Skill / 2) + Arma(Crit)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_crit() + (_skill / 2);
}

int Personagem::Hit() //Hit = (Skill * 2) + (Luck / 2) + Arma(Hit)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_hit() + (_skill * 2) + (_luck / 2);
}

int Personagem::Avo() //Avoid = (Speed * 2) + Luck
{
    return (_speed * 2) + _luck;
}

string Personagem::get_nome() const
{
    return _nome;
}

int Personagem::get_Max_HP() const
{
    return _hpmax;
}

int Personagem::get_HP() const
{
    return _hpAtual;
}

int Personagem::get_Str() const
{
    return _strengh;
}

int Personagem::get_Skill() const
{
    return _skill;
}

int Personagem::get_Spd() const
{
    return _speed;
}

int Personagem::get_Lck() const
{
    return _luck;
}

int Personagem::get_Def() const
{
    return _defense;
}

int Personagem::get_Res() const
{
    return _resistence;
}