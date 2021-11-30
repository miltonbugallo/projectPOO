#include "VFiltrado.h"
#include "Eventos.h"
#include <vector>
#include <string>
#include <sstream>

VFiltrado::VFiltrado(wxWindow *parent) : VentanaFiltrado(parent) {
	
}

void VFiltrado::llenarGrilla(vector<Eventos> eventos){
	grilla->ClearGrid();
	grilla->AppendRows(eventos.size());
	for (int i=0;i<eventos.size();i++) {
		
		Eventos e = eventos[i];
		stringstream aux; aux<<e.VerDiaEvento()<<"/"<<e.VerMesEvento()<<"/"<<e.VerAnioEvento();
		string fecha=aux.str();
		grilla->SetCellValue(i,0,e.VerCiudadEvento());
		grilla->SetCellValue(i,1,e.VerNombreProyecto());
		grilla->SetCellValue(i,2,e.VerDniCliente());
		grilla->SetCellValue(i,3,fecha);	
		
	}
}
VFiltrado::~VFiltrado() {
	
}

void VFiltrado::CambiarTamanio( wxSizeEvent& event )  {
	// Modificar ancho de cada columna
	Layout(); 
	int cantidad = 4;
	int cantidadColumnas[cantidad], anchoViejo=0;
	for (int i=0;i<cantidad;i++) { 
		cantidadColumnas[i] = grilla->GetColSize(i);
		anchoViejo += cantidadColumnas[i];
	}
	int anchoNuevo = grilla->GetSize().GetWidth(); // ver el ancho nuevo de la tabla
	grilla->BeginBatch();
	for (int i=0;i<cantidad;i++)
		grilla->SetColSize(i,cantidadColumnas[i]*anchoNuevo/anchoViejo);
	grilla->EndBatch();
}

void VFiltrado::DobleClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VFiltrado::DobleClickLabel( wxGridEvent& event )  {
	event.Skip();
}

