#include <iostream>

#include "monstro.h"
#include "personagem.h"

Monstro:: Monstro() {}

Monstro:: Monstro(string nome, string classe, int HP, int strength, int skill, int speed, int luck, int defense, int resistence, bool jogador){}

// bool Heroi::Move(){
// }

// void Heroi::setHeroi(){
    
// }

void Monstro::Move(int x, int y)
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
