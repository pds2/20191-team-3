//Crie uma nova classe que representa o seu " calabouço " como uma matriz bi- dimensional 


class CDungeon
{
    public:
        CDungeon()
        { //Criar uma mazechar vazio caaMaze 
        [ 10] [11 ] = {" ******* *** " , " ****** " , " ***** " , " ** " , " ****** " , " *** **** "," **** "," **** "," ****** "," ********** " }; 
        for (unsigned int uiRow = 0; uiRow < 10; + +uiRow) {
            for (unsigned int uiCol = 0; uiCol < 10; + +uiCol) {
                mcaaMaze[uiRow][uiCol] = caaMaze[uiRow][uiCol];
            }
        }
        }
        caractere GetMazeSquare(unsigned int uiRow, unsigned int uiCol) { return mcaaMaze[uiRow][uiCol]; }
    private:
        char mcaaMaze[10][10];
}
;
