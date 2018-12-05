#include "Distribuidor.h"
using namespace std;
#include <iostream>

Distribuidor::Distribuidor(string Texto_, int n_)
{
	texto = Texto_;
	n = n_; 
	tamTexto = Texto_.size();
} 

void Distribuidor::distribuir_para_limpiar(double velocidad[])
{
	double minimo = velocidad[0], pcs[NUMPCS], TotalPCS = 0;
	int cantidadxPC, aux[NUMPCS], total = 0;
	register int i;

	for(i = 1; i < NUMPCS; i++)
		if(velocidad[i] < minimo)
			minimo = velocidad[i];

	for(i = 0; i < NUMPCS; i++ )
		pcs[i] = minimo / velocidad[i]; 

	for(i = 0; i < NUMPCS; i++ )
		TotalPCS += pcs[i];
	
	cantidadxPC = tamTexto/TotalPCS;

	
	aux[0] = pcs[0]*cantidadxPC;
	cadenalimpiardividida.push_back(texto.substr(0, aux[0]));
	total += aux[0];

	for(i = 1; i < NUMPCS - 1; i++ )
	{
		aux[i] = pcs[i]*cantidadxPC;
		cadenalimpiardividida.push_back(texto.substr(total + 1, aux[i]));
		total += aux[i];
	}

	aux[NUMPCS - 1] = pcs[NUMPCS - 1] * cantidadxPC;
	cadenalimpiardividida.push_back(texto.substr(total, tamTexto - total ));

}


vector<string> Distribuidor::getCadenasLimpiarDividida()
{	
	return cadenalimpiardividida;
}

void Distribuidor::concatecarCadenalimpia(string pc1, string pc2, string pc3, string pc4)
{
	textolimpio = pc1 + pc2 + pc3 + pc4; 
}


string Distribuidor::getTextoLimpio()
{
	return textolimpio;
}

int * Distribuidor::getPesos(double velocidad[], bool disponibilidad[])
{
	double minimo = 0x00000000ffffffff, TotalPCS = 0;
	int cantidadxPC, indiceFinal, total = 0;
	register int i;
	int *pesos =(int *)malloc(sizeof(int) * NUMPCS);
	int indiceveloz;

	for(i = 0; i < NUMPCS; i++)
		if(disponibilidad[i])
			if(velocidad[i] < minimo)
			{
				minimo = velocidad[i];
				indiceveloz = i;
			}

	double pcs[NUMPCS];
	for(i = 0; i < NUMPCS; i++ )
		pcs[i] = minimo / velocidad[i];

	for(i = 0; i < NUMPCS; i++ )
		if(disponibilidad[i])
			TotalPCS += pcs[i];

	cantidadxPC = n/TotalPCS;
	printf("N:%d\n", n);

	for(i = 0; i < NUMPCS; i++ )
	{
		if(!disponibilidad[i])
			pesos[i] = 0;
		else
		{
			pesos[i] = pcs[i] * cantidadxPC;
			total += pesos[i];
		}
	}

	pesos[indiceveloz] += n - total;
	return pesos;
}