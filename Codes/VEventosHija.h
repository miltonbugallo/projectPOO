#ifndef VEVENTOSHIJA_H
#define VEVENTOSHIJA_H
#include "..\..\Ventanas.h"
#include <vector>
#include "Clientes.h"
#include "Proyectos.h"
#include "Eventos.h"

class VEventosHija : public VentanaEventos {
	
private:
	int actualPosEvento = 0;
	int actualPosProyEvento = 0;
	int actualPosDniClienteEvento = 0;
	int actualPosFechaEvento = 0;
	int hayFiltroFecha = 0; // 0 que no 1 k si
	int fechaDesde, fechaHasta;
	vector<Clientes> clientesList;
	vector<Proyectos> proyectosList;
	vector<Eventos> ciudadList;
	vector<Eventos> vectorConFiltro;
	vector<string> nombres;
	
protected:
	void filtrarFechas( wxCommandEvent& event ) ;
	void CambiaTamanio( wxSizeEvent& event ) ;
	void EnterBuscar( wxCommandEvent& event ) ;
	void ClickBuscar( wxCommandEvent& event ) ;
	void DobleClickGrilla( wxGridEvent& event ) ;
	void ClickGrilla( wxGridEvent& event ) ;
	void ClickAgregar( wxCommandEvent& event ) ;
	void ClickEditar( wxCommandEvent& event ) ;
	void ClickEliminar( wxCommandEvent& event ) ;
	void CargarFilaEventos(int i);
	void CargarFilas(vector<Eventos> vectorNuevo) ;
	void irAFiltrado(vector<Eventos> eventos) ;
	string limpiarPalabra(string s);
public:
	VEventosHija(wxWindow *parent=NULL);
	~VEventosHija();
};

#endif
