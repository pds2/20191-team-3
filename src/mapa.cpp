#include <time.h>
#include <limits>
#include "mapa.h"

Mapa::Mapa() {}

Mapa::Mapa(string nome) //Construtor
{
    ifstream map_file;
    map_file.open("Entradas/Mapas/" + nome);
    _nome = nome;
    if (map_file.is_open())
    {
        cout << "Carregando mapa: " << nome << endl;
        map_file >> _num_linhas >> _num_colunas;
        map_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // cout << _num_linhas << "x" << _num_colunas << endl;
        for (int i = 0; i < _num_linhas; i++)
        {
            string linha;
            getline(map_file, linha);
            vector<Terreno> vetor;
            for (int j = 0; j < _num_colunas; j++)
            {
                Terreno T(linha[j]);
                vetor.push_back(T);
            }
            _grade.push_back(vetor);
        }
    }
    map_file.close();
}

void Mapa::imprime()
{
    for (int i = 0; i < _num_linhas; i++)
    {
        for (int j = 0; j < _num_colunas; j++)
            cout << _grade[i][j].get_nome() << ' ';
        cout << endl;
    }
}

int Mapa::get_num_colunas()
{
    return _num_colunas;
}

int Mapa::get_num_linhas()
{
    return _num_linhas;
}

Terreno Mapa::GetMazeSquare(unsigned int uiRow, unsigned int uiCol)
{
    return _grade[uiRow][uiCol];
}

// map<string, Heroi *> Mapa::get_lista_personagens()
// {
//     return this->_lista_personagens;
// }

// map<string, Heroi *> Mapa::get_lista_personagens(bool heroi)
// {
//     std::map<string, Heroi *> personagensAux;

//     for (std::map<string, Heroi *>::iterator it = this->_lista_personagens.begin(); it != this->_lista_personagens.end(); it++)
//     {
//         if (it->second->isPlayer() == heroi)
//             personagensAux.insert(make_pair(it->first, it->second));
//     }

//     return personagensAux;
// }

// Heroi *Mapa::getHeroiPorPosicao(int x, int y)
// {
//     for (std::map<string, Heroi *>::iterator it = this->_lista_personagens.begin(); it != this->_lista_personagens.end(); it++)
//     {
//         if (it->second->get_i() == x && it->second->get_j() == y)
//             return it->second;
//     }

//     throw runtime_error("Nenhum personagem na posição.");
//     return NULL;
// }

// bool Mapa::Batalha(Heroi &Atacante, Monstro &Defensor)
// {
//     //Gera quatro números aleatótios de 0 a 99
//     //Valores de hit e crit do atacante
//     int hitA = rand() % 100;
//     int critA = rand() % 100;

//     //Valores de hit e crit do defensor
//     int hitD = rand() % 100;
//     int critD = rand() % 100;

//     //Valores de terreno
//     Terreno tA = GetMazeSquare(Atacante.get_i(), Atacante.get_j());
//     Terreno tD = GetMazeSquare(Defensor.get_i(), Defensor.get_j());

//     //Se ambos são do mesmo time
//     if (Atacante.isPlayer() == Defensor.isPlayer())
//         return false;

//     //Bonus de triângulo de armas (Sword > Axe > Lance > Sword)
//     srand(time(NULL));
//     int bonusA = Atacante.Hit();
//     int bonusD = Defensor.Hit();
//     string tipo_arma_A = Atacante.Arma_Equipada().get_tipo();
//     string tipo_arma_D = Defensor.Arma_Equipada().get_tipo();
//     if ((tipo_arma_A == "Sword" && tipo_arma_D == "Axe") || (tipo_arma_A == "Lance" && tipo_arma_D == "Sword") || (tipo_arma_A == "Axe" && tipo_arma_D == "Lance"))
//     {
//         bonusA += 4;
//     }
//     else if ((tipo_arma_D == "Sword" && tipo_arma_A == "Axe") || (tipo_arma_D == "Lance" && tipo_arma_A == "Sword") || (tipo_arma_D == "Axe" && tipo_arma_A == "Lance"))
//     {
//         bonusD += 4;
//     }

//     int defesaA, defesaD;
//     if (Atacante.Arma_Equipada().get_tipo() == "Tome")
//         defesaD = Defensor.get_Res();
//     else
//         defesaD = Defensor.get_Def();

//     if (Defensor.Arma_Equipada().get_tipo() == "Tome")
//         defesaA = Atacante.get_Res();
//     else
//         defesaA = Atacante.get_Def();

