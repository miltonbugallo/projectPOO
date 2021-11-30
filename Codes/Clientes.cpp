#include "Clientes.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Principal.h"
using namespace std;

Clientes::Clientes(){}

Clientes::Clientes(string _nombre_cliente, string _dni_cliente, string _telefono_cliente, string _facebook_cliente, string _mail_cliente, string _direccion_cliente, string _ciudad_cliente){
	nombre_cliente=_nombre_cliente;
	dni_cliente = _dni_cliente;
	telefono_cliente=_telefono_cliente;
	mail_cliente=_mail_cliente;
	direccion_cliente=_direccion_cliente;
	facebook_cliente=_facebook_cliente;
	ciudad_cliente=_ciudad_cliente;
}

// Metodos para ver los datos de la clase

string Clientes::VerNombreCliente() const{
	return nombre_cliente; 
}

string Clientes::VerDniClientes() const{
	return dni_cliente;
}

string Clientes::VerDireccionCliente() const{ 
	return direccion_cliente; 
}

string Clientes::VerCiudadCliente() const{ 
	return ciudad_cliente; 
}

string Clientes::VerTelefonoCliente() const{ 
	return telefono_cliente; 
}

string Clientes::VerMailCliente() const{ 
	return mail_cliente; 
}

string Clientes::VerFacebookCliente() const{ 
	return facebook_cliente; 
}

// Metodos para modificar los datos de la clase

void Clientes::ModificarNombreCliente(string nuevo_nombre_cliente) { 
	nombre_cliente = nuevo_nombre_cliente; 
}

void Clientes::ModificarDniCliente(string nuevo_dni_cliente){
	dni_cliente = nuevo_dni_cliente;
}

void Clientes::ModificarDireccionCliente(string nueva_direccion_cliente) { 
	direccion_cliente=nueva_direccion_cliente; 
}

void Clientes::ModificarCiudadCliente(string nueva_ciudad_cliente) {
	ciudad_cliente=nueva_ciudad_cliente; 
}

void Clientes::ModificarTelefonoCliente(string nuevo_telefono_cliente) { 
	telefono_cliente=nuevo_telefono_cliente; 
}

void Clientes::ModificarMailCliente(string nuevo_mail_cliente) { 
	mail_cliente=nuevo_mail_cliente; 
}

void Clientes::ModificarFacebookCliente(string nuevo_facebook_cliente){
	facebook_cliente = nuevo_facebook_cliente;
}



void Clientes::GuardarArchivoClientes(ofstream &ArchivoClientes){
	
	// Se guarda los datos dentro de el struct, transformando a un array de chars para despues guardarlo en el archivo
	
	registro_cliente reg_cliente;
	strcpy(reg_cliente.nombre_cliente,nombre_cliente.c_str());
	strcpy(reg_cliente.dni_cliente, dni_cliente.c_str());
	strcpy(reg_cliente.telefono_cliente,telefono_cliente.c_str());
	strcpy(reg_cliente.mail_cliente,mail_cliente.c_str());
	strcpy(reg_cliente.facebook_cliente,facebook_cliente.c_str());
	strcpy(reg_cliente.direccion_cliente,direccion_cliente.c_str());
	strcpy(reg_cliente.ciudad_cliente,ciudad_cliente.c_str());
	
	ArchivoClientes.write((char*)&reg_cliente,sizeof(reg_cliente));
	
}

void Clientes::LeerArchivoClientes(ifstream &ArchivoClientes){
	
	// Se lee los datos del cliente, transformando los datos de el array de chars a string
	
	registro_cliente reg_cliente;
	ArchivoClientes.read((char*)&reg_cliente,sizeof(reg_cliente));
	
	nombre_cliente=reg_cliente.nombre_cliente;
	dni_cliente = reg_cliente.dni_cliente;
	telefono_cliente=reg_cliente.telefono_cliente;
	mail_cliente=reg_cliente.mail_cliente;
	facebook_cliente=reg_cliente.facebook_cliente;
	direccion_cliente=reg_cliente.direccion_cliente;
	ciudad_cliente=reg_cliente.ciudad_cliente;
}


bool criterio_comparacion_nombre_cliente(const Clientes &c1, const Clientes &c2)  {
	string s1 = c1.VerNombreCliente();
	string s2 = c2.VerNombreCliente();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;
}

bool criterio_comparacion_dni(const Clientes &c1, const Clientes &c2)  {
	string s1 = c1.VerDniClientes();
	string s2 = c2.VerDniClientes();
	
	return s1<s2;
}

bool criterio_comparacion_direccion(Clientes c1, Clientes c2) {
	string s1 = c1.VerDireccionCliente();
	string s2 = c2.VerDireccionCliente();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;
}

bool criterio_comparacion_telefono(Clientes c1, Clientes c2) {
	string s1 = c1.VerTelefonoCliente();
	string s2 = c2.VerTelefonoCliente();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;
}


bool criterio_comparacion_mail(Clientes c1, Clientes c2) {
	string s1 = c1.VerMailCliente();
	string s2 = c2.VerMailCliente();	
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;	
}

bool criterio_comparacion_facebook(Clientes c1, Clientes c2) {
	string s1 = c1.VerFacebookCliente();
	string s2 = c2.VerFacebookCliente();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;	
}

bool criterio_comparacion_ciudad(Clientes c1, Clientes c2) {
	string s1 = c1.VerCiudadCliente();
	string s2 = c2.VerCiudadCliente();
	
	// Pasar string de comparacion a minusculas
	pasar_a_minuscula(s1);
	pasar_a_minuscula(s2);
	
	return s1<s2;	
}
