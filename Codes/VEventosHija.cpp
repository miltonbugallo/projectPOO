#include "VEventosHija.h"
#include "DEventosHija.h"
#include "Principal.h"
#include <sstream>
#include <wx/msgdlg.h>
#include "Clientes.h"
#include "Proyectos.h"
#include <string>
#include <wx/choice.h>
#include "Eventos.h"
#include <vector>
#include <wx/grid.h>
#include <cstring>
#include <cstdlib>
#include "VFiltrado.h"
#include <algorithm>
#include <wx/icon.h>

VEventosHija::VEventosHija(wxWindow *parent) : VentanaEventos(parent) {
	SetTitle("Asistencias");
	Show();
	SetIcon(wxIcon("icon32.ico"));

	BaseDatos bd;
	grilla->AppendRows(bd.CantidadEventos());
	CargarFilas(bd.ObtenerEventos());
	
	grilla->SetSelectionMode(wxGrid::wxGridSelectRows); 
	
	
	clientesList = bd.ObtenerClientes();
	proyectosList = bd.ObtenerProyectos();
	ciudadList = bd.ObtenerEventos();
	
	// Set default values
	desplegableClientes->Insert("Ninguno",0);
	desplegableEventos->Insert("Ninguno",0);
	desplegableCiudad->Insert("Ninguno",0);
	
	
	for(int i = 1 ; i <= clientesList.size(); i++){
		Clientes clienteNuevo = clientesList[i-1];
		stringstream aux; 
		aux<< clienteNuevo.VerNombreCliente() << " - " << clienteNuevo.VerDniClientes();
		string nombreDocumento = aux.str();
		desplegableClientes->Insert(nombreDocumento, i);
		
		
	}
	
	for(int i = 1 ; i <= proyectosList.size(); i++){
		Proyectos proyectoNuevo = proyectosList[i-1];
		desplegableEventos->Insert(proyectoNuevo.VerNombreProyecto(), i);
	}	
	
	
	if(ciudadList.size() != 0){
		nombres.push_back(ciudadList[0].VerCiudadEvento());
		desplegableCiudad->Insert(ciudadList[0].VerCiudadEvento(), 1);
		int cont = 2; // porque el 0 ta ocupado
		
		for(int i = 1; i < ciudadList.size(); i++){
			Eventos e = ciudadList[i];
			for(int j = 0; j <= i; j++){
				if(strcmp( limpiarPalabra(e.VerCiudadEvento()).c_str() , limpiarPalabra(ciudadList[j].VerCiudadEvento()).c_str() ) == 0){
					int encontro = 0;
					for(int k = 0; k < nombres.size(); k++){
						if(limpiarPalabra(e.VerCiudadEvento()) == limpiarPalabra(nombres[k])){
							encontro = 1;
						}
					}
					if(encontro == 0){
						desplegableCiudad->Insert(e.VerCiudadEvento(), cont);
						cont ++;
						nombres.push_back(e.VerCiudadEvento());
					}
					
				}
			}
		}
	}
	
	desplegableClientes->SetSelection(0);
	desplegableEventos->SetSelection(0);
	desplegableCiudad->SetSelection(0);
	
}

void VEventosHija::CargarFilas(vector<Eventos> vectorNuevo){
	grilla->ClearGrid();
	
	if(vectorNuevo.size() != 0){
		
		for (int i=0;i<vectorNuevo.size();i++) {
			
			Eventos e = vectorNuevo[i];
			if(hayFiltroFecha == 1){
				float fechaEventoActual = e.VerAnioEvento() * 10000 + e.VerMesEvento() * 100 + e.VerDiaEvento();
				if(fechaDesde > fechaEventoActual || fechaHasta < fechaEventoActual){
					continue;
				}
			}
			stringstream aux; aux<<e.VerDiaEvento()<<"/"<<e.VerMesEvento()<<"/"<<e.VerAnioEvento();
			string fecha=aux.str();
			grilla->SetCellValue(i,0,e.VerCiudadEvento());
			grilla->SetCellValue(i,1,e.VerNombreProyecto());
			grilla->SetCellValue(i,2,e.VerDniCliente());
			grilla->SetCellValue(i,3,fecha);	
			
		}
		
	}
}



void VEventosHija::CargarFilaEventos(int i){
	BaseDatos bd;
	Eventos e = bd.ObtenerEvento(i);
	stringstream aux; aux<<e.VerDiaEvento()<<"/"<<e.VerMesEvento()<<"/"<<e.VerAnioEvento();
	string fecha=aux.str();
	grilla->SetCellValue(i,0,e.VerCiudadEvento());
	grilla->SetCellValue(i,1,e.VerNombreProyecto());
	grilla->SetCellValue(i,2,e.VerDniCliente());
	grilla->SetCellValue(i,3,fecha);	
}



