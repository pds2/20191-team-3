#include "mapa.h"

//Crie uma nova classe que representa o seu " calabouço " como uma matriz bi- dimensional 


CDungeon::CDungeon(){ //Criar uma mazechar vazio caaMaze 
    for (unsigned int uiRow = 0; uiRow < 10; ++uiRow) {
        for (unsigned int uiCol = 0; uiCol < 10; ++uiCol) {
            mcaaMaze[uiRow][uiCol] = mcaaMaze[uiRow][uiCol];
        }
    }
}

char CDungeon::GetMazeSquare(unsigned int uiRow, unsigned int uiCol){ 
    return mcaaMaze[uiRow][uiCol]; 
}
