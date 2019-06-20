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

void Mapa::set_ocupacao_terreno(int x, int y, int tipoOcupacao)
{
    this->_grade[x][y].set_tipo_ocupacao(tipoOcupacao);
}

void Mapa::toggle_ocupado(int x, int y, bool ocupado)
{
    this->_grade[x][y].set_ocupacao(ocupado);
}

int Mapa::ValidarMovimentacao(int x, int y) {
    if (x >= get_num_linhas() || y >= get_num_colunas() || x < 0 || y < 0)
        return -1;

    int tipoOcupacao = GetMazeSquare(x, y).get_tipo_ocupado();
    return tipoOcupacao == 1 ? -1 : tipoOcupacao;
}