//     //Primeiro ataque
//     if (hitA < bonusA - Defensor.Avo() - tD.get_avoid())
//     {
//         int dano;
//         if (critA > Atacante.Crit())
//             dano = (Atacante.Atk() - defesaD - tD.get_defense()) * 3;
//         else
//             dano = Atacante.Atk() - defesaD - tD.get_defense();
//         if (dano > 0)
//         {
//             int HP = Defensor.get_HP() - dano;
//             cout << Atacante.get_nome() <<" aplicou " << dano << " pontos de dano!" <<endl;
//             if (HP <= 0) //Se defensor morreu
//             {
//                 Defensor.set_HP(0);
//                 cout << Defensor.get_nome() << " derrotado." << endl;
                
//                 _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
//                 _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);

//                 _grade[Defensor.get_i()][Defensor.get_j()].set_ocupacao(true);
//                 _grade[Defensor.get_i()][Defensor.get_j()].set_tipo_ocupacao(1);

//                 _lista_personagens.erase(Defensor.get_nome());

//                 return true;
//             }
//         }
//     }
//     //Contra-ataque
//     if (hitD < bonusD - Atacante.Avo() - tA.get_avoid())
//     {
//         int dano;
//         if (critD > Atacante.Crit())
//             dano = (Defensor.Atk() - defesaA - tA.get_defense()) * 2;
//         else
//             dano = Defensor.Atk() - defesaA - tA.get_defense();
//         if (dano > 0)
//         {
//             int HP = Atacante.get_HP() - dano;
//             cout << Defensor.get_nome() <<" aplicou " << dano << " pontos de dano!" <<endl;
//             if (HP <= 0) //Se atacante morreu
//             {
//                 Atacante.set_HP(0);
//                 cout << Atacante.get_nome() << " derrotado." << endl;
                
                
//                 _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
//                 _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);

//                 _lista_personagens.erase(Atacante.get_nome());
                
//                 return true;
//             }
//         }
//     }
//     //Se um personagem tem velocidade maior que o outro, ele ataca novamente
//     if (Atacante.get_Spd() - Defensor.get_Spd() >= 4)
//     {
//         hitA = rand() % 100;
//         critA = rand() % 100;
//         if (hitA < bonusA - Defensor.Avo() - tD.get_avoid())
//         {
//             int dano;
//             if (critA > Atacante.Crit())
//                 dano = (Atacante.Atk() - defesaD - tD.get_defense()) * 2;
//             else
//                 dano = Atacante.Atk() - defesaD - tD.get_defense();
//             if (dano > 0)
//             {
//                 int HP = Defensor.get_HP() - dano;
//                 cout << Atacante.get_nome() <<" aplicou um double attack!" <<endl;
//                 cout << Atacante.get_nome() <<" aplicou " << dano << " pontos de dano!" <<endl;
//                 if (HP <= 0) //Se defensor morreu
//                 {
//                     Defensor.set_HP(0);
//                     cout << Defensor.get_nome() << " derrotado." << endl;
                    
                    
//                     _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
//                     _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);

//                     _grade[Defensor.get_i()][Defensor.get_j()].set_ocupacao(true);
//                     _grade[Defensor.get_i()][Defensor.get_j()].set_tipo_ocupacao(1);

//                     _lista_personagens.erase(Defensor.get_nome());
                    
//                     return true;
//                 }
//             }
//         }
//     }
//     else if (Defensor.get_Spd() - Atacante.get_Spd() >= 4)
//     {
//         hitD = rand() % 100;
//         critD = rand() % 100;
//         if (hitD < bonusD - Atacante.Avo() - tA.get_avoid())
//         {
//             int dano;
//             if (critD > Atacante.Crit())
//                 dano = (Defensor.Atk() - defesaA - tA.get_defense()) * 3;
//             else
//                 dano = Defensor.Atk() - defesaA - tA.get_defense();
//             if (dano > 0)
//             {
//                 int HP = Atacante.get_HP() - dano;
//                 if (HP <= 0) //Se atacante morreu
//                 {
//                     Atacante.set_HP(0);
//                     cout << Atacante.get_nome() << " derrotado." << endl;

//                     _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
//                     _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);

//                     _lista_personagens.erase(Atacante.get_nome());
                   
//                     return true;
//                 }
//             }
//         }
//     }
//     return false; //Se ninguém morreu
// }

void Mapa::set_ocupacao_terreno(int x, int y, int tipoOcupacao)
{
    this->_grade[x][y].set_tipo_ocupacao(tipoOcupacao);
}

void Mapa::toggle_ocupado(int x, int y, bool ocupado)
{
    this->_grade[x][y].set_ocupacao(ocupado);
}

// void Mapa::setPosHeroi(string nome, int x, int y)
// {
//     this->_lista_personagens[nome]->set_i(x);
//     this->_lista_personagens[nome]->set_j(y);
// }
int Mapa::ValidarMovimentacao(int x, int y) {
    if (x >= get_num_linhas() || y >= get_num_colunas() || x < 0 || y < 0)
        return -1;

    int tipoOcupacao = GetMazeSquare(x, y).get_tipo_ocupado();
    return tipoOcupacao == 1 ? -1 : tipoOcupacao;
}