//Cliente
//#include "Distribuidor.h"
#include "Solicitud.h"
#include "Respuesta.h"
#include <stdio.h>
#include <string>
#include <thread>
#include <vector>
#include <unistd.h>
using namespace std;

char ip[4][16];
int puerto;
int s;

vector<int> pilaDeProcesos;
string resultado;
bool disponibilidad[4];
double velocidad[4];
vector<string> cadenasALimpiar;

int recibeN();
long unsigned int recibeTam();
void recibeArchivo(char * buf,long unsigned int *len);
void inicializaPila(int n);
void mandarALimpiar(int n);

int main (int argc, char **argv) {

	//Se reciben las  ip's y el puerto
	/*strcpy(ip[0], argv[1]);
	strcpy(ip[1], argv[2]);
	strcpy(ip[2], argv[3]);
	strcpy(ip[3], argv[4]);
	puerto = atoi(argv[5]);*/
	
	//Recibe n y texto del servidor web
	int n;
	long unsigned int len;
	string texto;
	
	len = recibeTam();
    cout << "tam: " << len << endl;
	n = recibeN();
    cout << "n: " << n << endl;
    
    char buffer = (char)malloc(len);
    recibeArchivo(buffer, &len);
    cout << "Contenido: " << buffer << endl;

	velocidad[0] = 230; //Miguel
	velocidad[1] = 206; //Abraham
	velocidad[2] = 274; //Jorge
	velocidad[3] = 795; //Jesús

	//Distribuidor distribuidor = new Distribuidor(texto, n);
	//cadenasALimpiar = distribuidor.getCadenasLimpiarDividida(velocidad);

	string prueba = "";
	cadenasALimpiar.push_back(prueba);

	/*thread h1(mandarALimpiar,0), h2(mandarALimpiar,1), h3(mandarALimpiar,2), h4(mandarALimpiar,3);
	h1.join();
	h2.join();
	h3.join();
	h4.join();*/
	return 0;
}

void mandarALimpiar(int n) {
	Solicitud s;
	const char *c = cadenasALimpiar[n].c_str();
	char *respuesta = s.doOperation(ip[n], puerto, 1, (char *)c);
	if (respuesta == NULL) {
		printf("Error al mandar a limpiar: Hilo %d(%s)", n+1, ip[n]);
	} else {
		string cadenaLimpia(respuesta);
		cadenasALimpiar[n] = cadenaLimpia;
	}

}

int recibeN() {
	int puerto = 7200;
	struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s, n;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));

    unsigned int addr_len = sizeof(direccionForanea);
    bzero((char *)&direccionForanea, sizeof(direccionForanea));

    int regreso = recvfrom(s,(char*)&n,4, 0, (struct sockaddr *) &direccionForanea, &addr_len);
    if (regreso != -1) {
    	sendto(s, &n, 4, 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
    	close(s);
    	return n;
    }
    else {
    	close(s);
    	return regreso;
    }
}

long unsigned int recibeTam() {
	int puerto = 7200;
	struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s;
    long unsigned int n;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));

    unsigned int addr_len = sizeof(direccionForanea);
    bzero((char *)&direccionForanea, sizeof(direccionForanea));

    int regreso = recvfrom(s,(char*)&n,sizeof(long unsigned int), 0, (struct sockaddr *) &direccionForanea, &addr_len);
    if (regreso != -1) {
    	sendto(s, &n, sizeof(long unsigned int), 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));
    	close(s);
    	return n;
    }
    else {
    	close(s);
    	return (long unsigned int)regreso;
    }
}

void recibeArchivo(char * buf,long unsigned int *len){
	int puerto = 7200;
	struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));

    unsigned int addr_len = sizeof(direccionForanea);
    bzero((char *)&direccionForanea, sizeof(direccionForanea));

	int total = 0;
	int n;
	int bytesleft = *len;
	while (total < *len)
	{
		n = recvfrom(s,(char*)(buf+total),bytesleft,0, (struct sockaddr *) &direccionForanea, &addr_len);
		if (n== -1 || n == 0) {
			break;
		}
		total += n;
		bytesleft -= n;
	}
	close(s);
}

void inicializaPila(int n) {
	for(int i = 0; i < n; i++) {
		pilaDeProcesos.push_back(i+1);
	}
}