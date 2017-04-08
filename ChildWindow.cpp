#include "ChildWindow.h"
#include "Edit.h"
#include "Button.h"
#include "Note.h"

void ChildWindow::InitializeComponent() {
	AddComponent(childCmpNames::editTitle, new TEdit(hwnd, 0, 0, 150, 20, NULL));
	AddComponent(childCmpNames::editText, new TEdit(hwnd, 0, 30, 150, 150, NULL));
	AddComponent(childCmpNames::btnSave, new TButton(hwnd, 0, 180, 150, 20, "Save", ButtonSaveClick));
}

ChildWindow::ChildWindow(HINSTANCE hInstance, HWND parent, int nCmdShow, int extra) : BaseWindow(hInstance, nCmdShow) {
	this->_parent = parent;
	this->_noteId = extra;
	hwnd = CreateWindow(wcl_name, "Note Editor",
                        WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		                0, 0, 166, 235, parent, NULL, hInstance, NULL);
	if (!hwnd) return;

	BaseWindow::AddWindow(hwnd, this);
	BaseWindow::GetWindow(parent)->SetEnabled(false);
	ChildWindow::InitializeComponent();
	
	TEdit *editTitle = (TEdit*)GetComponent(hwnd, childCmpNames::editTitle);
	TEdit *editText = (TEdit*)GetComponent(hwnd,   childCmpNames::editText);
	Note note = Notebook::GetNote(extra);
	SetDlgItemText(hwnd, editTitle->getId(), note.title.c_str());
	SetDlgItemText(hwnd, editText->getId(), note.body.c_str());
    ShowWindow( hwnd, nCmdShow );
    SetActive();
    UpdateWindow( hwnd );
}

ChildWindow::~ChildWindow() {
    BaseWindow::GetWindow( _parent )->SetEnabled( true );
}

int ChildWindow::GetExtra() {
    return _noteId;
}

void ChildWindow::ButtonSaveClick(HWND sender) 
{
    TEdit *editTitle = ( TEdit* )GetComponent( sender, childCmpNames::editTitle );
    TEdit *editText = ( TEdit* )GetComponent( sender, childCmpNames::editText );
    GetDlgItemText( sender, editTitle->getId(), buf, BUFSIZE );
    std::string title( buf );
    GetDlgItemText( sender, editText->getId(), buf, BUFSIZE );
    std::string body( buf );
    Notebook::UpdateNote( ( ( ChildWindow* )GetWindow( sender ) )->GetExtra(), title, body );
    Notebook::SaveToFile( filename );
}
