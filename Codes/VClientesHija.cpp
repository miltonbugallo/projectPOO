#include "VClientesHija.h"
#include "Principal.h"
#include "DClientesHija.h"
#include "Clientes.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>

VClientesHija::VClientesHija(wxWindow *parent) : VentanaClientes(parent) {
	SetTitle("Clientes");
	Show();
	SetIcon(wxIcon("icon32.ico"));
	BaseDatos bd; 
	int c_pers = bd.CantidadClientes();
	grilla->AppendRows(c_pers);
	for (int i=0;i<c_pers;i++) CargarFilaClientes(i);
	grilla->SetSelectionMode(wxGrid::wxGridSelectRows); // hacer que la seleccion sea por fila, y no por celda
	
}

void VClientesHija::CargarFilaClientes(int i){
	BaseDatos bd;
	Clientes c = bd.ObtenerCliente(i);
	grilla->SetCellValue(i,0,c.VerNombreCliente());
	grilla->SetCellValue(i,1,c.VerDniClientes());
	grilla->SetCellValue(i,2,c.VerTelefonoCliente());
	grilla->SetCellValue(i,3,c.VerMailCliente());
	grilla->SetCellValue(i,4,c.VerFacebookCliente());
	grilla->SetCellValue(i,5,c.VerDireccionCliente());
	grilla->SetCellValue(i,6,c.VerCiudadCliente());
}

void VClientesHija::CambiaTamanio( wxSizeEvent& event )  {
	
	// Modificar ancho de cada columna
	Layout(); 
	int cantidad = 7;
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

void VClientesHija::EnterBuscar( wxCommandEvent& event )  {
	ClickBuscar(event);
}

void VClientesHija::ClickBuscar( wxCommandEvent& event )  {
	
	BaseDatos bd;
	int opcionSeleccionada = opcionCliente->GetSelection();
	actualPosCliente = 0;
	actualPosClienteDni = 0;
	if(opcionSeleccionada == 0){
		// Selecciono nombre como campo de busqueda
		wxString textoEnElCuadrito = busqueda->GetValue();
		
		actualPosCliente = bd.BuscarClientePorNombre(textoEnElCuadrito, actualPosCliente);
		
		if(actualPosCliente == -1){
			wxMessageBox("No se encontraron coincidencias");
			actualPosCliente = 0;
			
		}else{
			grilla->SetGridCursor(actualPosCliente,0); // seleccionar
			grilla->SelectRow(actualPosCliente); // seleccionar
			actualPosCliente++;
		}
	}else{
		// Selecciono DNI como campo de busqueda
		wxString textoEnElCuadrito = busqueda->GetValue();
		actualPosClienteDni = bd.BuscarClientePorDni(textoEnElCuadrito, actualPosClienteDni);
		
		if(actualPosClienteDni == -1){
			wxMessageBox("No se encontraron coincidencias");
			actualPosClienteDni = 0;
		}else{
			grilla->SetGridCursor(actualPosClienteDni,0); // seleccionar
			grilla->SelectRow(actualPosClienteDni); // seleccionar
			actualPosClienteDni++;
		}
	}
}

void VClientesHija::DobleClickGrilla( wxGridEvent& event )  {
	int fila_actual = grilla->GetGridCursorRow(); // obtener el indice de persona
	DClientesHija nueva_ventana(this); // crear la ventana
	nueva_ventana.setEditMode(fila_actual);
	if (nueva_ventana.ShowModal()) // mostrar y esperar
		CargarFilaClientes(fila_actual); // actualizar en la grilla
}

void VClientesHija::ClickGrilla( wxGridEvent& event )  {
	
	BaseDatos bd;
	int columna = event.GetCol(); 
	int cant_Clientes=bd.CantidadClientes();
	
	switch(columna) {
	case 0: bd.OrdenarClientes(0); break;
	case 1: bd.OrdenarClientes(1); break;
	case 2: bd.OrdenarClientes(2); break;
	case 3: bd.OrdenarClientes(3); break;
	case 4: bd.OrdenarClientes(4); break;
	case 5: bd.OrdenarClientes(5); break;
	case 6: bd.OrdenarClientes(6); break;
	}
	bd.GuardarArchivoClientes();
	for (int i=0;i<cant_Clientes;i++) 
		CargarFilaClientes(i);
}

void VClientesHija::ClickAgregar( wxCommandEvent& event )  {
	
	DClientesHija nuevo_dialog(this);
	if (nuevo_dialog.ShowModal() == 1){
		BaseDatos bd;
		grilla->AppendRows(1);
		int pos_nuevo = bd.CantidadClientes() - 1;
		
		CargarFilaClientes(pos_nuevo);
		grilla->SetGridCursor(pos_nuevo,0);
		grilla->SelectRow(pos_nuevo);
	}
	
}

void VClientesHija::ClickEditar( wxCommandEvent& event )  {
	
	// Editamos el item
	int fila_actual = grilla->GetGridCursorRow(); // obtener el indice del cliente
	DClientesHija dialogCliente(this); // Creamos la ventana
	dialogCliente.setEditMode(fila_actual);
	if(dialogCliente.ShowModal() == 1){
		CargarFilaClientes(fila_actual);
	}
}

void VClientesHija::ClickEliminar( wxCommandEvent& event )  {
	
	// Preguntamos si desea eliminarlo
	int fila_actual = grilla->GetGridCursorRow();
	int res = wxMessageBox("¿Desea eliminar el cliente?",grilla->GetCellValue(fila_actual,0),wxYES_NO);
	if (res==wxYES) {
		
		// Eliminamos
		grilla->DeleteRows(fila_actual,1);
		BaseDatos bd;
		Clientes c = bd.ObtenerCliente(fila_actual); // Pasa que nosotros eliminamos por dni jeje
		bd.EliminarCliente(c.VerDniClientes());
		bd.GuardarArchivoClientes();
	}
}

VClientesHija::~VClientesHija() {
	
}

