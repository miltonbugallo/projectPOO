#ifndef DCLIENTESHIJA_H
#define DCLIENTESHIJA_H
#include "..\..\Ventanas.h"
#include "Clientes.h"

class DClientesHija : public DialogCliente {
	
private:
	Clientes clienteActual;
	bool isEditModeOn;
	int currentClienteNumber;
protected:
	void ClickBoton1( wxCommandEvent& event ) ;
	void ClickBoton2( wxCommandEvent& event ) ;
	
public:
	DClientesHija(wxWindow *parent=NULL);
	void setEditMode(int i);
	~DClientesHija();
};

#endif

