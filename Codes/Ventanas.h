///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __VENTANAS_H__
#define __VENTANAS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class VentanaInicial
///////////////////////////////////////////////////////////////////////////////
class VentanaInicial : public wxFrame 
{
	private:
	
	protected:
		wxButton* Clientes;
		wxButton* Eventos;
		wxButton* Proyectos;
		
		// Virtual event handlers, overide them in your derived class
		virtual void AbrirClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void AbrirEventos( wxCommandEvent& event ) { event.Skip(); }
		virtual void AbrirProyectos( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaInicial( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,100 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~VentanaInicial();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaEventos
///////////////////////////////////////////////////////////////////////////////
class VentanaEventos : public wxFrame 
{
	private:
	
	protected:
		wxChoice* m_choice3;
		wxTextCtrl* busqueda;
		wxButton* m_button2;
		wxGrid* grilla;
		wxButton* m_button6;
		wxButton* m_button3;
		wxButton* m_button4;
		
		// Virtual event handlers, overide them in your derived class
		virtual void CambiaTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEditar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaEventos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ventana Eventos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~VentanaEventos();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaClientes
///////////////////////////////////////////////////////////////////////////////
class VentanaClientes : public wxFrame 
{
	private:
	
	protected:
		wxChoice* m_choice3;
		wxTextCtrl* busqueda;
		wxButton* m_button2;
		wxGrid* grilla;
		wxButton* m_button6;
		wxButton* m_button3;
		wxButton* m_button4;
		
		// Virtual event handlers, overide them in your derived class
		virtual void CambiaTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEditar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaClientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ventana Clientes"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~VentanaClientes();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaProyectos
///////////////////////////////////////////////////////////////////////////////
class VentanaProyectos : public wxFrame 
{
	private:
	
	protected:
		wxChoice* m_choice4;
		wxTextCtrl* busqueda;
		wxButton* m_button2;
		wxGrid* grilla;
		wxButton* m_button6;
		wxButton* m_button3;
		wxButton* m_button4;
		
		// Virtual event handlers, overide them in your derived class
		virtual void CambiaTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void DobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEditar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaProyectos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ventana Eventos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~VentanaProyectos();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogCliente
///////////////////////////////////////////////////////////////////////////////
class DialogCliente : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* tx_nombre;
		wxStaticText* m_staticText3;
		wxTextCtrl* tx_apellido;
		wxStaticText* m_staticText4;
		wxTextCtrl* tx_telefono;
		wxStaticText* m_staticText12;
		wxTextCtrl* tx_direccion;
		wxStaticText* m_staticText13;
		wxTextCtrl* tx_localidad;
		wxStaticText* m_staticText14;
		wxTextCtrl* tx_email;
		wxStaticText* m_staticText141;
		wxTextCtrl* tx_email1;
		wxButton* boton1;
		wxButton* boton2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBoton1( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton2( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cliente"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogCliente();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogProyecto
///////////////////////////////////////////////////////////////////////////////
class DialogProyecto : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* tx_nombre;
		wxStaticText* m_staticText3;
		wxTextCtrl* tx_apellido;
		wxStaticText* m_staticText4;
		wxTextCtrl* tx_telefono;
		wxButton* boton1;
		wxButton* boton2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBoton1( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton2( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogProyecto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Proyecto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogProyecto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DialogEventos
///////////////////////////////////////////////////////////////////////////////
class DialogEventos : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* tx_nombre;
		wxStaticText* m_staticText3;
		wxTextCtrl* tx_apellido;
		wxStaticText* m_staticText4;
		wxTextCtrl* tx_telefono;
		wxStaticText* m_staticText47;
		wxTextCtrl* m_textCtrl46;
		wxStaticText* m_staticText49;
		wxTextCtrl* m_textCtrl47;
		wxStaticText* m_staticText50;
		wxTextCtrl* m_textCtrl48;
		wxButton* boton1;
		wxButton* boton2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBoton1( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBoton2( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DialogEventos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Evento"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~DialogEventos();
	
};

#endif //__VENTANAS_H__
