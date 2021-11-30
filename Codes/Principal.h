#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Proyectos.h"
#include "Clientes.h"
#include "Eventos.h"
#include <vector>
#include <string>
#include <wx/string.h>
using namespace std;


class BaseDatos {
private: 
	vector<Proyectos> vectorProyectos;
	vector<Eventos> vectorEventos;
	vector<Clientes> vectorClientes;
	string nombreArchivoProyectos="proyecto.dat";
	string nombreArchivoEventos="eventos.dat";
	string nombreArchivoCliente="cliente.dat";
	
	
public: BaseDatos();

bool GuardarArchivoEventos();
bool GuardarArchivoProyectos();
bool GuardarArchivoClientes();

int CantidadProyectos();
int CantidadClientes();
int CantidadEventos();

void AgregarProyecto(string _nombre_proyecto, string _tipo_proyecto, int _precio_proyecto);
void AgregarCliente(string _nombre_cliente, string _dni_cliente, string _telefono_cliente, string _facebook_cliente, string _mail_cliente, string _direccion_cliente, string _ciudad_cliente);
void AgregarEvento(string _ciudad_evento, string _nombre_proy, string _nombre_cliente, int _dia_evento, int _mes_evento, int _anio_evento);

void EliminarProyecto(string _nombre_proyecto);
void EliminarCliente(string _dni_cliente);
void EliminarEvento( int _dia_evento, int _mes_evento, int _anio_evento);

vector<Clientes> ObtenerClientes();
vector<Eventos> ObtenerEventos();
vector<Proyectos> ObtenerProyectos();

void ModificarClientes(vector<Clientes> clientes);
void ModificarEventos(vector<Eventos> eventos);
void ModificarProyectos(vector<Proyectos> proyectos);

Clientes ObtenerCliente(int i);
Eventos ObtenerEvento(int i);
Proyectos ObtenerProyecto(int i);

void OrdenarClientes(int criterio);
void OrdenarEventos(int criterio);
void OrdenarProyectos(int criterio);

int BuscarClientePorNombre(wxString nombre, int posInicial);
int BuscarClientePorDni(wxString dni, int posInicial);

int BuscarEventoPorCiudad(wxString ciudad, int posInicial);
int BuscarEventoPorDniClienteEvento(wxString dni_evento, int posInicial);
int BuscarEventoPorNombreProy(wxString nombre_proy, int posInicial);
int BuscarEventoPorFecha(wxString fecha, int posInicial);

int BuscarProyectoPorNombre(wxString nombre, int posInicial);
int BuscarProyectoPorTipo(wxString tipo, int posInicial);
};

void pasar_a_minuscula(string &s);

#endif

