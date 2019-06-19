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

// bool Heroi::Move(){
// }

// void Heroi::setHeroi(){
    
// }

void Heroi::Move(int x, int y)
{
    this->set_i(x);
    this->set_j(y);
    /*int num_linhas = map.get_num_linhas();
    int num_colunas = map.get_num_colunas();
    unsigned int uiHeroRow = get_i();
    unsigned int uiHeroCol = get_j(); 
    unsigned int uiNextRow = uiHeroRow;
    unsigned int uiNextCol =uiHeroCol;
    switch (kcDirection) {
        case 'w':
        case 'W': {
            --uiNextRow;
            break;
        }
        case 'd':
        case 'D': {
            ++uiNextCol;
            break;
        }
        case 's':
        case 'S': {
            ++uiNextRow;
            break;
        }
        case 'a':
        case 'A': {
            --uiNextCol;
            break;
        }
        case 'i':
        case 'I': {
            imprime_status();
            return false;
            break;
        }

        default: {
            return false;
        }
    }
    
    // Trata o tamanho do mapa diponivel
    if ((unsigned)uiNextRow >= (unsigned)num_linhas || (unsigned)uiNextCol >= (unsigned)num_colunas)
        return false;

    int tipoOcupacao = map.GetMazeSquare(uiNextRow, uiNextCol).get_tipo_ocupado();
    if (tipoOcupacao == 0) { //terreno destino vazio
        //esvazia o terreno atual
        map.set_ocupacao_terreno(uiHeroRow, uiHeroCol, 0);
        map.toggle_ocupado(uiHeroRow, uiHeroCol, false);

        //preenche o novo terreno
        map.set_ocupacao_terreno(uiNextRow, uiNextCol, 1);
        map.toggle_ocupado(uiHeroRow, uiHeroCol, true);

        //setando personagem na posição correta
        map.setPosHeroi(get_nome(), uiNextRow, uiNextCol);
    }
    else if (tipoOcupacao == 1) {
        cout<<"Movimento inválido."<<endl;
        return false;
    }
    else {
        Heroi* atacante = map.getHeroiPorPosicao(uiHeroRow, uiHeroCol);
        Heroi* atacado = map.getHeroiPorPosicao(uiNextRow, uiNextCol);
        
        bool retorno=map.Batalha(*atacante, *atacado);
        if(retorno==true)
        {
            map.setPosHeroi(get_nome(), uiNextRow, uiNextCol);
        }

        //TODO: movimentação pós batalha
    }
    return true;
     */
}

void Heroi::set_usavel(bool usavel)
{
    _usavel = usavel;
}

bool Heroi::is_usavel() const
{
    return _usavel;
}