#pragma once
#include <iostream>

//Crie uma nova classe que representa o seu " calabouço " como uma matriz bi- dimensional 


class CDungeon
{
    private:
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
        char GetMazeSquare(unsigned int uiRow, unsigned int uiCol);
};
