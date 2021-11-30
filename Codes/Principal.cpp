#include "Principal.h"
#include "Proyectos.h"
#include "Clientes.h"
#include "Eventos.h"


#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <wx/string.h>
#include <sstream>
using namespace std;


BaseDatos::BaseDatos(){
	
	// Se lee los proyectos y se los coloca en el vector
	ifstream archivo_proyectos(nombreArchivoProyectos.c_str(),ios::binary|ios::ate);
	if (archivo_proyectos.is_open()) {
		int tamanio_archivo = archivo_proyectos.tellg();
		int cantidad_proyectos = tamanio_archivo/sizeof(registro_proyecto);
		vectorProyectos.resize(cantidad_proyectos);
		archivo_proyectos.seekg(0,ios::beg);
		for (int i=0;i<cantidad_proyectos;i++)
			vectorProyectos[i].LeerArchivoProyecto(archivo_proyectos);
		archivo_proyectos.close();
	}
	
	// Se lee los eventos y se los coloca en el vector
	ifstream archivo_eventos(nombreArchivoEventos.c_str(),ios::binary|ios::ate);
	if (archivo_eventos.is_open()) {
		int tamanio_archivo = archivo_eventos.tellg();
		int cantidad_eventos = tamanio_archivo/sizeof(registro_evento);
		vectorEventos.resize(cantidad_eventos);
		archivo_eventos.seekg(0,ios::beg);
		for (int i=0;i<cantidad_eventos;i++)
			vectorEventos[i].LeerArchivoEventos(archivo_eventos);
		archivo_eventos.close();
	}
	
	// Se lee los Clientes y se los coloca en el vector
	ifstream archivo_clientes(nombreArchivoCliente.c_str(),ios::binary|ios::ate);
	if (archivo_clientes.is_open()) {
		int tamanio_archivo = archivo_clientes.tellg();
		int cantidad_clientes = tamanio_archivo/sizeof(registro_cliente);
		vectorClientes.resize(cantidad_clientes);
		archivo_clientes.seekg(0,ios::beg);
		for (int i=0;i<cantidad_clientes;i++)
			vectorClientes[i].LeerArchivoClientes(archivo_clientes);
		archivo_clientes.close();
	}
	
}

bool BaseDatos::GuardarArchivoProyectos() {
	
	// Metodo para guardar los datos del vector en el archivo
	
	ofstream archivo_proyectos(nombreArchivoProyectos.c_str(),ios::binary|ios::trunc);
	if (!archivo_proyectos.is_open()) return false;
	int cantidad_proyectos = CantidadProyectos();
	for (int i=0;i<cantidad_proyectos;i++)
		vectorProyectos[i].GuardarArchivoProyectos(archivo_proyectos);
	archivo_proyectos.close();
	return true;
}

bool BaseDatos::GuardarArchivoEventos() {
	
	// Metodo para guardar los datos del vector en el archivo
	
	ofstream archivo_eventos(nombreArchivoEventos.c_str(),ios::binary|ios::trunc);
	if (!archivo_eventos.is_open()) return false;
	int cantidad_eventos = CantidadEventos();
	for (int i=0;i<cantidad_eventos;i++)
		vectorEventos[i].GuardarArchivoEventos(archivo_eventos);
	archivo_eventos.close();
	return true;
}

bool BaseDatos::GuardarArchivoClientes() {
	
	// Metodo para guardar los datos del vector en el archivo
	
	ofstream archivo_clientes(nombreArchivoCliente.c_str(),ios::binary|ios::trunc);
	if (!archivo_clientes.is_open()) return false;
	int cantidad_clientes = CantidadClientes();
	for (int i=0;i<cantidad_clientes;i++)
		vectorClientes[i].GuardarArchivoClientes(archivo_clientes);
	archivo_clientes.close();
	return true;
}

// Metodos para obtener la cantidad de datos en cada vector

int BaseDatos::CantidadProyectos(){
	return vectorProyectos.size();
}

int BaseDatos::CantidadEventos(){
	return vectorEventos.size();
}

int BaseDatos::CantidadClientes(){
	return vectorClientes.size();
}


