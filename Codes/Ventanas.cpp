///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Ventanas.h"

///////////////////////////////////////////////////////////////////////////

VentanaInicial::VentanaInicial( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 3, 0, 0 );
	
	Clientes = new wxButton( this, wxID_ANY, wxT("Clientes"), wxDefaultPosition, wxSize( 150,50 ), 0 );
	gSizer1->Add( Clientes, 0, wxALL, 5 );
	
	Eventos = new wxButton( this, wxID_ANY, wxT("Eventos"), wxDefaultPosition, wxSize( 150,50 ), 0 );
	gSizer1->Add( Eventos, 0, wxALL, 5 );
	
	Proyectos = new wxButton( this, wxID_ANY, wxT("Proyectos"), wxDefaultPosition, wxSize( 150,50 ), 0 );
	gSizer1->Add( Proyectos, 0, wxALL, 5 );
	
	
	this->SetSizer( gSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	Clientes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::AbrirClientes ), NULL, this );
	Eventos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::AbrirEventos ), NULL, this );
	Proyectos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::AbrirProyectos ), NULL, this );
}

VentanaInicial::~VentanaInicial()
{
	// Disconnect Events
	Clientes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::AbrirClientes ), NULL, this );
	Eventos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::AbrirEventos ), NULL, this );
	Proyectos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaInicial::AbrirProyectos ), NULL, this );
	
}

VentanaEventos::VentanaEventos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choice3Choices[] = { wxT("Ciudad"), wxT("Nombre Proyecto"), wxT("Dni Cliente"), wxT("Fecha") };
	int m_choice3NChoices = sizeof( m_choice3Choices ) / sizeof( wxString );
	m_choice3 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice3NChoices, m_choice3Choices, 0 );
	m_choice3->SetSelection( 0 );
	bSizer3->Add( m_choice3, 0, wxALL, 5 );
	
	busqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	busqueda->SetMaxLength( 0 ); 
	bSizer3->Add( busqueda, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla->CreateGrid( 0, 4 );
	grilla->EnableEditing( false );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 219 );
	grilla->SetColSize( 1, 142 );
	grilla->SetColSize( 2, 132 );
	grilla->SetColSize( 3, 177 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( true );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Ciudad") );
	grilla->SetColLabelValue( 1, wxT("Nombre Proyecto") );
	grilla->SetColLabelValue( 2, wxT("DNI Cliente") );
	grilla->SetColLabelValue( 3, wxT("Fecha Evento") );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( true );
	grilla->SetRowLabelSize( 1 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( grilla, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button6, 0, wxALL, 5 );
	
	m_button3 = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL, 5 );
	
	m_button4 = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( VentanaEventos::CambiaTamanio ) );
	busqueda->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaEventos::EnterBuscar ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickBuscar ), NULL, this );
	grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaEventos::DobleClickGrilla ), NULL, this );
	grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaEventos::ClickGrilla ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickAgregar ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickEditar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickEliminar ), NULL, this );
}

VentanaEventos::~VentanaEventos()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( VentanaEventos::CambiaTamanio ) );
	busqueda->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaEventos::EnterBuscar ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickBuscar ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaEventos::DobleClickGrilla ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaEventos::ClickGrilla ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickAgregar ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickEditar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaEventos::ClickEliminar ), NULL, this );
	
}

