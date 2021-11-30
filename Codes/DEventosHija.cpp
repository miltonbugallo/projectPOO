#include "DEventosHija.h"
#include "Principal.h"
#include <sstream>
#include <vector>
#include "Clientes.h"
#include <wx/msgdlg.h>
#include <cstring>

DEventosHija::DEventosHija(wxWindow *parent) : DialogEventos(parent) {
	SetTitle("Agregar Asistencia"); 
	boton1->SetLabel("Cancelar"); 
	boton2->SetLabel("Agregar"); 
	
	BaseDatos bd;
	
	
	// Obtenemos los eventos a.k.a. "proyectos" y los completamos en la grilla
	proyectosList = bd.ObtenerProyectos();
	for(int i = 0 ; i < proyectosList.size(); i++){
		Proyectos proyectoNuevo = proyectosList[i];
		desplegableEvento->Insert(proyectoNuevo.VerNombreProyecto(), i);
	}	
	
	
	isEditModeOn = false;
	
}

void DEventosHija::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
}
void DEventosHija::setEditMode(int i){
	isEditModeOn = true;
	currentEventoNumber = i;
	
	// Pequeños cambios
	SetTitle("Editar evento");
	boton2->SetLabel("Guardar cambios");
	
	// Obtenemos evento actual
	BaseDatos bd;
	eventoActual = bd.ObtenerEvento(i);
	
		
	// Ponemos los valores de los campos de textos correspondientes al evento
	tx_Ciudad_Evento->SetValue(eventoActual.VerCiudadEvento());
	//tx_Nombre_Proyecto_Evento->SetValue(eventoActual.VerNombreProyecto());
	//tx_DNI_Cliente_Evento->SetValue();
	tx_Dia_Evento->SetValue(wxString()<<eventoActual.VerDiaEvento());
	tx_Mes_Evento->SetValue(wxString()<<eventoActual.VerMesEvento());
	tx_Anio_Evento->SetValue(wxString()<<eventoActual.VerAnioEvento());
	
	// eventoActual.VerDniCliente()
	dniCliente->SetValue(eventoActual.VerDniCliente().c_str());
	
	for(int k = 0; k < proyectosList.size(); k++){
		
		Proyectos proyectoNuevo1 = proyectosList[k];
		
		if(strcmp(proyectoNuevo1.VerNombreProyecto().c_str(), eventoActual.VerNombreProyecto().c_str()) == 0)
			desplegableEvento->Select(k);
		
	}
}

void DEventosHija::ClickBoton2( wxCommandEvent& event )  {
	long dia,mes,anio; 
	tx_Dia_Evento->GetValue().ToLong(&dia);
	tx_Mes_Evento->GetValue().ToLong(&mes);
	tx_Anio_Evento->GetValue().ToLong(&anio);
	

	BaseDatos bd; 
	int encontroAlguien = 0;
	
	// Validacion
	
	// Verificar si pusieron algo
	if(tx_Ciudad_Evento->GetValue().IsEmpty() || desplegableEvento->GetSelection() == -1 || dniCliente->GetValue().IsEmpty() || dia == NULL || mes == NULL || anio == NULL){
		wxMessageBox("Debe completar todos los campos", "error");
	}else{
		for(int i = 0; i < bd.CantidadClientes(); i++){
			Clientes c = bd.ObtenerCliente(i);
			if(strcmp(c.VerDniClientes().c_str(),dniCliente->GetValue().c_str()) == 0){
				
				encontroAlguien = 1;
				
				// anda y el cliente tiene doc
				if(mes < 13 && mes > 0){
					if(mes == 2){
						if(dia < 29 && dia > 0){
							
							if(anio < 3000 && anio > 1980){
								// ANDO
								
								if(isEditModeOn){
									eventoActual.ModificarCiudadEvento(tx_Ciudad_Evento->GetValue().c_str());
									eventoActual.ModificarDniCliente(dniCliente->GetValue().c_str());
									eventoActual.ModificarNombreProyecto(proyectosList[desplegableEvento->GetSelection()].VerNombreProyecto());
									eventoActual.ModificarFechaEvento(atoi(tx_Dia_Evento->GetValue().c_str()), atoi(tx_Mes_Evento->GetValue().c_str()), atoi(tx_Anio_Evento->GetValue().c_str()));
									
									// Obtenemos el vector completo para editarlo
									vector<Eventos> eventos = bd.ObtenerEventos();
									eventos[currentEventoNumber] = eventoActual;
									bd.ModificarEventos(eventos);
									
									// Guardamos el archivo
									bd.GuardarArchivoEventos();
									
								}else{
									bd.AgregarEvento(tx_Ciudad_Evento->GetValue().c_str(),
													 proyectosList[desplegableEvento->GetSelection()].VerNombreProyecto(),
													 dniCliente->GetValue().c_str(),
													 dia,mes,anio);
									bd.GuardarArchivoEventos();
									
								}
								EndModal(1);
								
								break;
							}
						}else{
							wxMessageBox("Ingrese un dia valido", "error");
						}
					}else{
						if(dia < 32 && dia > 0){
							if(anio < 3000 && anio > 1980){
								
								// ANDO
								
								if(isEditModeOn){
									eventoActual.ModificarCiudadEvento(tx_Ciudad_Evento->GetValue().c_str());
									eventoActual.ModificarDniCliente(dniCliente->GetValue().c_str());
									eventoActual.ModificarNombreProyecto(proyectosList[desplegableEvento->GetSelection()].VerNombreProyecto());
									eventoActual.ModificarFechaEvento(atoi(tx_Dia_Evento->GetValue().c_str()), atoi(tx_Mes_Evento->GetValue().c_str()), atoi(tx_Anio_Evento->GetValue().c_str()));
									
									// Obtenemos el vector completo para editarlo
									vector<Eventos> eventos = bd.ObtenerEventos();
									eventos[currentEventoNumber] = eventoActual;
									bd.ModificarEventos(eventos);
									
									// Guardamos el archivo
									bd.GuardarArchivoEventos();
									
								}else{
									bd.AgregarEvento(tx_Ciudad_Evento->GetValue().c_str(),
													 proyectosList[desplegableEvento->GetSelection()].VerNombreProyecto(),
													 dniCliente->GetValue().c_str(),
													 dia,mes,anio);
									bd.GuardarArchivoEventos();
									
								}
								EndModal(1);
								
								break;
								
							}else{
								wxMessageBox("Ingrese un año valido", "error");
							}
						}else{
							wxMessageBox("Ingrese un dia valido", "error");
						}
					}
				}else{
					wxMessageBox("Ingrese mes valido", "error");
				}
				
			}
		}
		if(encontroAlguien == 0){
			// Se muestra cuando se pasó todo el for y no se encontró documento
			wxMessageBox("No se ha registrado ese cliente en la base de datos", "error");
		}
		
	}
	
}

DEventosHija::~DEventosHija() {
	
}

