#include "terreno.h"

Terreno::Terreno(char nome) //Construtor
{
    _ocupado = false;
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

char Terreno::get_nome()
{
    if (_ocupado == true)
        return 'x';
    if (_nome == "Plain")
        return '_';
    else if (_nome == "Forest")
        return 'F';
    else if (_nome == "Mountain")
        return 'M';
    else if (_nome == "Fort")
        return '#';
    else
        return ' ';
}

int Terreno::get_avo()
{
    return _avoid;
}

int Terreno::get_def()
{
    return _defense;
}

bool Terreno::is_ocupado()
{
    return _ocupado;
}

void Terreno::muda_ocupacao(bool ocupado)
{
    _ocupado = ocupado;
}