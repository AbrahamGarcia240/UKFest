#include <iostream>
#include "Servidor.h"
using namespace std;


int main(int argc, char const *argv[])
{
	/*RECIBIR MI CACHO DE CADENA*/

	Servidor prueba;

	//pongo una cadena de prueba
	prueba.setCadena("De 1993 que escribiera un libro con anita lava la tina las experiencias de ella durante su secuestro de seis meses, y las arduas diligencias en que él se empeñó hasta que logró liberarla");
	//le añado un n de prueba
	prueba.setDato(6);
	//la limpio
	string aux(prueba.limpiarPedazo());

	/*ENVIAR MI CACHO DE CADENA*/

	/*RECIBIR LA SUPER CADENOTA*/

	prueba.setCadena(aux);

	//busco palindromos
	prueba.divideCadenota();

	cout<<"Encontre los siguientes palindromos:"<<endl;

	puts(prueba.getPalindromos());

}


