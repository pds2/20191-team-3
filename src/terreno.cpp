#include "terreno.h"

Terreno::Terreno(TipoTerreno terreno) {
    switch (terreno) {
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

int Terreno::get_avoid() {
    return _avoid;
}

int Terreno::get_defense() {
    return _defense;
}

bool Terreno::get_ocupado() {
    return _ocupado;
}

void Terreno::set_ocupacao(bool ocupacao) {
    _ocupado = ocupacao;
}