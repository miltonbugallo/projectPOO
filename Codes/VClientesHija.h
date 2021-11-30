#ifndef VCLIENTESHIJA_H
#define VCLIENTESHIJA_H
#include "..\..\Ventanas.h"

class VClientesHija : public VentanaClientes {
	
private:
	int actualPosCliente = 0;
	int actualPosClienteDni = 0;
protected:
	void CambiaTamanio( wxSizeEvent& event ) ;
	void EnterBuscar( wxCommandEvent& event ) ;
	void ClickBuscar( wxCommandEvent& event ) ;
	void DobleClickGrilla( wxGridEvent& event ) ;
	void ClickGrilla( wxGridEvent& event ) ;
	void ClickAgregar( wxCommandEvent& event ) ;
	void ClickEditar( wxCommandEvent& event ) ;
	void ClickEliminar( wxCommandEvent& event ) ;
	void CargarFilaClientes(int i);
public:
	VClientesHija(wxWindow *parent=NULL);
	~VClientesHija();
};

#endif

