#ifndef CLIENTES_H
#define CLIENTES_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


struct registro_cliente {
	char nombre_cliente[256];
	char dni_cliente[9];
	char telefono_cliente[256];
	char facebook_cliente[256];
	char mail_cliente[256];
	char direccion_cliente[256];
	char ciudad_cliente[256];
};


class Clientes{
	
private:
	
	string nombre_cliente, dni_cliente, telefono_cliente, mail_cliente, facebook_cliente, direccion_cliente, ciudad_cliente;
	
public:
	Clientes();
	Clientes(string _nombre_cliente, string _dni_cliente, string _telefono_cliente, string _facebook_cliente, string _mail_cliente, string _direccion_cliente, string _ciudad_cliente);
	
	
	string VerNombreCliente() const;
	string VerDniClientes() const;
	string VerTelefonoCliente() const;
	string VerMailCliente() const;
	string VerFacebookCliente() const;
	string VerDireccionCliente() const;
	string VerCiudadCliente() const;
	
	void ModificarNombreCliente(string nuevo_nombre_cliente);
	void ModificarDniCliente(string nuevo_dni_cliente);
	void ModificarTelefonoCliente(string nuevo_telefono_cliente);
	void ModificarMailCliente(string nuevo_mail_cliente);
	void ModificarFacebookCliente(string );
	void ModificarDireccionCliente(string nueva_direccion_cliente);
	void ModificarCiudadCliente(string nueva_ciudad_cliente);
	
	void GuardarArchivoClientes(ofstream &ArchivoClientes);
	
	void LeerArchivoClientes(ifstream &ArchivoClientes);
	
	
	
};

bool criterio_comparacion_nombre_cliente(const Clientes &c1, const Clientes &c2);
bool criterio_comparacion_dni(Clientes c1, Clientes c2);
bool criterio_comparacion_telefono(Clientes c1, Clientes c2);
bool criterio_comparacion_mail(Clientes c1, Clientes c2);
bool criterio_comparacion_facebook(Clientes c1, Clientes c2) ;
bool criterio_comparacion_direccion(Clientes c1, Clientes c2);
bool criterio_comparacion_ciudad(Clientes c1, Clientes c2);



#endif

