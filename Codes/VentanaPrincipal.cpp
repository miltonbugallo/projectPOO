#include "VentanaPrincipal.h"
#include <wx/window.h>
#include <wx/event.h>
#include "VClientesHija.h"
#include "VEventosHija.h"
#include "VProyectosHija.h"
#include <wx/icon.h>

VentanaPrincipal::VentanaPrincipal(wxWindow *parent):VentanaInicial(parent){
	Show();
	SetTitle("Administrador de Seminarios");
	SetIcon(wxIcon("icon32.ico"));
}

void VentanaPrincipal::OnBotonCerrar( wxCommandEvent& event ) { 
	Close();
}

void VentanaPrincipal::AbrirClientes( wxCommandEvent& event )  {
	VClientesHija *c = new VClientesHija(this);
}

void VentanaPrincipal::AbrirEventos( wxCommandEvent& event )  {
	VEventosHija *e = new VEventosHija(this);
}

void VentanaPrincipal::AbrirProyectos( wxCommandEvent& event )  {
	VProyectosHija *p = new VProyectosHija(this);
}

