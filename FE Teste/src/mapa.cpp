#include "mapa.h"

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

void Mapa::cria_lista_personagens()
{
    vector<string> lista = {"Eliwood", "Lyn", "Wil", "Hector", "Raven", "Florina", "Dorcas", "Wallace", "Marcus", "Erk"};
    for (unsigned int i = 0; i < lista.size(); i++)
    {
        string pasta = "Entradas/Personagens/";
        ifstream infile;
        infile.open(pasta + lista[i] + ".txt");
        if (infile.is_open())
        {
            string nome, classe;
            int hp, str, skl, spd, lck, def, res;
            infile >> nome >> classe >> hp >> str >> skl >> spd >> lck >> def >> res;
            Personagem *p = new Personagem(nome, classe, hp, str, skl, spd, lck, def, res);
            p->set_i(_num_linhas - 1);
            p->set_j(i);
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
            _lista_personagens.insert(pair<string, Personagem *>(p->get_Nome(), p));
            _grade[p->get_i()][p->get_j()].muda_ocupacao(true);
        }
        infile.close();
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