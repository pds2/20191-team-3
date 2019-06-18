#ifndef HEROI_H
#define HEROI_H

#include <iostream>
#include <string>
#include <vector>

#include "personagem.h"

class Heroi : public Personagem {
    public:
        Heroi();
        Heroi(string nome, string classe, int HP, int strength, int skill, int speed, int luck, int defense, int resistence, bool jogador);
        bool Move() override;
        bool Move(char const kcDirection, Mapa map);
        void setHeroi();
};

#endif