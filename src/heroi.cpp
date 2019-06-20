#include <iostream>

#include "heroi.h"
#include "personagem.h"


Heroi:: Heroi() {}

Heroi:: Heroi(string nome, string classe, int HP, int strength, int skill, int speed, int luck, int defense, int resistence, bool jogador) {
    _nome = nome;
    if (classe == "PegasusKnight")
        _classe = "Pegasus Knight";
    else
        _classe = classe;
    _hp_Max = HP;
    _hp_Atual = HP;
    _strengh = strength;
    _skill = skill;
    _speed = speed;
    _luck = luck;
    _defense = defense;
    _resistence = resistence;

    if (classe == "Archer" || classe == "Mage" || classe == "General")
        _move = 5;
    else if (classe == "Mercenary" || classe == "Warrior")
        _move = 6;
    else if (classe == "Lord")
        _move = 7;
    else if (classe == "Paladin" || classe == "PegasusKnight")
        _move = 8;

    /*Criando o iventario de Itens de cura*/
    HealingItem Potion("Potion");
    HealingItem Elixir("Elixir");
    _iventario_item.push_back(Potion);
    _iventario_item.push_back(Elixir);

    _armaequipada = -1; //Não tem arma equipada
}

void Heroi::Move(int x, int y)
{
    this->set_i(x);
    this->set_j(y);
}

void Heroi::set_usavel(bool usavel)
{
    _usavel = usavel;
}

bool Heroi::is_usavel() const
{
    return _usavel;
}