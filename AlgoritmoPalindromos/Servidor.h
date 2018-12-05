#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>


using namespace std;

#ifndef Servidor_H_
#define Servidor_H_

class Servidor
{
private:
	//la cadena principal
	string cadena;
	//numero maximo de plabras
	int dato;
	//arreglo del codigo ascii de los caracteres que NO QUIERO
	int *ASCII;
	//cadena con los palindromos que encontre, ENVIAR ESTA CADENA
	string palindromosEncontrados;



	//convierte todo un string a mayusculas
	string todoAMayusculas( string input);
	//genera el codigo ascii de los caracteres que no quiero
    void generaASCII();
    string replaceChar(string str, int ch1, char ch2);
    //analiza una cadena de "dato" palabras o menos
	void analizarCadenota(string input);

public:
	Servidor();
	// getters y setters
	string getCadena();
	void setCadena(string cad);
	int getDato();
	void setDato(int n);

	//ve si la cadena ingresada YA SIN ESPACIOS es un plaindromo
	bool esPalindromo(string input);

	//quita los espacios de un string
	string quitaEspacios(string str);

	//quita caracteres especiales y signos de puntacion;
	char * limpiarPedazo();

	//divide el texto en "dato" palabras
	void divideCadenota();

	//regreso los palindromos encontrados
	char* getPalindromos();




};


 #endif