#ifndef VentanaPrincipal_H
#define VentanaPrincipal_H
#include "../../Ventanas.h"
#include <wx/window.h>
#include <wx/event.h>


class VentanaPrincipal:public VentanaInicial {
protected:
	void AbrirClientes( wxCommandEvent& event ) ;
	void AbrirEventos( wxCommandEvent& event ) ;
	void AbrirProyectos( wxCommandEvent& event ) ;

public:
	VentanaPrincipal(wxWindow *parent=NULL);
	void OnBotonCerrar(wxCommandEvent &evt);
};

#endif
