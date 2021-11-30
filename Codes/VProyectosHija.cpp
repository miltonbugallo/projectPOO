#include "VProyectosHija.h"
#include "DProyectosHija.h"
#include "Principal.h"
#include <sstream>
#include <wx/msgdlg.h>
#include <wx/icon.h>

VProyectosHija::VProyectosHija(wxWindow *parent) : VentanaProyectos(parent) {
	SetTitle("Eventos");
	Show();
	SetIcon(wxIcon("icon32.ico"));
	BaseDatos bd; 
	int c_pers = bd.CantidadProyectos();
	grilla->AppendRows(c_pers);
	for (int i=0;i<c_pers;i++) CargarFilaProyectos(i);
	grilla->SetSelectionMode(wxGrid::wxGridSelectRows); 
}

void VProyectosHija::CargarFilaProyectos(int i){
	BaseDatos bd; 
	Proyectos p = bd.ObtenerProyecto(i);
	stringstream aux; aux<<p.VerPrecioProyecto(); string precio=aux.str();
	grilla->SetCellValue(i,0,p.VerNombreProyecto());
	grilla->SetCellValue(i,1,p.VerTipoProyecto());
	grilla->SetCellValue(i,2,precio);
	
}

void VProyectosHija::CambiaTamanio( wxSizeEvent& event )  {
	// Modificar ancho de cada columna
	Layout(); 
	int cantidad = 3;
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

void VProyectosHija::EnterBuscar( wxCommandEvent& event )  {
	ClickBuscar(event);;
}

void VProyectosHija::ClickBuscar( wxCommandEvent& event )  {
	BaseDatos bd;
	int opcionSeleccionada = opcionProyecto->GetSelection();
	if(opcionSeleccionada == 0){
		// Selecciono nombre del proy como campo de busqueda
		wxString textoEnElCuadrito = busqueda->GetValue();
		
		actualPosNombreProy = bd.BuscarProyectoPorNombre(textoEnElCuadrito, actualPosNombreProy);
		
		if(actualPosNombreProy == -1){
			wxMessageBox("No se encontraron coincidencias");
			actualPosNombreProy = 0;
			
		}else{
			grilla->SetGridCursor(actualPosNombreProy,0); // seleccionar
			grilla->SelectRow(actualPosNombreProy); // seleccionar
			actualPosNombreProy++;
		}
	}else{
		// Selecciono tipo como campo de busqueda
		wxString textoEnElCuadrito = busqueda->GetValue();
		actualPosTipoProy = bd.BuscarProyectoPorTipo(textoEnElCuadrito, actualPosTipoProy);
		
		if(actualPosTipoProy == -1){
			wxMessageBox("No se encontraron coincidencias");
			actualPosTipoProy = 0;
		}else{
			grilla->SetGridCursor(actualPosTipoProy,0); // seleccionar
			grilla->SelectRow(actualPosTipoProy); // seleccionar
			actualPosTipoProy++;
		}
	};
}

void VProyectosHija::DobleClickGrilla( wxGridEvent& event )  {
	int fila_actual = grilla->GetGridCursorRow(); // obtener el indice de persona
	DProyectosHija nueva_ventana(this); // crear la ventana
	nueva_ventana.setEditMode(fila_actual);
	if (nueva_ventana.ShowModal()) // mostrar y esperar
		CargarFilaProyectos(fila_actual); // actualizar en la grilla
}

void VProyectosHija::ClickGrilla( wxGridEvent& event )  {
	BaseDatos bd;
	int columna = event.GetCol(); 
	int cant_Proyectos = bd.CantidadProyectos();
	
	switch(columna) {
		case 0: bd.OrdenarProyectos(0); break;
		case 1: bd.OrdenarProyectos(1); break;
		case 2: bd.OrdenarProyectos(2); break;
	}
	bd.GuardarArchivoProyectos();
	for (int i=0;i<cant_Proyectos;i++) 
		CargarFilaProyectos(i);
}

void VProyectosHija::ClickAgregar( wxCommandEvent& event )  {
	DProyectosHija nuevo_dialog(this);
	if (nuevo_dialog.ShowModal() == 1){
		BaseDatos bd;
		grilla->AppendRows(1);
		int pos_nuevo = bd.CantidadProyectos() - 1;
		
		CargarFilaProyectos(pos_nuevo);
		grilla->SetGridCursor(pos_nuevo,0);
		grilla->SelectRow(pos_nuevo);
	}
}

void VProyectosHija::ClickEditar( wxCommandEvent& event )  {
	
	// Editamos el item
	int fila_actual = grilla->GetGridCursorRow(); // obtener el indice del cliente
	DProyectosHija dialogProyecto(this); // Creamos la ventana
	dialogProyecto.setEditMode(fila_actual);
	if(dialogProyecto.ShowModal() == 1){
		CargarFilaProyectos(fila_actual);
	}
}

void VProyectosHija::ClickEliminar( wxCommandEvent& event )  {
	
	// Preguntamos si desea eliminarlo
	int fila_actual = grilla->GetGridCursorRow();
	int res = wxMessageBox("¿Desea eliminar el proyecto?",grilla->GetCellValue(fila_actual,0),wxYES_NO);
	if (res==wxYES) {
		
		// Eliminamos
		grilla->DeleteRows(fila_actual,1);
		BaseDatos bd;
		Proyectos p = bd.ObtenerProyecto(fila_actual);
		bd.EliminarProyecto(p.VerNombreProyecto());
		bd.GuardarArchivoProyectos();
	}
}

VProyectosHija::~VProyectosHija() {
	
}

