#include <iostream>
#include <thread>
#include <mutex>
#include "Servidor.h"
using namespace std;

string a,b,c,d;

void function(string aux, int numHilo, int n, string respuesta){
	Servidor nucleo;
	nucleo.setCadena(aux);
	nucleo.setDato(n);
	//busco palindromos
	nucleo.divideCadenota();



	
	//cout<<"Hilo "<<this_thread::get_id()<<" soy el hilo "<<n<<" Encontre los siguientes palindromos:"<<endl;
	//puts(nucleo.getPalindromos());
	string s(nucleo.getPalindromos());
	switch(numHilo){
		case 1: a=s; break;
		case 2: b=s; break;
		case 3: c=s; break;
		case 4: d=s; break;

	}
}	

int main(int argc, char const *argv[])
{
	/*RECIBIR MI CACHO DE CADENA*/

	Servidor prueba;

	//pongo una cadena de prueba
	prueba.setCadena("De 1993 ana ojo ada Aman a Panama A mama Roma le aviva el amor a papa y a papa Roma le aviva el amor a mama que escribiera un libro con anita lava la tina las experiencias de ella durante su secuestro de seis meses, y las arduas diligencias en que él se empeñó hasta que logró liberarla");
	//le añado un n de prueba
	prueba.setDato(6);
	//la limpio
	string aux(prueba.limpiarPedazo());

	/*ENVIAR MI CACHO DE CADENA*/

	/*RECIBIR LA SUPER CADENOTA*/

	

	//testing de los hilos
	
	thread th1(function,aux,1,2,a),th2(function,aux,2,4,b),th3(function,aux,3,5,c),th4(function,aux,4,6,d);
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	cout<<endl;
	cout<<"Hilo 1"<< a<<endl;
	cout<<endl;
	cout<<"Hilo 2"<< b<<endl;
	cout<<endl;
	cout<<"Hilo 3"<< c<<endl;
	cout<<endl;
	cout<<"Hilo 4"<< d<<endl;
	cout<<endl;


	
}


