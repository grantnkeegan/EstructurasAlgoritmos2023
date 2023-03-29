// Esta clase es para poder crear objetos de los casos del archivo .txt.
#include <string>
#include <vector>
using namespace std;

class Bitacora
{
    // Defnimos las variables de la clase.
    private:
    vector<string> registros;
    vector<string> fechas;
    string mes, dia, hora, min, seg, ip, razon;
    string inicio, fin;

    // Definimos los metodos de la clase.
    public:
    Bitacora();
    void leer();
    void ordenar_efectivo(); // Metodo para el Bubble Sort.
    void ordenar_poco_efectivo();
    void verificar_fechas();
    void buscar_fechas();
    void imprimir(); // Imprime los resultados en un archivo .txt.
    void imprimirN();
};