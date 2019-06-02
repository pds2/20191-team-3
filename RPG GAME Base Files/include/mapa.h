#pragma once
#include <iostream>

//Crie uma nova classe que representa o seu " Dungeon (Masmorra) " como uma matriz bi- dimensional 


class CDungeon
{
    private: // Cria uma matriz de char para a construcao do mapa
        char mcaaMaze[11][11] = {"**********",
                                "**********",
                                "**********",
                                "**********",
                                "**********",
                                "**********",
                                "**********",
                                "**********",
                                "**********",
                                "**********"};
    public:
        CDungeon();
        char GetMazeSquare(unsigned int uiRow, unsigned int uiCol); // Retorna a posição procurada no mapa
};