void BaseDatos::AgregarProyecto(string _nombre_proyecto, string _tipo_proyecto, int _precio_proyecto){
	
	// Se crea el proyecto, se agrega al vector y se guarda en el archivo
	
	Proyectos nuevo_proyecto(_nombre_proyecto, _tipo_proyecto, _precio_proyecto);
	vectorProyectos.push_back(nuevo_proyecto);
	GuardarArchivoProyectos();
}

void BaseDatos::AgregarEvento(string _ciudad_evento, string _nombre_proy, string _nombre_cliente, int _dia_evento, int _mes_evento, int _anio_evento){
	
	// Se crea el evento, se agrega al vector y se guarda en el archivo
	
	Eventos nuevo_evento(_ciudad_evento, _nombre_proy, _nombre_cliente ,_dia_evento, _mes_evento, _anio_evento);
	vectorEventos.push_back(nuevo_evento);
	GuardarArchivoEventos();
}

void BaseDatos::AgregarCliente(string _nombre_cliente, string _dni_cliente, string _telefono_cliente, string _facebook_cliente, string _mail_cliente, string _direccion_cliente, string _ciudad_cliente){
	
	// Se crea el cliente, se agrega al vector y se guarda en el archivo
	
	Clientes nuevo_cliente(_nombre_cliente, _dni_cliente,  _telefono_cliente, _facebook_cliente, _mail_cliente, _direccion_cliente, _ciudad_cliente);
	vectorClientes.push_back(nuevo_cliente);
	GuardarArchivoClientes();
}

void BaseDatos::EliminarCliente(string _dni_cliente){
	
	// Se elimina el cliente del vector y se actualiza el archivo
	
	for(int i = 0; i < vectorClientes.size(); i++){
		if(vectorClientes[i].VerDniClientes() == _dni_cliente){
			vectorClientes.erase(vectorClientes.begin() + i);
			GuardarArchivoClientes();
		}
	}
}

void BaseDatos::EliminarProyecto(string _nombre_proyecto){
	
	// Se elimina el proyecto del vector y se actualiza el archivo
	
	for(int i = 0; i < vectorProyectos.size(); i++){
		if(vectorProyectos[i].VerNombreProyecto() == _nombre_proyecto){
			vectorProyectos.erase(vectorProyectos.begin() + i);
			GuardarArchivoProyectos();
		}
	}
}

void BaseDatos::EliminarEvento(int _dia_evento, int _mes_evento, int _anio_evento){
	
	// Se elimina el evento del vector y se actualiza el archivo
	
	for(int i = 0; i < vectorEventos.size(); i++){
		if(vectorEventos[i].VerDiaEvento() == _dia_evento && vectorEventos[i].VerMesEvento() == _mes_evento && vectorEventos[i].VerAnioEvento() == _anio_evento){
			vectorEventos.erase(vectorEventos.begin() + i);
			GuardarArchivoEventos();
		}
	}
}


// Metodos para obtener individualmente cada uno de los elementos de los vectores

Clientes BaseDatos::ObtenerCliente(int i){
	return vectorClientes[i];
}

Eventos BaseDatos::ObtenerEvento(int i){
	return vectorEventos[i];
}

Proyectos BaseDatos::ObtenerProyecto(int i){
	return vectorProyectos[i];
}

// Metodos para obtener y setear los vectores completos

vector<Clientes> BaseDatos::ObtenerClientes(){
	return vectorClientes;
}

vector<Eventos> BaseDatos::ObtenerEventos(){
	return vectorEventos;
}

vector<Proyectos> BaseDatos::ObtenerProyectos(){
	return vectorProyectos;
}

void BaseDatos::ModificarClientes(vector<Clientes> clientes){
	vectorClientes = clientes;
}

void BaseDatos::ModificarEventos(vector<Eventos> eventos){
	vectorEventos = eventos;
}

void BaseDatos::ModificarProyectos(vector<Proyectos> proyectos){
	vectorProyectos = proyectos;
}

