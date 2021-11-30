#include "DProyectosHija.h"
#include "Principal.h"
#include <wx/msgdlg.h>

DProyectosHija::DProyectosHija(wxWindow *parent) : DialogProyecto(parent) {
	SetTitle("Agregar Proyecto"); 
	boton1->SetLabel("Cancelar"); 
	boton2->SetLabel("Agregar"); 
	
	isEditModeOn = false;
}

void DProyectosHija::ClickBoton1( wxCommandEvent& event )  {
	EndModal(0);
}

void DProyectosHija::setEditMode(int i){
	isEditModeOn = true;
	currentProyectoNumber = i;
	
	// Pequeños cambios
	SetTitle("Editar proyecto");
	boton2->SetLabel("Guardar cambios");
	
	// Obtenemos proyecto actual
	BaseDatos bd;
	proyectoActual = bd.ObtenerProyecto(i);
	
	
	// Ponemos los valores de los campos de textos correspondientes al proyecto
	tx_Nombre_Proy->SetValue(proyectoActual.VerNombreProyecto());
	tx_Tipo_Proy->SetValue(proyectoActual.VerTipoProyecto());
	tx_Precio_Proy->SetValue(wxString()<<proyectoActual.VerPrecioProyecto());
}

void DProyectosHija::ClickBoton2( wxCommandEvent& event )  {
	BaseDatos bd; 
	
	// Validacion 
	if(tx_Nombre_Proy->GetValue().IsEmpty() || tx_Tipo_Proy->GetValue().IsEmpty() || tx_Precio_Proy->GetValue().IsEmpty() || atoi(tx_Precio_Proy->GetValue().c_str()) < 0 || atoi(tx_Precio_Proy->GetValue().c_str()) > 1000000){
		wxMessageBox("Complete todos los campos", "error");
	}else{
		if(isEditModeOn){
			proyectoActual.ModificarNombreProyecto(tx_Nombre_Proy->GetValue().c_str());
			proyectoActual.ModificarTipoPoryecto(tx_Tipo_Proy->GetValue().c_str());
			proyectoActual.ModificarPrecioProyecto(atoi(tx_Precio_Proy->GetValue().c_str()));
			
			// Obtenemos el vector completo para editarlo
			vector<Proyectos> proyectos = bd.ObtenerProyectos();
			proyectos[currentProyectoNumber] = proyectoActual;
			bd.ModificarProyectos(proyectos);
			
			// Guardamos el archivo
			bd.GuardarArchivoProyectos();
			
		}else{
			bd.AgregarProyecto(tx_Nombre_Proy->GetValue().c_str(),
							   tx_Tipo_Proy->GetValue().c_str(),
							   atoi(tx_Precio_Proy->GetValue().c_str()));
			bd.GuardarArchivoProyectos();
		}
		EndModal(1);
	}
	
	
}

DProyectosHija::~DProyectosHija() {
	
}

