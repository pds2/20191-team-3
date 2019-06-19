#include <iostream>
#include <time.h>  
#include <map>
#include "game.h"
#include "color.h"

using namespace std;

/*Esta classe controla o movimento dos seu heróis. 
Você usa "W ", "A", "S" e "Z" para mover o seu personagem . 
Ele também gera 10 monstros e seu heróis dentro de sua " Dungeon (Masmorra) " e controla as interações 
entre eles , como mortes e posições.*/

CRolePlayingGame::CRolePlayingGame()
{
	//Seta jogo para jogando
    gameOver = false;
    //Cria os personagens e setam eles em uma posicao aleatoria no mapa
    this->map = Mapa("mapa_ch12.txt");
    CriarListaHerois(true);
    CriarListaHerois(false);
}

void CRolePlayingGame::CriarListaHerois(bool heroi) {
    vector<string> lista;
    string pasta;
    if (heroi) {
        lista = {"Eliwood", "Lyn", "Wil", "Hector", "Raven", "Florina", "Dorcas", "Wallace", "Sain", "Erk"};
        pasta = "Entradas/Personagens/";
    } 
    else {
        lista = {"Batta", "Beyard", "Damian", "Glass", "Heintz", "Lundgren", "Migal", "Yogi", "Zagan", "Zugu"};
        pasta = "Entradas/Inimigos/";
    }
    
    for (unsigned int i = 0; i < lista.size(); i++)
    {
        ifstream infile;
        infile.open(pasta + lista[i] + ".txt");
        if (infile.is_open())
        {
            string nome, classe;
            int hp, str, skl, spd, lck, def, res;
            infile >> nome >> classe >> hp >> str >> skl >> spd >> lck >> def >> res;
            unsigned int rng_i, rng_j;
            do
            {
                rng_i = rand() % map.get_num_linhas();
                rng_j = rand() % map.get_num_colunas();
            } while (map.GetMazeSquare(rng_i, rng_j).get_ocupado() == true);

            if (heroi) {
                Heroi *p = new Heroi(nome, classe, hp, str, skl, spd, lck, def, res, true);
                p->set_i(rng_i);
                p->set_j(rng_j);
                p->set_usavel(true);
                AddArmasPersonagem(*p);
                _lista_herois.insert(pair<string, Heroi *>(p->get_nome(), p));
            }
            else {
                Monstro *p = new Monstro(nome, classe, hp, str, skl, spd, lck, def, res, true);
                p->set_i(rng_i);
                p->set_j(rng_j);
                AddArmasPersonagem(*p);
                _lista_monstros.insert(pair<string, Monstro *>(p->get_nome(), p));
            }
            
            map.set_ocupacao_terreno(rng_i, rng_j, 1);
            map.toggle_ocupado(rng_i, rng_j, true);
        }
        infile.close();
    }
}

void AddArmasPersonagem(Heroi &p) {
    if (p.get_Classe() == "Mercenary")
            {
                Arma a1 = Arma("Iron Sword");
                Arma a2 = Arma("Steel Sword");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
            }
            else if (p.get_Classe() == "Lord")
            {
                Arma a1 = Arma("Killer Axe");
                Arma a2 = Arma("Killing Edge");
                Arma a3 = Arma("Steel Sword");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
                p.Add_Arma(a3);
            }
            else if (p.get_Classe() == "General")
            {
                Arma a1 = Arma("Steel Lance");
                Arma a2 = Arma("Iron Axe");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
            }
            else if (p.get_Classe() == "Pegasus Knight")
            {
                Arma a1 = Arma("Steel Lance");
                Arma a2 = Arma("Killer Lance");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
            }
            else if (p.get_Classe() == "Paladin")
            {
                Arma a1 = Arma("Steel Sword");
                Arma a2 = Arma("Iron Lance");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
            }
            else if (p.get_Classe() == "Archer")
            {
                Arma a1 = Arma("Iron Bow");
                Arma a2 = Arma("Steel Bow");
                Arma a3 = Arma("Killer Bow");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
                p.Add_Arma(a3);
            }
            else if (p.get_Classe() == "Mage")
            {
                Arma a1 = Arma("Fire");
                Arma a2 = Arma("Thunder");
                Arma a3 = Arma("Aura");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
                p.Add_Arma(a3);
            }
            else if (p.get_Classe() == "Warrior")
            {
                Arma a1 = Arma("Steel Axe");
                Arma a2 = Arma("Killer Axe");
                p.Add_Arma(a1);
                p.Add_Arma(a2);
            }
}