void BaseDatos::OrdenarClientes(int criterio){
	switch(criterio){
	case 0: 
		sort(vectorClientes.begin(),vectorClientes.end(),criterio_comparacion_nombre_cliente); 
		break;
	case 1: 
		sort(vectorClientes.begin(),vectorClientes.end(),criterio_comparacion_telefono);
		break;
	case 2: 
		sort(vectorClientes.begin(),vectorClientes.end(),criterio_comparacion_telefono);
		break;
	case 3: 
		sort(vectorClientes.begin(),vectorClientes.end(),criterio_comparacion_mail);
		break;
	case 4: 
		sort(vectorClientes.begin(),vectorClientes.end(),criterio_comparacion_facebook);
		break;
	case 5: 
		sort(vectorClientes.begin(),vectorClientes.end(),criterio_comparacion_direccion);
		break;
	case 6: 
		sort(vectorClientes.begin(),vectorClientes.end(),criterio_comparacion_ciudad);
		break;
	};
}

void BaseDatos::OrdenarEventos(int criterio){
	switch(criterio){
	case 0: 
		sort(vectorEventos.begin(), vectorEventos.end(), criterio_comparacion_ciudad_evento);
		break;
	case 1:  
		sort(vectorEventos.begin(), vectorEventos.end(), criterio_comparacion_nombre_proyecto);
		break;
	case 2:  
		sort(vectorEventos.begin(), vectorEventos.end(), criterio_comparacion_nombre_proyecto);
		break;
	case 3:  
		sort(vectorEventos.begin(), vectorEventos.end(), criterio_comparacion_fecha_evento);
		break;
	}
}
void BaseDatos::OrdenarProyectos(int criterio){
	switch(criterio){
	case 0: 
		sort(vectorProyectos.begin(), vectorProyectos.end(), criterio_comparacion_nombre_proy);
		break;
	case 1:  
		sort(vectorProyectos.begin(), vectorProyectos.end(), criterio_comparacion_tipo_proy);
		break;
	case 2:  
		sort(vectorProyectos.begin(), vectorProyectos.end(), criterio_comparacion_precio_proy);
		break;
	}
}


int BaseDatos::BuscarClientePorNombre(wxString nombre, int posInicial){
	string nombreCliente = nombre.c_str();
	
	// Pasamos a minusculas el nombre que nos pasan
	pasar_a_minuscula(nombreCliente);
	
	for(int i = posInicial; i < vectorClientes.size(); i++){
		string actualName = vectorClientes[i].VerNombreCliente();
		pasar_a_minuscula(actualName);
		
		if(actualName.find(nombreCliente, 0) != string::npos){
			return i;
		}
	}
	
	for(int i = 0; i <= posInicial; i++){
		string actualName = vectorClientes[i].VerNombreCliente();
		pasar_a_minuscula(actualName);
		
		if(actualName.find(nombreCliente, 0) != string::npos){
			return i;
		}
	}
	return -1;
}

int BaseDatos::BuscarClientePorDni(wxString dni, int posInicial){
	string dniCliente = dni.c_str();
	
	for(int i = posInicial; i < vectorClientes.size(); i++){
		string dni_Actual = vectorClientes[i].VerDniClientes();
		pasar_a_minuscula(dni_Actual);
		
		if(dni_Actual.find(dniCliente, 0) != string::npos){
			return i;
		}
	}
	
	for(int i = 0; i <= posInicial; i++){
		string dni_Actual = vectorClientes[i].VerDniClientes();
		pasar_a_minuscula(dni_Actual);
		
		if(dni_Actual.find(dniCliente, 0) != string::npos){
			return i;
		}
	}
	return -1;
	
}

	
int BaseDatos::BuscarEventoPorCiudad(wxString ciudad, int posInicial){
	string nombreCiudad = ciudad.c_str();
	
	// Pasamos a minusculas el nombre que nos pasan
	pasar_a_minuscula(nombreCiudad);
	
	for(int i = posInicial; i < vectorEventos.size(); i++){
		string CiudadActual = vectorEventos[i].VerCiudadEvento();
		pasar_a_minuscula(CiudadActual);
		
		if(CiudadActual.find(nombreCiudad, 0) != string::npos){
			return i;
		}
	}
	
	for(int i = 0; i <= posInicial; i++){
		string CiudadActual = vectorEventos[i].VerCiudadEvento();
		pasar_a_minuscula(CiudadActual);
		
		if(CiudadActual.find(nombreCiudad, 0) != string::npos){
			return i;
		}
	}
	return -1;
	
}	


