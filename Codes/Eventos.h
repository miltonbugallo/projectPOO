#ifndef EVENTOS_H
#define EVENTOS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


struct registro_evento {
	char ciudad_evento[256];
	char nombre_proy[256];
	char dni_cliente[9];
	int dia_evento,mes_evento,anio_evento;
};


class Eventos {
	
private: string ciudad_evento;
string nombre_proy;
string dni_cliente;
int dia_evento,mes_evento,anio_evento;

public:
	Eventos();
	Eventos(string _ciudad_evento, string _nombre_proy, string _dni_cliente, int _dia_evento, int _mes_evento, int _anio_evento);
	
	string VerCiudadEvento() const;
	string VerNombreProyecto() const;
	string VerDniCliente() const;
	int VerDiaEvento() const;
	int VerMesEvento() const;
	int VerAnioEvento() const;
	
	void ModificarCiudadEvento(string nueva_ciudad_evento);
	void ModificarNombreProyecto(string nuevo_nombre_proy); 
	void ModificarDniCliente(string nuevo_dni_cliente);
	void ModificarFechaEvento(int nuevo_dia_evento, int nuevo_mes_evento, int nuevo_anio_evento);
	
	void GuardarArchivoEventos(ofstream &ArchivoEventos); 
	
	void LeerArchivoEventos(ifstream &ArchivoEventos);
};


bool criterio_comparacion_fecha_evento(const Eventos &e1, const Eventos &e2);
bool criterio_comparacion_dni_cliente(const Eventos &e1, const Eventos &e2);
bool criterio_comparacion_nombre_proyecto(const Eventos &e1, const Eventos &e2);
bool criterio_comparacion_ciudad_evento(const Eventos &e1, const Eventos &e2);


#endif

