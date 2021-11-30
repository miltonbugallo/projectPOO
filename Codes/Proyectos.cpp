#include "Proyectos.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Principal.h"
using namespace std;

Proyectos::Proyectos(){}

Proyectos::Proyectos(string _nombre_proyecto, string _tipo_proyecto, int _precio_proyecto){
	nombre_proyecto=_nombre_proyecto; 
	tipo_proyecto=_tipo_proyecto; 
	precio_proyecto=_precio_proyecto;
}

// Metodos para ver los datos de la clase

string Proyectos::VerNombreProyecto() const {
	return nombre_proyecto;
}

string Proyectos::VerTipoProyecto() const {
	return tipo_proyecto;
}

int Proyectos::VerPrecioProyecto() const {
	return precio_proyecto;
}

// Metodos para modificar los datos de la clase

void Proyectos::ModificarNombreProyecto(string nuevo_nombre_proyecto){
	nombre_proyecto=nuevo_nombre_proyecto;
}

void Proyectos::ModificarTipoPoryecto(string nuevo_tipo_proyecto){
	tipo_proyecto=nuevo_tipo_proyecto;
}

void Proyectos::ModificarPrecioProyecto(int nuevo_precio_proyecto){
	precio_proyecto=nuevo_precio_proyecto;
}
void Proyectos::GuardarArchivoProyectos(ofstream &ArchivoProyecto){
	
	// Se guarda los datos dentro de el struct, transformando a un array de chars para despues guardarlo en el archivo
	
	registro_proyecto reg_proyecto;
	strcpy(reg_proyecto.nombre_proyecto,nombre_proyecto.c_str());
	strcpy(reg_proyecto.tipo_proyecto,tipo_proyecto.c_str());
	reg_proyecto.precio_proyecto=precio_proyecto;
	ArchivoProyecto.write((char*)&reg_proyecto,sizeof(reg_proyecto));
}


void Proyectos::LeerArchivoProyecto(ifstream &ArchivoProyecto){
	
	// Se lee los datos del cliente, transformando los datos de el array de chars a string
	
	registro_proyecto reg_proyecto;
	ArchivoProyecto.read((char*)&reg_proyecto,sizeof(reg_proyecto));
	
	nombre_proyecto=reg_proyecto.nombre_proyecto;
	tipo_proyecto=reg_proyecto.tipo_proyecto;
	precio_proyecto=reg_proyecto.precio_proyecto;
}


bool criterio_comparacion_nombre_proy(const Proyectos &p1, const Proyectos &p2) {
	string s1 = p1.VerNombreProyecto();
	string s2 = p2.VerNombreProyecto();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;
}

bool criterio_comparacion_tipo_proy(const Proyectos &p1, const Proyectos &p2) {
	string s1 = p1.VerTipoProyecto();
	string s2 = p2.VerTipoProyecto();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;
}

bool criterio_comparacion_precio_proy(const Proyectos &p1, const Proyectos &p2) {
	int s1 = p1.VerPrecioProyecto();
	int s2 = p2.VerPrecioProyecto();
	return s1<s2;
}


