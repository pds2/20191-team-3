#include "terreno.h"

Terreno::Terreno(TipoTerreno terreno) //Construtor
{
    switch (terreno)
    {
    case TipoTerreno::Plain:
        _nome = "Plain";
        _avoid = 0;
        _defense = 0;
        break;

    case TipoTerreno::Forest:
        _nome = "Forest";
        _avoid = 20;
        _defense = 1;
        break;

    case TipoTerreno::Mountain:
        _nome = "Mountain";
        _avoid = 30;
        _defense = 1;
        break;

    case TipoTerreno::Fort:
        _nome = "Fort";
        _avoid = 20;
        _defense = 2;
        break;
    }
}

Terreno::Terreno(char nome) //Construtor
{
    _ocupado = false;
    _tipocupacao = 0;
    if (nome == 'P')
    {
        _nome = "Plain";
        _avoid = 0;
        _defense = 0;
    }
    else if (nome == 'M')
    {
        _nome = "Mountain";
        _avoid = 30;
        _defense = 1;
    }
    else if (nome == 'F')
    {
        _nome = "Forest";
        _avoid = 20;
        _defense = 1;
    }
    else if (nome == 'f')
    {
        _nome = "Fort";
        _avoid = 20;
        _defense = 2;
    }
}

Terreno::Terreno() {}

char Terreno::get_nome()
{
    if (_ocupado == true)
        return 'x';
    if (_nome == "Plain")
        return '_';
    else if (_nome == "Forest")
        return 'f';
    else if (_nome == "Mountain")
        return 'm';
    else if (_nome == "Fort")
        return '#';
    else
        return ' ';
}

int Terreno::get_avoid()
{
    return _avoid;
}

int Terreno::get_defense()
{
    return _defense;
}

int Terreno::get_tipo_ocupado()
{
    return _tipocupacao;
}

bool Terreno::get_ocupado()
{
    return _ocupado;
}

void Terreno::set_ocupacao(bool ocupacao)
{
    _ocupado = ocupacao;
}

void Terreno::set_tipo_ocupacao(int tipocupacao)
{
    _tipocupacao = tipocupacao;
}