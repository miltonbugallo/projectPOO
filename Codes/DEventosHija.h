#ifndef DEVENTOSHIJA_H
#define DEVENTOSHIJA_H
#include "..\..\Ventanas.h"
#include "Eventos.h"
#include <vector>
#include "Clientes.h"
#include "Proyectos.h"

class DEventosHija : public DialogEventos {
	
private:
	Eventos eventoActual;
	bool isEditModeOn;
	int currentEventoNumber;
	vector<Clientes> clientesList;
	vector<Proyectos> proyectosList;
protected:
	void ClickBoton1( wxCommandEvent& event ) ;
	void ClickBoton2( wxCommandEvent& event ) ;
	
public:
	DEventosHija(wxWindow *parent=NULL);
	void setEditMode(int i);
	void fillDesplegable();
	~DEventosHija();
};

#endif

