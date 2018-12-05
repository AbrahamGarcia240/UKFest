#include "Distribuidor.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;


int main()
{
	string texto = "Las frases palindrómicas se resienten en su significado cuanto más largas son";
	int n = 25;
	vector<string> cadena;

	double velocidades[4];
	velocidades[0] = 230;
	velocidades[1] = 206;
	velocidades[2] = 795;
	velocidades[3] = 274;

	bool disponibilidad[4];
	disponibilidad[0] = true;
	disponibilidad[1] = true;
	disponibilidad[2] = true;
	disponibilidad[3] = true;


	Distribuidor distribuidor(texto, n);

	distribuidor.distribuir_para_limpiar(velocidades);
	cadena=distribuidor.getCadenasLimpiarDividida();
	cout << cadena[0]+"\n" << cadena[1]+"\n" << cadena[2]+"\n" << cadena[3]+"\n" <<endl; 


	int pesos[4];
	memcpy(pesos,distribuidor.getPesos(velocidades, disponibilidad), 4 * sizeof(int));

	printf("%d\n",pesos[0] );
	printf("%d\n",pesos[1] );
	printf("%d\n",pesos[2] );
	printf("%d\n",pesos[3] );

	return 0;
}