void VEventosHija::CambiaTamanio( wxSizeEvent& event )  {
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

void VEventosHija::EnterBuscar( wxCommandEvent& event )  {
	ClickBuscar(event);
}


void VEventosHija::ClickBuscar( wxCommandEvent& event )  {
	BaseDatos bd;
	vector<Eventos> vectorEventos = bd.ObtenerEventos();
	vector<Eventos> newVector;

	if(desplegableClientes->GetSelection() == 0 && desplegableEventos->GetSelection() == 0 && desplegableCiudad->GetSelection() == 0){
		hayFiltroFecha = 0;
		CargarFilas(bd.ObtenerEventos());
	}
	else if (desplegableClientes->GetSelection() != 0 && desplegableEventos->GetSelection() != 0 && desplegableCiudad->GetSelection() == 0){
		wxMessageBox("Solo debe seleccionar un campo de busqueda", "Error");
	}
	else if (desplegableClientes->GetSelection() != 0 && desplegableEventos->GetSelection() == 0 && desplegableCiudad->GetSelection() != 0){
		wxMessageBox("Solo debe seleccionar un campo de busqueda", "Error");
	}
	else if (desplegableClientes->GetSelection() == 0 && desplegableEventos->GetSelection() != 0 && desplegableCiudad->GetSelection() != 0){
		wxMessageBox("Solo debe seleccionar un campo de busqueda", "Error");
	}
	else if(desplegableClientes->GetSelection() != 0 && desplegableEventos->GetSelection() != 0 && desplegableCiudad->GetSelection() != 0){
			wxMessageBox("Solo debe seleccionar un campo de busqueda", "Error");
	}
	else // Aca pasa la magia 
		 if(desplegableClientes->GetSelection() == 0 && desplegableCiudad->GetSelection() == 0){
			// Se busca en eventos
			int eventoSeleccionado = desplegableEventos->GetSelection() - 1;
			for(int i = 0; i < vectorEventos.size(); i++){
				if(strcmp(vectorEventos[i].VerNombreProyecto().c_str(), proyectosList[eventoSeleccionado].VerNombreProyecto().c_str()) == 0){
					newVector.push_back(vectorEventos[i]);
				}
			}
			
			VFiltrado ventana(this);
			ventana.llenarGrilla(newVector);
			ventana.ShowModal();
		}
	else if (desplegableClientes->GetSelection() == 0 && desplegableEventos->GetSelection() == 0){
				// Se busca en ciudad
				int ciudadSeleccionado = desplegableCiudad->GetSelection();
				for(int i = 0; i < vectorEventos.size(); i++){
					if( strcmp(limpiarPalabra(vectorEventos[i].VerCiudadEvento()).c_str() , limpiarPalabra(nombres[ciudadSeleccionado - 1]).c_str()) == 0){
						newVector.push_back(vectorEventos[i]);
					}
				}
				
				VFiltrado ventana(this);
				ventana.llenarGrilla(newVector);
				ventana.ShowModal();
			}
	else {// Se busca en dni
		int clienteSeleccionado = desplegableClientes->GetSelection() - 1;
		for(int i = 0; i < vectorEventos.size(); i++){
			if(strcmp(vectorEventos[i].VerDniCliente().c_str(), clientesList[clienteSeleccionado].VerDniClientes().c_str()) == 0){
				newVector.push_back(vectorEventos[i]);
			}
		}
		
		VFiltrado ventana(this);
		ventana.llenarGrilla(newVector);
		ventana.ShowModal();
	}
}

void VEventosHija::DobleClickGrilla( wxGridEvent& event )  {
	int fila_actual = grilla->GetGridCursorRow(); // obtener el indice de persona
	DEventosHija nueva_ventana(this); // crear la ventana
	nueva_ventana.setEditMode(fila_actual);
	if (nueva_ventana.ShowModal()) // mostrar y esperar
		CargarFilaEventos(fila_actual); // actualizar en la grilla
}

void VEventosHija::ClickGrilla( wxGridEvent& event )  {
	BaseDatos bd;
	int columna = event.GetCol(); 
	int cant_Eventos = bd.CantidadEventos();
	
	switch(columna) {
	case 0: bd.OrdenarEventos(0); break;
	case 1: bd.OrdenarEventos(1); break;
	case 2: bd.OrdenarEventos(2); break;
	case 3: bd.OrdenarEventos(3); break;
	}
	bd.GuardarArchivoEventos();
	for (int i=0;i<cant_Eventos;i++) 
		CargarFilaEventos(i);
}

void VEventosHija::ClickAgregar( wxCommandEvent& event )  {
	DEventosHija nuevo_dialog(this);
	if (nuevo_dialog.ShowModal() == 1){
		BaseDatos bd;
		grilla->AppendRows(1);
		int pos_nuevo = bd.CantidadEventos() - 1;
		
		CargarFilaEventos(pos_nuevo);
		grilla->SetGridCursor(pos_nuevo,0);
		grilla->SelectRow(pos_nuevo);
	}
}

void VEventosHija::ClickEditar( wxCommandEvent& event )  {
	
	// Editamos
	int fila_actual = grilla->GetGridCursorRow(); // obtener el indice del cliente
	DEventosHija dialogEventos(this); // Creamos la ventana
	dialogEventos.setEditMode(fila_actual);
	if(dialogEventos.ShowModal() == 1){
		CargarFilaEventos(fila_actual);
	}
}

void VEventosHija::ClickEliminar( wxCommandEvent& event )  {
	
	// Preguntamos si desea eliminarlo
	int fila_actual = grilla->GetGridCursorRow();
	int res = wxMessageBox("¿Desea eliminar el evento?",grilla->GetCellValue(fila_actual,0),wxYES_NO);
	if (res==wxYES) {
		
		// Eliminamos
		grilla->DeleteRows(fila_actual,1);
		BaseDatos bd;
		Eventos e = bd.ObtenerEvento(fila_actual);
		bd.EliminarEvento(e.VerDiaEvento(), e.VerMesEvento(), e.VerAnioEvento());
		bd.GuardarArchivoEventos();
	}
}


void VEventosHija::filtrarFechas( wxCommandEvent& event )  {
	
	long _diaDesde, _mesDesde, _anioDesde, _diaHasta, _mesHasta, _anioHasta;
	diaDesde->GetValue().ToLong(&_diaDesde);
	mesDesde->GetValue().ToLong(&_mesDesde);
	anioDesde->GetValue().ToLong(&_anioDesde);
	diaHasta->GetValue().ToLong(&_diaHasta);
	mesHasta->GetValue().ToLong(&_mesHasta);
	anioHasta->GetValue().ToLong(&_anioHasta);
	vector<Eventos> vecAux;
	
	if(_diaDesde < 32 && _diaDesde > 0 && _diaHasta < 32 && _diaHasta > 0){
		if(_mesDesde < 13 && _mesDesde > 0 && _mesHasta < 13 && _mesHasta > 0){
			if(_anioDesde < 3000 && _anioDesde > 1980 && _anioHasta < 3000 && _anioHasta > 1980){
				
				// Seteo las fechas como 20160715 para compararlas
				fechaDesde =(_anioDesde*10000)+(_mesDesde*100)+(_diaDesde);
				fechaHasta =(_anioHasta*10000)+(_mesHasta*100)+(_diaHasta);
				
				hayFiltroFecha = 1;
				BaseDatos bd;
				
				for (int i=0;i<bd.CantidadEventos();i++) {
					
					Eventos e = bd.ObtenerEvento(i);
					float fechaEventoActual = e.VerAnioEvento() * 10000 + e.VerMesEvento() * 100 + e.VerDiaEvento();
					if(fechaDesde > fechaEventoActual || fechaHasta < fechaEventoActual){
						continue;
					}else{
						if(fechaDesde == fechaEventoActual || fechaHasta == fechaEventoActual){
							vecAux.push_back(e);
							continue;
						}
						vecAux.push_back(e);
					}
				}
				
				VFiltrado ventana(this);
				ventana.llenarGrilla(vecAux);
				ventana.ShowModal();
				
			}else{
				wxMessageBox("Debe ingresar datos validos (año)","error");
			}
		}else{
			wxMessageBox("Debe ingresar datos validos (mes)","error");
		}
	}else{
		wxMessageBox("Debe ingresar datos validos (dias)","error");
	}
		
}

string VEventosHija::limpiarPalabra(string s){
	int i, c=s.size();
	for (i=0;i<c;i++)
		s[i]=tolower(s[i]);
	
	replace( s.begin(), s.end(), 'á', 'a');
	replace( s.begin(), s.end(), 'é', 'e');
	replace( s.begin(), s.end(), 'í', 'i');
	replace( s.begin(), s.end(), 'ó', 'o');
	replace( s.begin(), s.end(), 'ú', 'u');
	return s;
}

VEventosHija::~VEventosHija() {
	
}

