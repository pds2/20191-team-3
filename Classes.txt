Link para informações de informações do jogo: https://serenesforest.net/blazing-sword/

Classe Personagem:
  Atributos:
  String Nome     Item Iventário[5]
  int HP Max      int Arma Equipada
  int HP Atual    bool Player
  int Strengh
  int Skill
  int Speed
  int Luck
  int Defense
  int Resistence
  
Classes classes de batalha: 
  Atributos: (String Nome, int Move, bool Tipo de armas[5] = true pode usar, false não pode)

Mercenary: (Arma = Sword; Move = 6) 
Cavalier: (Armas = Sword, Lance; Move = 8) 
Warrior: (Arma = Axe; Move = 6)
Archer: (Arma = Bow; Move = 5)
Mage: (Arma = Tome; Move = 6)
Pegasus Knight: (Arma = Lance; Move = 7)
Lord: (Armas = Sword, Axe; Move = 6)
General: (Armas = Axe, Lance; Move = 5)

Interface Item:
exibir_status();

Classe Arma:
  String Nome
  String Tipo
  int Attack
  int Hit
  int Crit
  int Range Min
  int Range Max
  
Classe Healing Item:
  String Nome: (Potion, Elixir)
  String Status: (Potion recupera 10 HP, Elixir recupera 20 HP)
  
Classe Terreno:
  String Nome
  int Avoid
  int Defense
  bool Ocupado
  
Plain: (Avo = 0, Def = 0)
Forest: (Avo = 20, Def = 1)
Mountain: (Avo = 30, Def = 1)
Fort: (Avo = 20, Def = 2)

Classe Mapa:
  Matriz Terreno
  Map<String Nome, (int Pos_i, int Pos_j, bool Usavel)>
  
Link de exemplos de mapas: https://serenesforest.net/blazing-sword/miscellaneous/chapter-maps/
