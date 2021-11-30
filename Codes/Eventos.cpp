#include "Eventos.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Principal.h"
using namespace std;

Eventos::Eventos(){}

Eventos::Eventos (string _ciudad_evento, string _nombre_proy, string _dni_cliente, int _dia_evento, int _mes_evento, int _anio_evento){
	ciudad_evento=_ciudad_evento; 
	nombre_proy=_nombre_proy; 
	dni_cliente = _dni_cliente; 
	dia_evento=_dia_evento; mes_evento=_mes_evento; anio_evento=_anio_evento;
}

// Metodos para ver los datos de la clase

string Eventos::VerCiudadEvento() const {
	return ciudad_evento;
}

string Eventos::VerNombreProyecto() const {
	return nombre_proy;
}

string Eventos::VerDniCliente() const {
	return dni_cliente;
}

int Eventos::VerDiaEvento() const {
	return dia_evento;
}

int Eventos::VerMesEvento() const {
	return mes_evento;
}

int Eventos::VerAnioEvento() const {
	return anio_evento;
}

// Metodos para modificar los datos de la clase

void Eventos::ModificarCiudadEvento(string nueva_ciudad_evento){
	ciudad_evento=nueva_ciudad_evento;
}

void Eventos::ModificarNombreProyecto(string nuevo_nombre_proy){
	nombre_proy=nuevo_nombre_proy;
}

void Eventos::ModificarDniCliente(string nuevo_dni_cliente){
	dni_cliente=nuevo_dni_cliente;
}

void Eventos::ModificarFechaEvento(int nuevo_dia_evento, int nuevo_mes_evento, int nuevo_anio_evento) { 
	dia_evento=nuevo_dia_evento;
	mes_evento=nuevo_mes_evento;
	anio_evento=nuevo_anio_evento;
}

void Eventos::GuardarArchivoEventos(ofstream &ArchivoEventos){
	
	// Se guarda los datos dentro de el struct, transformando a un array de chars para despues guardarlo en el archivo
	
	registro_evento reg_evento;
	strcpy(reg_evento.ciudad_evento,ciudad_evento.c_str());
	strcpy(reg_evento.nombre_proy,nombre_proy.c_str());
	strcpy(reg_evento.dni_cliente,dni_cliente.c_str());
	reg_evento.dia_evento=dia_evento;
	reg_evento.mes_evento=mes_evento;
	reg_evento.anio_evento=anio_evento;
	
	ArchivoEventos.write((char*)&reg_evento,sizeof(reg_evento));
}

void Eventos::LeerArchivoEventos(ifstream &ArchivoEventos){
	
	// Se lee los datos del cliente, transformando los datos de el array de chars a string
	
	registro_evento reg_evento;
	ArchivoEventos.read((char*)&reg_evento,sizeof(reg_evento));
	ciudad_evento=reg_evento.ciudad_evento;
	nombre_proy=reg_evento.nombre_proy;
	dni_cliente = reg_evento.dni_cliente;
	dia_evento=reg_evento.dia_evento;
	mes_evento=reg_evento.mes_evento;
	anio_evento=reg_evento.anio_evento;
}


bool criterio_comparacion_ciudad_evento(const Eventos &e1, const Eventos &e2) {
	string s1 = e1.VerCiudadEvento();
	string s2 = e2.VerCiudadEvento();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;	
}

bool criterio_comparacion_nombre_proyecto(const Eventos &e1, const Eventos &e2) {
	string s1 = e1.VerNombreProyecto();
	string s2 = e2.VerNombreProyecto();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;	
}

bool criterio_comparacion_dni_cliente(const Eventos &e1, const Eventos &e2) {
	string s1 = e1.VerDniCliente();
	string s2 = e2.VerDniCliente();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;	
}

bool criterio_comparacion_fecha_evento(const Eventos &e1, const Eventos &e2) {
	int a1 = e1.VerAnioEvento() * 10000 + e1.VerMesEvento() * 100 + e1.VerDiaEvento();
	int a2 = e2.VerAnioEvento() * 10000 + e2.VerMesEvento() * 100 + e2.VerDiaEvento();
	
	if((a1-a2) <= 0){
		return false;
	}
	return true;
	
}