VentanaClientes::VentanaClientes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choice3Choices[] = { wxT("Nombre"), wxT("DNI") };
	int m_choice3NChoices = sizeof( m_choice3Choices ) / sizeof( wxString );
	m_choice3 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice3NChoices, m_choice3Choices, 0 );
	m_choice3->SetSelection( 1 );
	bSizer3->Add( m_choice3, 0, wxALL, 5 );
	
	busqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	busqueda->SetMaxLength( 0 ); 
	bSizer3->Add( busqueda, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	grilla->CreateGrid( 0, 7 );
	grilla->EnableEditing( false );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 1 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( true );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Nombre") );
	grilla->SetColLabelValue( 1, wxT("DNI") );
	grilla->SetColLabelValue( 2, wxT("Telefono") );
	grilla->SetColLabelValue( 3, wxT("Mail") );
	grilla->SetColLabelValue( 4, wxT("Facebook") );
	grilla->SetColLabelValue( 5, wxT("Direccion") );
	grilla->SetColLabelValue( 6, wxT("Ciudad") );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( true );
	grilla->SetRowLabelSize( 1 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( grilla, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button6, 0, wxALL, 5 );
	
	m_button3 = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL, 5 );
	
	m_button4 = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( VentanaClientes::CambiaTamanio ) );
	busqueda->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaClientes::EnterBuscar ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickBuscar ), NULL, this );
	grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaClientes::DobleClickGrilla ), NULL, this );
	grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaClientes::ClickGrilla ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickAgregar ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickEditar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickEliminar ), NULL, this );
}

VentanaClientes::~VentanaClientes()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( VentanaClientes::CambiaTamanio ) );
	busqueda->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaClientes::EnterBuscar ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickBuscar ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaClientes::DobleClickGrilla ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaClientes::ClickGrilla ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickAgregar ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickEditar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaClientes::ClickEliminar ), NULL, this );
	
}

VentanaProyectos::VentanaProyectos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxString m_choice4Choices[] = { wxT("Nombre"), wxT("Tipo") };
	int m_choice4NChoices = sizeof( m_choice4Choices ) / sizeof( wxString );
	m_choice4 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice4NChoices, m_choice4Choices, 0 );
	m_choice4->SetSelection( 1 );
	bSizer3->Add( m_choice4, 0, wxALL, 5 );
	
	busqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	busqueda->SetMaxLength( 0 ); 
	bSizer3->Add( busqueda, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla->CreateGrid( 0, 3 );
	grilla->EnableEditing( false );
	grilla->EnableGridLines( true );
	grilla->EnableDragGridSize( false );
	grilla->SetMargins( 0, 0 );
	
	// Columns
	grilla->SetColSize( 0, 1 );
	grilla->EnableDragColMove( false );
	grilla->EnableDragColSize( true );
	grilla->SetColLabelSize( 30 );
	grilla->SetColLabelValue( 0, wxT("Nombre") );
	grilla->SetColLabelValue( 1, wxT("Tipo") );
	grilla->SetColLabelValue( 2, wxT("Precio") );
	grilla->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla->EnableDragRowSize( true );
	grilla->SetRowLabelSize( 1 );
	grilla->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( grilla, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button6, 0, wxALL, 5 );
	
	m_button3 = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL, 5 );
	
	m_button4 = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( VentanaProyectos::CambiaTamanio ) );
	busqueda->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaProyectos::EnterBuscar ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickBuscar ), NULL, this );
	grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaProyectos::DobleClickGrilla ), NULL, this );
	grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaProyectos::ClickGrilla ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickAgregar ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickEditar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickEliminar ), NULL, this );
}

VentanaProyectos::~VentanaProyectos()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( VentanaProyectos::CambiaTamanio ) );
	busqueda->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( VentanaProyectos::EnterBuscar ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickBuscar ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaProyectos::DobleClickGrilla ), NULL, this );
	grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( VentanaProyectos::ClickGrilla ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickAgregar ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickEditar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaProyectos::ClickEliminar ), NULL, this );
	
}

