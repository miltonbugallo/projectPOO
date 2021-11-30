#ifndef VPROYECTOSHIJA_H
#define VPROYECTOSHIJA_H
#include "..\..\Ventanas.h"

class VProyectosHija : public VentanaProyectos {
	
private: int actualPosNombreProy = 0;
int actualPosTipoProy = 0;
	
protected:
	void CambiaTamanio( wxSizeEvent& event ) ;
	void EnterBuscar( wxCommandEvent& event ) ;
	void ClickBuscar( wxCommandEvent& event ) ;
	void DobleClickGrilla( wxGridEvent& event ) ;
	void ClickGrilla( wxGridEvent& event ) ;
	void ClickAgregar( wxCommandEvent& event ) ;
	void ClickEditar( wxCommandEvent& event ) ;
	void ClickEliminar( wxCommandEvent& event ) ;
	void CargarFilaProyectos(int i);
public:
	VProyectosHija(wxWindow *parent=NULL);
	~VProyectosHija();
};

#endif

