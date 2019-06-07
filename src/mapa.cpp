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
        cout << _num_linhas << "x" << _num_colunas << endl;
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

    cria_lista_personagens();
}

void Mapa::cria_lista_personagens()
{
    vector<string> lista1 = {"Eliwood", "Lyn", "Wil", "Hector", "Raven", "Florina", "Dorcas", "Wallace", "Sain", "Erk"};
    vector<string> lista2 = {"Batta", "Beyard", "Damian", "Glass", "Heintz", "Lundgren", "Migal", "Yogi", "Zagan", "Zugu"};
    string pasta1 = "Entradas/Personagens/";
    string pasta2 = "Entradas/Inimigos/";
    for (unsigned int i = 0; i < lista1.size(); i++)
    {
        ifstream infile;
        infile.open(pasta1 + lista1[i] + ".txt");
        if (infile.is_open())
        {
            string nome, classe;
            int hp, str, skl, spd, lck, def, res;
            infile >> nome >> classe >> hp >> str >> skl >> spd >> lck >> def >> res;
            Personagem *p = new Personagem(nome, classe, hp, str, skl, spd, lck, def, res, true);
            unsigned int rng_i, rng_j;
            do
            {
                rng_i = rand() % _num_linhas;
                rng_j = rand() % _num_colunas;
            } while (_grade[rng_i][rng_j].get_ocupado() == true);
            p->set_i(rng_i);
            p->set_j(rng_j);
            p->set_usavel(true);
            if (p->get_Classe() == "Mercenary")
            {
                Arma a1 = Arma("Iron Sword");
                Arma a2 = Arma("Steel Sword");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
            }
            else if (p->get_Classe() == "Lord")
            {
                Arma a1 = Arma("Killer Axe");
                Arma a2 = Arma("Killing Edge");
                Arma a3 = Arma("Steel Sword");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
                p->Add_Arma(a3);
            }
            else if (p->get_Classe() == "General")
            {
                Arma a1 = Arma("Steel Lance");
                Arma a2 = Arma("Iron Axe");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
            }
            else if (p->get_Classe() == "Pegasus Knight")
            {
                Arma a1 = Arma("Steel Lance");
                Arma a2 = Arma("Killer Lance");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
            }
            else if (p->get_Classe() == "Paladin")
            {
                Arma a1 = Arma("Steel Sword");
                Arma a2 = Arma("Iron Lance");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
            }
            else if (p->get_Classe() == "Archer")
            {
                Arma a1 = Arma("Iron Bow");
                Arma a2 = Arma("Steel Bow");
                Arma a3 = Arma("Killer Bow");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
                p->Add_Arma(a3);
            }
            else if (p->get_Classe() == "Mage")
            {
                Arma a1 = Arma("Fire");
                Arma a2 = Arma("Thunder");
                Arma a3 = Arma("Aura");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
                p->Add_Arma(a3);
            }
            else if (p->get_Classe() == "Warrior")
            {
                Arma a1 = Arma("Steel Axe");
                Arma a2 = Arma("Killer Axe");
                p->Add_Arma(a1);
                p->Add_Arma(a2);
            }
            _lista_personagens.insert(pair<string, Personagem *>(p->get_nome(), p));
            _grade[p->get_i()][p->get_j()].set_ocupacao(true);
            _grade[p->get_i()][p->get_j()].set_tipo_ocupacao(1);
        }
        infile.close();

        infile.open(pasta2 + lista2[i] + ".txt");
        if (infile.is_open())
        {
            string nome, classe;
            int hp, str, skl, spd, lck, def, res;
            infile >> nome >> classe >> hp >> str >> skl >> spd >> lck >> def >> res;
            Personagem *p = new Personagem(nome, classe, hp, str, skl, spd, lck, def, res, false);
            unsigned int rng_i, rng_j;
            do
            {
                rng_i = rand() % _num_linhas;
                rng_j = rand() % _num_colunas;
            } while (_grade[rng_i][rng_j].get_ocupado() == true);
            p->set_i(rng_i);
            p->set_j(rng_j);
            p->set_usavel(true);
            if (p->get_Classe() == "Mercenary")
            {
                Arma a = Arma("Iron Sword");
                p->Add_Arma(a);
            }
            else if (p->get_Classe() == "Lord")
            {
                Arma a = Arma("Steel Sword");
                p->Add_Arma(a);
            }
            else if (p->get_Classe() == "General")
            {
                Arma a = Arma("Steel Lance");
                p->Add_Arma(a);
            }
            else if (p->get_Classe() == "Pegasus Knight")
            {
                Arma a = Arma("Steel Lance");
                p->Add_Arma(a);
            }
            else if (p->get_Classe() == "Paladin")
            {
                Arma a = Arma("Steel Sword");
                p->Add_Arma(a);
            }
            else if (p->get_Classe() == "Archer")
            {
                Arma a = Arma("Iron Bow");
                p->Add_Arma(a);
            }
            else if (p->get_Classe() == "Mage")
            {
                Arma a = Arma("Fire");
                p->Add_Arma(a);
            }
            else if (p->get_Classe() == "Warrior")
            {
                Arma a = Arma("Steel Axe");
                p->Add_Arma(a);
            }
            _lista_personagens.insert(pair<string, Personagem *>(p->get_nome(), p));
            _grade[p->get_i()][p->get_j()].set_ocupacao(true);
            _grade[p->get_i()][p->get_j()].set_tipo_ocupacao(2);
        }
        infile.close();
    }
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

void Mapa::imprime_personagem(string nome)
{
    _lista_personagens[nome]->imprime_status();
}

Personagem Mapa::get_personagem(string nome)
{
    return *_lista_personagens[nome];
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

map<string, Personagem *> Mapa::get_lista_personagens()
{
    return this->_lista_personagens;
}

map<string, Personagem *> Mapa::get_lista_personagens(bool heroi)
{
    std::map<string, Personagem *> personagensAux;

    for (std::map<string, Personagem *>::iterator it = this->_lista_personagens.begin(); it != this->_lista_personagens.end(); it++)
    {
        if (it->second->isPlayer() == heroi)
            personagensAux.insert(make_pair(it->first, it->second));
    }

    return personagensAux;
}

Personagem *Mapa::getPersonagemPorPosicao(int x, int y)
{
    for (std::map<string, Personagem *>::iterator it = this->_lista_personagens.begin(); it != this->_lista_personagens.end(); it++)
    {
        if (it->second->get_i() == x && it->second->get_j() == y)
            return it->second;
    }

    throw runtime_error("Nenhum personagem na posição.");
    return NULL;
}

void Mapa::Batalha(Personagem &Atacante, Personagem &Defensor)
{
    //Gera quatro números aleatótios de 0 a 99
    //Valores de hit e crit do atacante
    unsigned int hitA = rand() % 100;
    unsigned int critA = rand() % 100;

    //Valores de hit e crit do defensor
    unsigned int hitD = rand() % 100;
    unsigned int critD = rand() % 100;

    //Valores de terreno
    Terreno tA = GetMazeSquare(Atacante.get_i(), Atacante.get_j());
    Terreno tD = GetMazeSquare(Defensor.get_i(), Defensor.get_j());

    //Primeiro ataque
    if (hitA > Atacante.Hit() - Defensor.Avo() - tD.get_avoid())
    {
        int dano;
        if (critA > Atacante.Crit())
            dano = (Atacante.Atk() - Defensor.get_Def() - tD.get_defense()) * 3;
        else
            dano = Atacante.Atk() - Defensor.get_Def() - tD.get_defense();
        if (dano > 0)
        {
            int HP = Defensor.get_HP() - dano;
            if (HP <= 0)
            {
                Defensor.set_HP(0);
                cout << "Inimigo derrotado." << endl;
                _lista_personagens.erase(Defensor.get_nome());
                _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
                _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);
                return;
            }
        }
    }
    //Contra-ataque
    if (hitD > Defensor.Hit() - Atacante.Avo() - tA.get_avoid())
    {
        int dano;
        if (critD > Atacante.Crit())
            dano = (Defensor.Atk() - Atacante.get_Def() - tA.get_defense()) * 3;
        else
            dano = Defensor.Atk() - Atacante.get_Def() - tA.get_defense();
        if (dano > 0)
        {
            int HP = Atacante.get_HP() - dano;
            if (HP <= 0)
            {
                Atacante.set_HP(0);
                cout << Atacante.get_nome() << " derrotado." << endl;
                _lista_personagens.erase(Atacante.get_nome());
                _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
                _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);
                return;
            }
        }
    }
    //Se um personagem tem velocidade maior que o outro, ele ataca novamente
    if (Atacante.get_Spd() - Defensor.get_Spd() >= 4)
    {
        hitA = rand() % 100;
        critA = rand() % 100;
        if (hitA > Atacante.Hit() - Defensor.Avo() - tD.get_avoid())
        {
            int dano;
            if (critA > Atacante.Crit())
                dano = (Atacante.Atk() - Defensor.get_Def() - tD.get_defense()) * 3;
            else
                dano = Atacante.Atk() - Defensor.get_Def() - tD.get_defense();
            if (dano > 0)
            {
                int HP = Defensor.get_HP() - dano;
                if (HP <= 0)
                {
                    Defensor.set_HP(0);
                    cout << "Inimigo derrotado." << endl;
                    _lista_personagens.erase(Defensor.get_nome());
                    _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
                    _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);
                    return;
                }
            }
        }
    }
    else if (Defensor.get_Spd() - Atacante.get_Spd() >= 4)
    {
        hitD = rand() % 100;
        critD = rand() % 100;
        if (hitD > Defensor.Hit() - Atacante.Avo() - tA.get_avoid())
        {
            int dano;
            if (critD > Atacante.Crit())
                dano = (Defensor.Atk() - Atacante.get_Def() - tA.get_defense()) * 3;
            else
                dano = Defensor.Atk() - Atacante.get_Def() - tA.get_defense();
            if (dano > 0)
            {
                int HP = Atacante.get_HP() - dano;
                if (HP <= 0)
                {
                    Atacante.set_HP(0);
                    cout << Atacante.get_nome() << " derrotado." << endl;
                    _lista_personagens.erase(Atacante.get_nome());
                    _grade[Atacante.get_i()][Atacante.get_j()].set_ocupacao(false);
                    _grade[Atacante.get_i()][Atacante.get_j()].set_tipo_ocupacao(0);
                    return;
                }
            }
        }
    }
}

void Mapa::set_ocupacao_terreno(int x, int y, int tipoOcupacao)
{
    this->_grade[x][y].set_tipo_ocupacao(tipoOcupacao);
}

void Mapa::toggle_ocupado(int x, int y, bool ocupado)
{
    this->_grade[x][y].set_ocupacao(ocupado);
}