void AddArmasPersonagem(Monstro &p) {
    if (p.get_Classe() == "Mercenary")
            {
                Arma a = Arma("Iron Sword");
                p.Add_Arma(a);
            }
            else if (p.get_Classe() == "Lord")
            {
                Arma a = Arma("Steel Sword");
                p.Add_Arma(a);
            }
            else if (p.get_Classe() == "General")
            {
                Arma a = Arma("Steel Lance");
                p.Add_Arma(a);
            }
            else if (p.get_Classe() == "Pegasus Knight")
            {
                Arma a = Arma("Steel Lance");
                p.Add_Arma(a);
            }
            else if (p.get_Classe() == "Paladin")
            {
                Arma a = Arma("Steel Sword");
                p.Add_Arma(a);
            }
            else if (p.get_Classe() == "Archer")
            {
                Arma a = Arma("Iron Bow");
                p.Add_Arma(a);
            }
            else if (p.get_Classe() == "Mage")
            {
                Arma a = Arma("Fire");
                p.Add_Arma(a);
            }
            else if (p.get_Classe() == "Warrior")
            {
                Arma a = Arma("Steel Axe");
                p.Add_Arma(a);
            }
}

// int CRolePlayingGame::QueryLocation(unsigned int uiRow, unsigned int uiCol)
// {
//     return map.GetMazeSquare(uiRow, uiCol).get_tipo_ocupado();
// }

// void CRolePlayingGame::printboard(int _i, int _j)
// {
//     // for(unsigned int uiRow = 0; uiRow < (unsigned)map.get_num_linhas(); ++uiRow){
//     //     for(unsigned int uiCol = 0; uiCol < (unsigned)map.get_num_colunas(); ++uiCol){
//     //         QueryLocation(uiRow, uiCol);
//     //     }
//     //     cout<<endl;
//     // }
//     for (unsigned int uiRow = 0; uiRow < (unsigned)map.get_num_linhas(); ++uiRow) {
//         for (unsigned int uiCol = 0; uiCol < (unsigned)map.get_num_colunas(); ++uiCol) {
//             int tipoOcupacao = QueryLocation(uiRow, uiCol);
//             if(tipoOcupacao == 0){
//                 cout << cor.greenPrint("*");
//             }
//             else if(tipoOcupacao == 1){
//                 if(uiRow == (unsigned)_i && uiCol == (unsigned)_j){
//                     cout << cor.BbluePrint(map.getHeroiPorPosicao(uiRow, uiCol)->get_nome().substr(0,1));
//                 }else{
//                     cout << cor.bluePrint(map.getHeroiPorPosicao(uiRow, uiCol)->get_nome().substr(0,1));
//                 }
                
//             }
//             else if(tipoOcupacao == 2){
//                 cout << cor.redPrint("M");
//             }
//         }
//         cout << endl;
//     }
// }

void CRolePlayingGame::AllMonstersDead()
{
    if(_lista_monstros.size() == 0){
        std::cout << "Você Venceu! " << std::endl;
        this->gameOver = true;
    }
}

void CRolePlayingGame::AllHeroesisDead()
{
    if(_lista_herois.size() == 0){
        std::cout << "Você Perdeu! " << std::endl;
        this->gameOver = true;
    }
}

// bool CRolePlayingGame::TerrenoComparator(Terreno &terreno1, Terreno &terreno2) {
//     if (terreno1.get_tipo_ocupado() == terreno2.get_tipo_ocupado())
//         return true;
//     return false;
// }

Mapa CRolePlayingGame::getMapa() {
    return this->map;
}

map<string, Heroi *> CRolePlayingGame::get_lista_herois()
{
    return this->_lista_herois;
}

map<string, Monstro *> CRolePlayingGame::get_lista_monstros()
{
    return this->_lista_monstros;
}

Heroi *CRolePlayingGame::getHeroiPorPosicao(int x, int y)
{
    for (std::map<string, Heroi *>::iterator it = this->_lista_herois.begin(); it != this->_lista_herois.end(); it++)
    {
        if (it->second->get_i() == x && it->second->get_j() == y)
            return it->second;
    }

    throw runtime_error("Nenhum personagem na posição.");
    return NULL;
}

