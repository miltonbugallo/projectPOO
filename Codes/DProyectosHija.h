#ifndef DPROYECTOSHIJA_H
#define DPROYECTOSHIJA_H
#include "..\..\Ventanas.h"
#include "Proyectos.h"

class DProyectosHija : public DialogProyecto {
	
private:
	Proyectos proyectoActual;
	bool isEditModeOn;
	int currentProyectoNumber;
	
protected:
	void ClickBoton1( wxCommandEvent& event ) ;
	void ClickBoton2( wxCommandEvent& event ) ;
	
public:
	DProyectosHija(wxWindow *parent=NULL);
	void setEditMode(int i);
	~DProyectosHija();
};

#endif

