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
	// map<string, Heroi *> _lista_personagens; //Lista de personagens e inimigos
	// Heroi cria_personagem(string _nome);	 //Método de criação de personagens
	// void cria_lista_personagens();

public:
	Mapa();
	//Construtor, string nome é o nome do arquivo de entrada
	Mapa(string nome);

	void imprime(); //Imprime o mapa como uma matriz de caracteres
	// void imprime_personagem(string nome);
	// void equip_armas(string nome); //Cria as armas e as equipam ao personagem
	int get_num_linhas();
	int get_num_colunas();
	Terreno GetMazeSquare(unsigned int uiRow, unsigned int uiCol); // Retorna a posição procurada no mapa
	// Heroi get_personagem(string nome);
	// bool Batalha(Heroi &Atacante, Heroi &Defensor); //Retorna true se alguém morre e false se ninguém morre
	// map<string, Heroi*> get_lista_personagens();
	// map<string, Heroi*> get_lista_personagens(bool heroi);
	// Heroi* getHeroiPorPosicao(int x, int y);
	void set_ocupacao_terreno(int x, int y, int tipoOcupacao);
	void toggle_ocupado(int x, int y, bool ocupado);
	int ValidarMovimentacao(int x, int y);
	// void setPosHeroi(string nome, int x, int y);
};

#endif