bool CRolePlayingGame::Batalha(string nomeHeroi, int x, int y)
{
    Heroi *Atacante = _lista_herois[nomeHeroi];
    Monstro *Defensor = getMonstroPorPosicao(x, y);
    //Gera quatro números aleatótios de 0 a 99
    //Valores de hit e crit do atacante
    int hitA = rand() % 100;
    int critA = rand() % 100;

    //Valores de hit e crit do defensor
    int hitD = rand() % 100;
    int critD = rand() % 100;

    //Valores de terreno
    Terreno tA = map.GetMazeSquare(Atacante->get_i(), Atacante->get_j());
    Terreno tD = map.GetMazeSquare(Defensor->get_i(), Defensor->get_j());

    //Bonus de triângulo de armas (Sword > Axe > Lance > Sword)
    srand(time(NULL));
    int bonusA = Atacante->Hit();
    int bonusD = Defensor->Hit();
    string tipo_arma_A = Atacante->Arma_Equipada().get_tipo();
    string tipo_arma_D = Defensor->Arma_Equipada().get_tipo();
    if ((tipo_arma_A == "Sword" && tipo_arma_D == "Axe") || (tipo_arma_A == "Lance" && tipo_arma_D == "Sword") || (tipo_arma_A == "Axe" && tipo_arma_D == "Lance"))
    {
        bonusA += 4;
    }
    else if ((tipo_arma_D == "Sword" && tipo_arma_A == "Axe") || (tipo_arma_D == "Lance" && tipo_arma_A == "Sword") || (tipo_arma_D == "Axe" && tipo_arma_A == "Lance"))
    {
        bonusD += 4;
    }

    int defesaA, defesaD;
    if (Atacante->Arma_Equipada().get_tipo() == "Tome")
        defesaD = Defensor->get_Res();
    else
        defesaD = Defensor->get_Def();

    if (Defensor->Arma_Equipada().get_tipo() == "Tome")
        defesaA = Atacante->get_Res();
    else
        defesaA = Atacante->get_Def();

    //Primeiro ataque
    if (hitA < bonusA - Defensor->Avo() - tD.get_avoid())
    {
        int dano;
        if (critA > Atacante->Crit())
            dano = (Atacante->Atk() - defesaD - tD.get_defense()) * 3;
        else
            dano = Atacante->Atk() - defesaD - tD.get_defense();
        if (dano > 0)
        {
            int HP = Defensor->get_HP() - dano;
            cout << Atacante->get_nome() <<" aplicou " << dano << " pontos de dano!" <<endl;
            if (HP <= 0) //Se defensor morreu
            {
                Defensor->set_HP(0);
                cout << Defensor->get_nome() << " derrotado." << endl;
                
                map.set_ocupacao_terreno(Atacante->get_i(), Atacante->get_j(), 0);
                map.toggle_ocupado(Atacante->get_i(), Atacante->get_j(), false);

                map.set_ocupacao_terreno(Defensor->get_i(), Defensor->get_j(), 1);
                map.toggle_ocupado(Defensor->get_i(), Defensor->get_j(), true);

                _lista_monstros.erase(Defensor->get_nome());

                return true;
            }
        }
    }
    //Contra-ataque
    if (hitD < bonusD - Atacante->Avo() - tA.get_avoid())
    {
        int dano;
        if (critD > Atacante->Crit())
            dano = (Defensor->Atk() - defesaA - tA.get_defense()) * 2;
        else
            dano = Defensor->Atk() - defesaA - tA.get_defense();
        if (dano > 0)
        {
            int HP = Atacante->get_HP() - dano;
            cout << Defensor->get_nome() <<" aplicou " << dano << " pontos de dano!" <<endl;
            if (HP <= 0) //Se atacante morreu
            {
                Atacante->set_HP(0);
                cout << Atacante->get_nome() << " derrotado." << endl;
                
                map.set_ocupacao_terreno(Atacante->get_i(), Atacante->get_j(), 0);
                map.toggle_ocupado(Atacante->get_i(), Atacante->get_j(), false);

                _lista_herois.erase(Atacante->get_nome());
                
                return true;
            }
        }
    }
    //Se um personagem tem velocidade maior que o outro, ele ataca novamente
    if (Atacante->get_Spd() - Defensor->get_Spd() >= 4)
    {
        hitA = rand() % 100;
        critA = rand() % 100;
        if (hitA < bonusA - Defensor->Avo() - tD.get_avoid())
        {
            int dano;
            if (critA > Atacante->Crit())
                dano = (Atacante->Atk() - defesaD - tD.get_defense()) * 2;
            else
                dano = Atacante->Atk() - defesaD - tD.get_defense();
            if (dano > 0)
            {
                int HP = Defensor->get_HP() - dano;
                cout << Atacante->get_nome() <<" aplicou um double attack!" <<endl;
                cout << Atacante->get_nome() <<" aplicou " << dano << " pontos de dano!" <<endl;
                if (HP <= 0) //Se defensor morreu
                {
                    Defensor->set_HP(0);
                    cout << Defensor->get_nome() << " derrotado." << endl;
                    
                    map.set_ocupacao_terreno(Atacante->get_i(), Atacante->get_j(), 0);
                    map.toggle_ocupado(Atacante->get_i(), Atacante->get_j(), false);

                    map.set_ocupacao_terreno(Defensor->get_i(), Defensor->get_j(), 1);
                    map.toggle_ocupado(Defensor->get_i(), Defensor->get_j(), true);

                    _lista_monstros.erase(Defensor->get_nome());
                    
                    return true;
                }
            }
        }
    }
    else if (Defensor->get_Spd() - Atacante->get_Spd() >= 4)
    {
        hitD = rand() % 100;
        critD = rand() % 100;
        if (hitD < bonusD - Atacante->Avo() - tA.get_avoid())
        {
            int dano;
            if (critD > Atacante->Crit())
                dano = (Defensor->Atk() - defesaA - tA.get_defense()) * 3;
            else
                dano = Defensor->Atk() - defesaA - tA.get_defense();
            if (dano > 0)
            {
                int HP = Atacante->get_HP() - dano;
                if (HP <= 0) //Se atacante morreu
                {
                    Atacante->set_HP(0);
                    cout << Atacante->get_nome() << " derrotado." << endl;

                    map.set_ocupacao_terreno(Atacante->get_i(), Atacante->get_j(), 0);
                    map.toggle_ocupado(Atacante->get_i(), Atacante->get_j(), false);

                    _lista_herois.erase(Atacante->get_nome());
                   
                    return true;
                }
            }
        }
    }
    return false; //Se ninguém morreu
}

