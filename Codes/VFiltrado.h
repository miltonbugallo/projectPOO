#ifndef VFILTRADO_H
#define VFILTRADO_H
#include "..\..\Ventanas.h"
#include <vector>
#include "Eventos.h"

class VFiltrado : public VentanaFiltrado {
	
private:
	
protected:
	void DobleClickLabel( wxGridEvent& event ) ;
	void DobleClickGrilla( wxGridEvent& event ) ;
	void CambiarTamanio( wxSizeEvent& event ) ;
	
public:
	VFiltrado(wxWindow *parent=NULL);
	void llenarGrilla(vector<Eventos> eventos);
	~VFiltrado();
};

#endif

