#ifndef HEROI_H
#define HEROI_H

#include <iostream>
#include <string>
#include <vector>

#include "personagem.h"

class Heroi : public Personagem {
    private:
    	bool _usavel; //Define se pode ser utilizado no turno

    public:
        Heroi();
        Heroi(string nome, string classe, int HP, int strength, int skill, int speed, int luck, int defense, int resistence, bool jogador);
        void Move(int x, int y);
        void setHeroi();
    	void set_usavel(bool usavel);
    	bool is_usavel() const;
};

#endif