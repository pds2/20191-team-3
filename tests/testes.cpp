#include "doctest.h"
#include"color.h"
#include "arma.h"
#include "game.h"
#include "healingitem.h"
#include "item.h"
#include "mapa.h"
#include "personagem.h"
#include "terreno.h"
#include "heroi.h"
#include "monstro.h"
//incluir todos .h

#include "string"
#include "map"

TEST_CASE("01 - Testando Construtor com parametros válidos Heroi/Monstro"){
	CHECK_NOTHROW(Heroi("Dorcas", "Lord", 10, 15, 20, 25, 30, 35, 40, true));
	CHECK_NOTHROW(Monstro("Batta", "Lord", 10, 15, 20, 25, 30, 35, 40, true));
}

TEST_CASE("02 - Testando Heranca Heroi"){
	Arma *gun = new Arma("pistol","gun",10,11,12,13,14);
	CHECK(gun->get_attack() ==  10);
}

TEST_CASE("03 - Checando o acesso aos atributos da classe base pela classe derivada"){
	Personagem *hero  = new Heroi("Dorcas", "Lord", 10, 15, 20, 25, 30, 35, 40, true);
	
	CHECK(hero->IsDead() == false);
	hero->set_HP(0);
	CHECK(hero->get_HP() == 0);
	CHECK(hero->IsDead() == true);
	
	Personagem *m = new Monstro("Batta","Lord", 10, 15, 20, 25, 30, 35, 40, false);
	CHECK(m->IsDead() == false);
	CHECK(m->get_HP() == 10);
	CHECK(m->get_nome() == "Batta");

}

TEST_CASE("04 - Checando construtor Mapa") {
	CHECK_NOTHROW(Mapa("mapa_ch12.txt"));
}

TEST_CASE("05 - Checando construtor Terreno"){
	CHECK_NOTHROW(Terreno('P'));
}

TEST_CASE("06 - Checando classe Terreno"){
	Terreno ter('P');
	CHECK(ter.get_nome() == '_');
	CHECK(ter.get_avoid() == 0);
	ter.set_ocupacao(true);
	CHECK(ter.get_ocupado() == true);
}
