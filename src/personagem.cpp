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