int BaseDatos::BuscarEventoPorDniClienteEvento(wxString dni, int posInicial){
	string _dni = dni.c_str();
	
	for(int i = posInicial; i < vectorEventos.size(); i++){
		string dniActual = vectorEventos[i].VerDniCliente();
		pasar_a_minuscula(dniActual);
		
		if(dniActual.find(_dni , 0) != string::npos){
			return i;
		}
	}
	
	for(int i = 0; i <= posInicial; i++){
		string dniActual = vectorEventos[i].VerDniCliente();
		pasar_a_minuscula(dniActual);
		
		if(dniActual.find(_dni , 0) != string::npos){
			return i;
		}
	}
	return -1;
	
}

int BaseDatos::BuscarEventoPorFecha(wxString fecha, int posInicial){
	
	// Input -> 27/06/1996
	string fechaEvento = fecha.c_str();
	for(int i = posInicial; i < vectorEventos.size(); i++){
		stringstream aux;
		aux << vectorEventos[i].VerDiaEvento()<<"/"<<vectorEventos[i].VerMesEvento()<<"/"<<vectorEventos[i].VerAnioEvento();
		string fechaAux = aux.str();
		if(fechaAux.find(fechaEvento, 0) != string::npos){
			return i;
		}
	}
	return -1;
}

int BaseDatos::BuscarEventoPorNombreProy(wxString nombre_proy, int posInicial){
	string NombreProyEvento = nombre_proy.c_str();
	
	// Pasamos a minusculas el nombre del proy que nos pasan
	pasar_a_minuscula(NombreProyEvento);
	
	for(int i = posInicial; i < vectorEventos.size(); i++){
		string NombreProyEventoActual = vectorEventos[i].VerNombreProyecto();
		pasar_a_minuscula(NombreProyEventoActual);
		
		if(NombreProyEventoActual.find(NombreProyEvento, 0) != string::npos){
			return i;
		}
	}
	
	for(int i = 0; i <= posInicial; i++){
		string NombreProyEventoActual = vectorEventos[i].VerNombreProyecto();
		pasar_a_minuscula(NombreProyEventoActual);
		
		if(NombreProyEventoActual.find(NombreProyEvento, 0) != string::npos){
			return i;
		}
	}
	return -1;
	
}	

int BaseDatos::BuscarProyectoPorNombre(wxString nombre_proyecto, int posInicial){
	string NombreProy = nombre_proyecto.c_str();
	
	// Pasamos a minusculas el nombre del proy que nos pasan
	pasar_a_minuscula(NombreProy);
	
	for(int i = posInicial; i < vectorProyectos.size(); i++){
		string NombreProyActual = vectorProyectos[i].VerNombreProyecto();
		pasar_a_minuscula(NombreProyActual);
		
		if(NombreProyActual.find(NombreProy, 0) != string::npos){
			return i;
		}
	}
	
	for(int i = 0; i <= posInicial; i++){
		string NombreProyActual = vectorProyectos[i].VerNombreProyecto();
		pasar_a_minuscula(NombreProyActual);
		
		if(NombreProyActual.find(NombreProy, 0) != string::npos){
			return i;
		}
	}
	return -1;
	
}

int BaseDatos::BuscarProyectoPorTipo(wxString tipo, int posInicial){
	string tipo_proy= tipo.c_str();
	
	// Pasamos a minusculas el nombre del proy que nos pasan
	pasar_a_minuscula(tipo_proy);
	
	for(int i = posInicial; i < vectorProyectos.size(); i++){
		string TipoProyActual = vectorProyectos[i].VerTipoProyecto();
		pasar_a_minuscula(TipoProyActual);
		
		if(TipoProyActual.find(tipo_proy, 0) != string::npos){
			return i;
		}
	}
	
	for(int i = 0; i <= posInicial; i++){
		string TipoProyActual = vectorProyectos[i].VerTipoProyecto();
		pasar_a_minuscula(TipoProyActual);
		
		if(TipoProyActual.find(tipo_proy, 0) != string::npos){
			return i;
		}
	}
	return -1;
	
}

void pasar_a_minuscula(string &s) {
	int i,c=s.size();
	for (i=0;i<c;i++)
		s[i]=tolower(s[i]);
}


