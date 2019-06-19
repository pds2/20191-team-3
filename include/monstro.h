#ifndef MONSTRO_H
#define MONSTRO_H

#include <iostream>
#include <string>
#include <vector>

#include "personagem.h"

class Monstro : public Personagem {
    public:
        Monstro();
        Monstro(string nome, string classe, int HP, int strength, int skill, int speed, int luck, int defense, int resistence, bool jogador);
        void Move(int x, int y) override;
        void setHeroi();
};

#endif