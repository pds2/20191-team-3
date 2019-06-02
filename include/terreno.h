#include <string>

using namespace std;

class Terreno {
    private:
        string _nome;
        int _avoid;
        int _defense;
        bool _ocupado;

    public:
        enum TipoTerreno { Plain, Forest, Mountain, Fort }; //enum que lista os possíveis terrenos
        Terreno(TipoTerreno terreno); //construtor que seta os valores baseado no terreno que está sendo instanciado
        Terreno(char nome);
        char get_nome();
        int get_avoid(); //getter que busca o valor da property _avoid
        int get_defense(); //getter que busca o valor da property _defense
        bool get_ocupado(); //getter que busca o valor da property _ocupado
        void set_ocupacao(bool ocupado); //true ou false para determinar se o terreno acabou de ser ocupado/desocupado
        bool is_ocupado();

        void muda_ocupacao(bool ocupado);
};