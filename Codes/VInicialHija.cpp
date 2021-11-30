#include "VInicialHija.h"
#include "../../Ventanas.h"
#include "VClientesHija.h"
#include <wx/event.h>
#include <wx/window.h>

VInicialHija::VInicialHija(wxWindow *parent) : VentanaInicial(parent) {
	
}

void VInicialHija::AbrirClientes( wxCommandEvent& event )  {
	event.Skip();
	
}

void VInicialHija::AbrirEventos( wxCommandEvent& event )  {
	event.Skip();
}

void VInicialHija::AbrirProyectos( wxCommandEvent& event )  {
	event.Skip();
}

VInicialHija::~VInicialHija() {
	
}

