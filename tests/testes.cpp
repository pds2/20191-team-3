#include "doctest.h"
#include"color.h"
#include "arma.h"
#include "game.h"
#include "healingitem.h"
#include "item.h"
#include "mapa.h"
#include "personagem.h"
#include "terreno.h"
//incluir todos .h

#include "string"
#include "map"

TEST_CASE("01 - Testando Construtor com parametros válidos Heroi/Monstro"){
	CHECK_NOTHROW(Heroi("Dorcas", "Lord", 10, 15, 20, 25, 30, 35, 40, true));
	CHECK_NOTHROW(Monstro("Batta", "Lord", 10, 15, 20, 25, 30, 35, 40, true));
}

TEST_CASE("02 - Testando Heranca Heroi"){
	Personagem *hero = new Heroi("Dorcas", "Lord", 10, 15, 20, 25, 30, 35, 40, true);
	hero->Move(1, 2);
	CHECK(hero->get_i == 1);
	CHECK(hero->get_j == 2);
	delete hero;
}

TEST_CASE("03 - Checando o acesso aos atributos da classe base pela classe derivada"){
	Personagem *hero = new Heroi("Dorcas", "Lord", 10, 15, 20, 25, 30, 35, 40, true);
	CHECK(hero->get_nome == "Dorcas");
	Personagem *monstro = new Monstro("Batta", "Lord", 10, 15, 20, 25, 30, 35, 40, true);
	CHECK(monstro->get_nome == "Batta");
	delete hero;
	delete monstro;
}

TEST_CASE("04 - Checando construtor Mapa") {
	CHECK_NOTHROW(Mapa("mapa_ch12.txt");
}