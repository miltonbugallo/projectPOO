#include "DClientesHija.h"
#include "Principal.h"
#include <wx/msgdlg.h>

DClientesHija::DClientesHija(wxWindow *parent) : DialogCliente(parent) {
	SetTitle("Agregar Cliente"); 
	boton1->SetLabel("Cancelar"); 
	boton2->SetLabel("Agregar"); 
	isEditModeOn = false;
}

void DClientesHija::setEditMode(int i){
	isEditModeOn = true;
	currentClienteNumber = i;
	
	// Pequeños cambios
	SetTitle("Editar Cliente"); 
	boton2->SetLabel("Guardar cambios");
	
	// Obtenemos cliente actual
	BaseDatos bd;
	this->clienteActual = bd.ObtenerCliente(i);
	
	// Ponemos los valores de los campos de textos correspondientes al usuario
	tx_Nombre->SetValue(clienteActual.VerNombreCliente());
	tx_DNI->SetValue(clienteActual.VerDniClientes());
	tx_Telefono->SetValue(clienteActual.VerTelefonoCliente());
	tx_Mail->SetValue(clienteActual.VerMailCliente());
	tx_Facebook->SetValue(clienteActual.VerFacebookCliente());
	tx_Direccion->SetValue(clienteActual.VerDireccionCliente());
	tx_Ciudad->SetValue(clienteActual.VerCiudadCliente());
}

void DClientesHija::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
}

void DClientesHija::ClickBoton2( wxCommandEvent& event )  {
	
	// Verificacion
	if(tx_Ciudad->GetValue().IsEmpty() || tx_Nombre->GetValue().IsEmpty() || tx_Direccion->GetValue().IsEmpty() || tx_DNI->GetValue().IsEmpty() || tx_Telefono->GetValue().IsEmpty() || tx_Mail->GetValue().IsEmpty() ||  tx_Facebook->GetValue().IsEmpty()){
		wxMessageBox("Debe completar todos los campos", "error");
	}else{
		
		BaseDatos bd; 
		if(isEditModeOn){
			
			// Ponemos los valores del dialog en una instancia de Clientes
			clienteActual.ModificarCiudadCliente(tx_Ciudad->GetValue().c_str());
			clienteActual.ModificarNombreCliente(tx_Nombre->GetValue().c_str());
			clienteActual.ModificarDireccionCliente(tx_Direccion->GetValue().c_str());
			clienteActual.ModificarDniCliente(tx_DNI->GetValue().c_str());
			clienteActual.ModificarTelefonoCliente(tx_Telefono->GetValue().c_str());
			clienteActual.ModificarMailCliente(tx_Mail->GetValue().c_str());
			clienteActual.ModificarFacebookCliente(tx_Facebook->GetValue().c_str());
			
			// Obtenemos el vector completo para editarlo
			vector<Clientes> clientes = bd.ObtenerClientes();
			clientes[currentClienteNumber] = clienteActual;
			bd.ModificarClientes(clientes);
			
			// Guardamos el archivo
			bd.GuardarArchivoClientes();
			
			// Actualizamos la pantalla
			
		}else{
			bd.AgregarCliente(tx_Nombre->GetValue().c_str(),
							  tx_DNI->GetValue().c_str(),
							  tx_Telefono->GetValue().c_str(),
							  tx_Mail->GetValue().c_str(),
							  tx_Facebook->GetValue().c_str(),
							  tx_Direccion->GetValue().c_str(),
							  tx_Ciudad->GetValue().c_str());
			bd.GuardarArchivoClientes();
		}
		EndModal(1);
	}
	
}

DClientesHija::~DClientesHija() {
	
}

