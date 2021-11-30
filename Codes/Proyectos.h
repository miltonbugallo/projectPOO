#ifndef PROYECTOS_H
#define PROYECTOS_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


struct registro_proyecto{
	char nombre_proyecto[256];
	char tipo_proyecto[256];
	int precio_proyecto;
};


class Proyectos {
private: 
	string nombre_proyecto;
	string tipo_proyecto;
	int precio_proyecto;
	
public: 
	Proyectos();
	Proyectos(string _nombre_proyecto, string _tipo_proyecto, int _precio_proyecto);
	
	string VerNombreProyecto() const;
	string VerTipoProyecto() const;
	int VerPrecioProyecto() const;
	
	void ModificarNombreProyecto(string nuevo_nombre_proyecto);
	void ModificarTipoPoryecto(string nuevo_tipo_proyecto);
	void ModificarPrecioProyecto(int nuevo_precio_proyecto);
	
	void GuardarArchivoProyectos(ofstream &ArchivoProyecto);
	
	void LeerArchivoProyecto(ifstream &ArchivoProyecto);
	
};

bool criterio_comparacion_precio_proy(const Proyectos &p1, const Proyectos &p2) ;
bool criterio_comparacion_tipo_proy(const Proyectos &p1, const Proyectos &p2);
bool criterio_comparacion_nombre_proy(const Proyectos &p1, const Proyectos &p2); 


#endif