void CRolePlayingGame::printboard(int _i, int _j)
{
    for (unsigned int uiRow = 0; uiRow < (unsigned)map.get_num_linhas(); ++uiRow) {
        for (unsigned int uiCol = 0; uiCol < (unsigned)map.get_num_colunas(); ++uiCol) {
            Terreno terreno = map.GetMazeSquare((int)uiRow, (int)uiCol);
            int tipoOcupacao = terreno.get_tipo_ocupado();
            if(tipoOcupacao == 0){
                cout << cor.greenPrint("*");
            }
            else if(tipoOcupacao == 1){
                if(uiRow == (unsigned)_i && uiCol == (unsigned)_j){
                    cout << cor.BbluePrint(getHeroiPorPosicao(uiRow, uiCol)->get_nome().substr(0,1));
                }else{
                    cout << cor.bluePrint(getHeroiPorPosicao(uiRow, uiCol)->get_nome().substr(0,1));
                }
                
            }
            else if(tipoOcupacao == 2){
                cout << cor.redPrint("M");
            }
        }
        cout << endl;
    }
}

void CRolePlayingGame::AtualizarDestinoMovimentacao(int &uiNextRow, int &uiNextCol, char kcDirection) {
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
    }
}

void CRolePlayingGame::RealizarMovimentacao(string nomeHeroi, int x, int y) {
    int xAntigo = _lista_herois[nomeHeroi]->get_i();
    int yAntigo = _lista_herois[nomeHeroi]->get_j();
    _lista_herois[nomeHeroi]->Move(x, y);

    map.set_ocupacao_terreno(xAntigo, yAntigo, 0);
    map.toggle_ocupado(xAntigo, yAntigo, false);
    map.set_ocupacao_terreno(x, y, 1);
    map.toggle_ocupado(x, y, true);
}

Monstro* CRolePlayingGame::getMonstroPorPosicao(int x, int y) {
    for (std::map<string, Monstro *>::iterator it = this->_lista_monstros.begin(); it != this->_lista_monstros.end(); it++)
    {
        if (it->second->get_i() == x && it->second->get_j() == y)
            return it->second;
    }

    throw runtime_error("Nenhum personagem na posição.");
    return NULL;   
}

void CRolePlayingGame::MovimentarMonstros() {
    for (std::map<string, Monstro *>::iterator it = this->_lista_monstros.begin(); it != this->_lista_monstros.end(); it++)
    {
        int rng_i, rng_j;
        do
        {
            rng_i = rand() % map.get_num_linhas();
            rng_j = rand() % map.get_num_colunas();
        } while (map.GetMazeSquare(rng_i, rng_j).get_ocupado() == true);
        it->second->Move(rng_i, rng_j);
    }
}