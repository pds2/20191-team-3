#include <iostream>
#include <string>

#include "personagem.h"

using namespace std;

//Construtor
Personagem::Personagem(string nome, string classe, int HP, int strength, int skill, int speed, int luck, int defense, int resistence)
{
    _nome = nome;
    if (classe == "PegasusKnight")
        _classe = "Pegasus Knight";
    else
        _classe = classe;
    _hp_Max = HP;
    _hp_Atual = HP;
    _player = true;
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
};

Personagem::Personagem(){}

void Personagem::Usar_Item(HealingItem curativo)
{
    _hp_Atual += curativo.Heal_Pts();
    if (_hp_Atual > _hp_Max)
        _hp_Atual = _hp_Max;
}

string Personagem::get_Nome() const
{
    return _nome;
}

string Personagem::get_Classe() const
{
    return _classe;
}

int Personagem::get_Max_HP() const
{
    return _hp_Max;
}

int Personagem::get_HP() const
{
    return _hp_Atual;
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

int Personagem::get_Move() const
{
    return _move;
}

int Personagem::Atk() //Atack = Strength + Arma(Attack)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_attack() + get_Str();
}

int Personagem::Crit() //Crit = (Skill / 2) + Arma(Crit)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_crit() + (get_Skill() / 2);
}

int Personagem::Hit() //Hit = (Skill * 2) + (Luck / 2) + Arma(Hit)
{
    if (_armaequipada == -1)
        return 0;
    else
        return _iventario_arma[_armaequipada].get_hit() + (get_Skill() * 2) + (get_Lck() / 2);
}

int Personagem::Avo() //Avoid = (Speed * 2) + Luck
{
    return (get_Spd() * 2) + get_Lck();
}

void Personagem::set_i(int pos_i)
{
    _pos_i = pos_i;
}

void Personagem::set_j(int pos_j)
{
    _pos_j = pos_j;
}

void Personagem::set_usavel(bool usavel)
{
    _usavel = usavel;
}

int Personagem::get_i() const
{
    return _pos_i;
}

int Personagem::get_j() const
{
    return _pos_j;
}

bool Personagem::is_usavel() const
{
    return _usavel;
}

void Personagem::Add_Arma(Arma arma)
{
    if (_iventario_arma.size() < 3)
    {
        if (arma.get_tipo() == "Sword")
        {
            if (_classe == "Mercenary" || _classe == "Lord" || _classe == "Paladin")
                _iventario_arma.push_back(arma);
        }
        if (arma.get_tipo() == "Lance")
        {
            if (_classe == "General" || _classe == "Pegasus Knight" || _classe == "Paladin")
                _iventario_arma.push_back(arma);
        }
        if (arma.get_tipo() == "Axe")
        {
            if (_classe == "General" || _classe == "Lord" || _classe == "Warrior")
                _iventario_arma.push_back(arma);
        }
        if (arma.get_tipo() == "Bow")
        {
            if (_classe == "Archer")
                _iventario_arma.push_back(arma);
        }
        if (arma.get_tipo() == "Tome")
        {
            if (_classe == "Mage")
                _iventario_arma.push_back(arma);
        }
    }

    if (_iventario_arma.size() == 1)
        _armaequipada = 0;
}

void Personagem::Mudar_Arma_Equipada(Arma arma)
{
    for (unsigned int i = 0; i < _iventario_arma.size(); i++)
        if (_iventario_arma[i].get_nome() == arma.get_nome())
            _armaequipada = i;
}

Arma Personagem::Arma_Equipada() const
{
    return _iventario_arma[_armaequipada];
}

void Personagem::imprime_status() const
{
    cout << get_Classe() << ": " << get_Nome() << endl
         << "HP: " << get_HP() << "/" << get_Max_HP() << " Mov: " << get_Move() << endl
         << "Str: " << get_Str() << " Skl: " << get_Skill() << endl
         << "Spd: " << get_Spd() << " Lck: " << get_Lck() << endl
         << "Def: " << get_Def() << " Res: " << get_Res() << endl;
}

void Personagem::imprime_iventario() const
{
    for (unsigned int i = 0; i < _iventario_arma.size(); i++)
        cout << _iventario_arma[i].get_nome() << endl;
    cout << "Potion" << endl
         << "Elixir" << endl;
}

void Personagem::Ataque(Personagem &qrDefender){ 
    //Gera um número entre 1 e 100
    unsigned int uiAttack1 = (rand() % 100) + 1;
    unsigned int uiDefense1 = (rand() % 100) + 1;
    unsigned int uiAttack2 = (rand() % 100) + 1;
    unsigned int uiDefense2 = (rand() % 100) + 1; 
    
    //Verifica se o atacante ( herói ) vence
    if ( uiAttack1 > qrDefender.muiAttack && uiDefense1 < qrDefender.muiDefense) {
     muiHitPoints++;
     std::cout << " Monstro Hit" << std::endl;
    }
    else {
     std::cout << "Monstro Perde" << std::endl;
    } 
    //Verifique se o monstro acerta o herói
    if (uiAttack2 < qrDefender.muiAttack && uiDefense2 > qrDefender.muiDefense) {
        qrDefender.muiHitPoints--;
        std::cout << " Herói Hit " << std::endl;
    }else {
        std::cout << " Herói perde " << std::endl;
    }
    
    std::cout <<  "Seus hitpoints: " << muiHitPoints << std::endl;
    std::cout << " Pontos de vida do monstro: " << qrDefender.muiHitPoints << std::endl;
}

//Verificar se Objeto (Monstro ou Heroi) morreu    
bool Personagem::IsDead(){
    if(muiHitPoints == 0){
        return true;
    } 
    else{
        return false;
    } 
}