DialogCliente::DialogCliente( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL, 5 );
	
	tx_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	tx_nombre->SetMaxLength( 0 ); 
	bSizer5->Add( tx_nombre, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL, 5 );
	
	tx_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_apellido->SetMaxLength( 0 ); 
	bSizer6->Add( tx_apellido, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL, 5 );
	
	tx_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_telefono->SetMaxLength( 0 ); 
	bSizer7->Add( tx_telefono, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer7, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Direccion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer9->Add( m_staticText12, 0, wxALL, 5 );
	
	tx_direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_direccion->SetMaxLength( 0 ); 
	bSizer9->Add( tx_direccion, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Ciudad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer10->Add( m_staticText13, 0, wxALL, 5 );
	
	tx_localidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_localidad->SetMaxLength( 0 ); 
	bSizer10->Add( tx_localidad, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer11->Add( m_staticText14, 0, wxALL, 5 );
	
	tx_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_email->SetMaxLength( 0 ); 
	bSizer11->Add( tx_email, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer11, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText141 = new wxStaticText( this, wxID_ANY, wxT("Facebook:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText141->Wrap( -1 );
	bSizer111->Add( m_staticText141, 0, wxALL, 5 );
	
	tx_email1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_email1->SetMaxLength( 0 ); 
	bSizer111->Add( tx_email1, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	boton1 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton1, 0, wxALL, 5 );
	
	boton2 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton2, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	// Connect Events
	boton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogCliente::ClickBoton1 ), NULL, this );
	boton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogCliente::ClickBoton2 ), NULL, this );
}

DialogCliente::~DialogCliente()
{
	// Disconnect Events
	boton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogCliente::ClickBoton1 ), NULL, this );
	boton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogCliente::ClickBoton2 ), NULL, this );
	
}

DialogProyecto::DialogProyecto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Ciudad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL, 5 );
	
	tx_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_nombre->SetMaxLength( 0 ); 
	bSizer5->Add( tx_nombre, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Tipo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL, 5 );
	
	tx_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_apellido->SetMaxLength( 0 ); 
	bSizer6->Add( tx_apellido, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL, 5 );
	
	tx_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_telefono->SetMaxLength( 0 ); 
	bSizer7->Add( tx_telefono, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer7, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	boton1 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton1, 0, wxALL, 5 );
	
	boton2 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton2, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	// Connect Events
	boton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProyecto::ClickBoton1 ), NULL, this );
	boton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProyecto::ClickBoton2 ), NULL, this );
}

DialogProyecto::~DialogProyecto()
{
	// Disconnect Events
	boton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProyecto::ClickBoton1 ), NULL, this );
	boton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogProyecto::ClickBoton2 ), NULL, this );
	
}

DialogEventos::DialogEventos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Ciudad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL, 5 );
	
	tx_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_nombre->SetMaxLength( 0 ); 
	bSizer5->Add( tx_nombre, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre del proyecto:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL, 5 );
	
	tx_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_apellido->SetMaxLength( 0 ); 
	bSizer6->Add( tx_apellido, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("DNI cliente:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL, 5 );
	
	tx_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	tx_telefono->SetMaxLength( 0 ); 
	bSizer7->Add( tx_telefono, 1, wxALL, 5 );
	
	
	bSizer4->Add( bSizer7, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText47 = new wxStaticText( this, wxID_ANY, wxT("Fecha (DD/MM/AAAA):"), wxPoint( -1,-1 ), wxSize( -1,-1 ), 0 );
	m_staticText47->Wrap( -1 );
	bSizer72->Add( m_staticText47, 0, wxALL, 5 );
	
	m_textCtrl46 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	bSizer72->Add( m_textCtrl46, 0, wxALL, 5 );
	
	m_staticText49 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText49->Wrap( -1 );
	bSizer72->Add( m_staticText49, 0, wxALL, 5 );
	
	m_textCtrl47 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 30,-1 ), 0 );
	bSizer72->Add( m_textCtrl47, 0, wxALL, 5 );
	
	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer72->Add( m_staticText50, 0, wxALL, 5 );
	
	m_textCtrl48 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer72->Add( m_textCtrl48, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer72, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	boton1 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton1, 0, wxALL, 5 );
	
	boton2 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( boton2, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );
	
	// Connect Events
	boton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogEventos::ClickBoton1 ), NULL, this );
	boton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogEventos::ClickBoton2 ), NULL, this );
}

DialogEventos::~DialogEventos()
{
	// Disconnect Events
	boton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogEventos::ClickBoton1 ), NULL, this );
	boton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DialogEventos::ClickBoton2 ), NULL, this );
	
}
