#pragma once
#ifndef MAPA_H_
#define MAPA_H_

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>
#include "terreno.h"
#include "heroi.h"
#include "arma.h"

using namespace std;

class Mapa
{
private:
	string _nome;
	vector<vector<Terreno>> _grade; //Matriz de terrenos que compõe o mapa
	int _num_linhas;
	int _num_colunas;

public:
	Mapa();
	//Construtor, string nome é o nome do arquivo de entrada
	Mapa(string nome);

	void imprime(); //Imprime o mapa como uma matriz de caracteres
	int get_num_linhas();
	int get_num_colunas();
	Terreno GetMazeSquare(unsigned int uiRow, unsigned int uiCol); // Retorna a posição procurada no mapa
	void set_ocupacao_terreno(int x, int y, int tipoOcupacao);
	void toggle_ocupado(int x, int y, bool ocupado);
	int ValidarMovimentacao(int x, int y);
};

#endif