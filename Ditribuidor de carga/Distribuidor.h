
#ifndef Distribuidor_H
#define Distribuidor_H
#include <string>
#include <vector>
using namespace std;
const int NUMPCS = 4;

class Distribuidor
{

private:
	int n; // n que nos da el cliente
	double velocidad[4];//velocidades computadoras
	int pesos[4]; // pesos del 1 al 4  si en una posicion regreso -1 hay que testear esa pc
	string texto; 
	string textolimpio;
	int tamTexto;
	vector<string> cadenalimpiardividida;//taam 

public:
	Distribuidor(string Texto_, int n_);
	void distribuir_para_limpiar(double velocidad[]);//debe llenar el arreglo cadena limpiar dividida 
	vector<string> getCadenasLimpiarDividida();
	void concatecarCadenalimpia(string pc1, string pc2, string pc3, string pc4);//lo concatena a texto limpio
	string getTextoLimpio();
	int * getPesos(double velocidad[], bool disponibilidad[] ); //regresa el arrrglo de numero de pesos;
};

#endif