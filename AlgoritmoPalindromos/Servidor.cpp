#include <string.h>
#include <iostream>	
#include "Servidor.h"
using namespace std;

//constructor
Servidor::Servidor(){
	//genero espacio de memoria para guardar los caracteres que no quiero
	ASCII=(int*)malloc(sizeof(int)*192);
}

//getters y setters
string Servidor::getCadena(){
	return cadena;
}

void Servidor::setCadena(string cad){
	cadena=cad;

}

int Servidor::getDato(){
	return dato;
}

void Servidor::setDato(int n){
	dato=n;
}
/*
	QUE ES: Funcion que llena un arreglo de enteros con todos los ascii que no
	quiero conservar

	COMO LO HACE: recorro en un for todo el espectro ascii para encontrar los 
	caracteres que NO QUIERO y los meto en un arreglo de enteros

*/

void Servidor::generaASCII(){
	register int i;
	int j=0;
	for ( i = 0; i < 127; i++)
	{
		if(i<32 || (i>32 && i<48)  || (i>57 && i<65)   || (i>90 && i<97)  || i>122 ){
			ASCII[j]=i;
			j++;
		}

	}
}


/*
	QUE ES: Esta funcion elimina todos los signos de puntuacion de la cadena PRINCIPAL

	COMO LO HACE: para cada elemento del arreglo ASCII de valores no deseados, busco
	coincidencias en la cadena principal y las elimino alv

	Al final regreso el apuntador al espacio de texto ya limpio
*/


char* Servidor::limpiarPedazo(){
	Servidor::generaASCII();
	register int i;
	for ( i = 0; i < 192; i++)
	{
		cadena.erase(remove(cadena.begin(), cadena.end(), (char)ASCII[i]), cadena.end());

	}


	replace( cadena.begin(), cadena.end(), (char)162, (char) 111);

	return (char*)cadena.c_str();

}


/*
	QUE ES: verifica que una funcion sin espacios es palindrome

	COMO LO HACE: creo un nuevo string que sea el mismo pero al reves y comparo si es que 
	son iguales
*/

bool Servidor::esPalindromo(string input){
	input=Servidor::todoAMayusculas(input);
	if (input == string(input.rbegin(), input.rend())) {
	    return true;
	}
	return false;
}

//pues... eso, quita espacios no manches

string Servidor::quitaEspacios(string str){
	for(unsigned int i=0; i<str.length(); i++)
    	 if(str[i] == ' ') str.erase(i,1);
    return str;
}

// convierte toda una cadena a mayusculas

string Servidor::todoAMayusculas( string input){
	transform(input.begin(), input.end(), input.begin(), ::toupper);
	return input;

}

/*
	QUE HACE: Esta funcion recorre la cadena principal de n palabras en n palabras
	dde manera desplazante
	
	COMO LO HACE: recorro la cadena principal hasta encontrar un espacio, guardo la posicion
	del primer espacio y cuento n-i espacios mas,

	Cuando ya lei n espacios, me regreso al segundo espacio que lei e inicio el contador de nuevo

	para cada iteracion guardo los caracteres en un string

*/

void Servidor::divideCadenota(){
	register unsigned int i;
	int k=0; //ultimo punto de partida
	int j=0; //numero de espacios
	int candado=0;
	string aux="";
	for ( i = 0; i < cadena.length(); i++)
	{
		if(cadena[i]==' '){
			//cout<<"_"<<endl;
			aux+=" ";
			j++;
			aux=aux+cadena[i];
			if(candado==0){
				candado=1;
				k=i;
			}
			
		}
		else{
			//cout<<cadena[i];
			aux+=cadena[i];
		}

		if(j==dato){
			cout<<"********************"<<endl;
			cout<<aux<<endl;
			Servidor::analizarCadenota(aux);
			aux="";
			j=0;
			i=k;
			candado=0;

		}
	}	

    
}

/*
	QUE HACE: de una cadena tamaño n detecta si es que hay palindromos, de ser asi los guarda

	COMO LO HACE: recibe una cadena de tamaño n y palabra por palabra la va agregando a un string
	auxiliar, para cada iteracion verifica si dicha cadena es un palindromo.

	Para esto, a la cadena auxiliar le quita los espacios y la pasa a mayusculas

	Si es un plaindromo la agrega a un string con TODOS los palindromos que se han encontrado
*/

void Servidor::analizarCadenota(string input){
	cout<<endl;
	char* myString=(char*)  input.c_str();
	char *p = strtok(myString, " ");
	string aux;
	string sinespacios;
	string mayusculas;
	register int i=1;

	while (p) {
		if(i<=dato){
	    	printf ("%s\n", p);
	    	aux=aux+" "+string(p);
	    	//verifico si es palindromo
	    	sinespacios=Servidor::quitaEspacios(aux);
	    	mayusculas=Servidor::todoAMayusculas(sinespacios);
	    	if(Servidor::esPalindromo(mayusculas)){
	    		cout<<"palindromo"<<endl;
	    		palindromosEncontrados+=aux+";";
	    	}
	    	else{
	    		cout<<aux<<": NO ES palindromo"<<endl;
	    	}

	    	i++;
		}
	    p = strtok(NULL, " ");
	}
	cout<<aux<<endl;

	sinespacios=Servidor::quitaEspacios(aux);
	mayusculas=Servidor::todoAMayusculas(sinespacios);
	    	if(Servidor::esPalindromo(mayusculas)){
	    		cout<<"palindromo"<<endl;
	    		palindromosEncontrados+=aux+";";
	    	}
	    	else{
	    		cout<<aux<<": NO ES palindromo"<<endl;
	    	}
	//cout<<"PALINDORMOS ENCONTRADOS:"<<endl;
	//cout<<palindromosEncontrados<<endl;
}	

char* Servidor::getPalindromos(){
	return (char*)palindromosEncontrados.c_str();
}