#pragma once
#ifndef MAPA_H_
#define MAPA_H_

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "terreno.h"
#include "personagem.h"
#include "arma.h"

using namespace std;

class Mapa
{
private:
	string _nome;
	vector<vector<Terreno>> _grade; //Matriz de terrenos que compõe o mapa
	int _num_linhas;
	int _num_colunas;
	map<string, Personagem *> _lista_personagens; //Lista de personagens
	Personagem cria_personagem(string _nome);	 //Método de criação de personagens

public:
	//Construtor, string nome é o nome do arquivo de entrada
	Mapa(string nome);

	void imprime(); //Imprime o mapa como uma matriz de caracteres
	void cria_lista_personagens();
	void imprime_personagem(string nome);
	void equip_armas(string nome); //Cria as armas e as equipam ao personagem
	int get_num_linhas();
	int get_num_colunas();

	Terreno GetMazeSquare(unsigned int uiRow, unsigned int uiCol); // Retorna a posição procurada no mapa

	Personagem get_personagem(string nome);
};

#endif