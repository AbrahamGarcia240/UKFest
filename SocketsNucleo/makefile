main: Main.cpp Semaforo.o Solicitud.o
	g++ Main.cpp Solicitud.o SocketDatagrama.o PaqueteDatagrama.o -o main -lpthread
Solicitud.o: Solicitud.cpp Solicitud.h SocketDatagrama.o
	g++ Solicitud.cpp  -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h
	g++ SocketDatagrama.cpp  -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c