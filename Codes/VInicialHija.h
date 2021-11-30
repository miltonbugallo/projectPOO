#ifndef VINICIALHIJA_H
#define VINICIALHIJA_H
#include "..\..\Ventanas.h"

class VInicialHija : public VentanaInicial {
	
private:
	
protected:
	void AbrirClientes( wxCommandEvent& event ) ;
	void AbrirEventos( wxCommandEvent& event ) ;
	void AbrirProyectos( wxCommandEvent& event ) ;
	
public:
	VInicialHija(wxWindow *parent=NULL);
	~VInicialHija();
};

#endif

