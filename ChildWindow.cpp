#include "ChildWindow.h"
#include "Edit.h"
#include "Button.h"
#include "Note.h"

void ChildWindow::InitializeComponent() {
	AddComponent(childCmpNames::editTitle, new CppEdit(hwnd, 0, 0, 150, 20, NULL));
	AddComponent(childCmpNames::editText, new CppEdit(hwnd, 0, 30, 150, 150, NULL));
	AddComponent(childCmpNames::btnSave, new CppButton(hwnd, 0, 180, 150, 20, "Save", ButtonSaveClick));
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
	
	CppEdit *editTitle = (CppEdit*)_components[hwnd][childCmpNames::editTitle];
	CppEdit *editText = (CppEdit*) _components[hwnd][childCmpNames::editText];
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

int ChildWindow::getNoteId() {
    return _noteId;
}

void ChildWindow::ButtonSaveClick(HWND sender) 
{
    CppEdit *editTitle = ( CppEdit* )_components[sender][childCmpNames::editTitle];
    CppEdit *editText = ( CppEdit* )_components[sender][childCmpNames::editText];
    GetDlgItemText( sender, editTitle->getId(), buf, BUFSIZE );
    std::string title( buf );
    GetDlgItemText( sender, editText->getId(), buf, BUFSIZE );
    std::string body( buf );
    Notebook::UpdateNote( ( ( ChildWindow* )GetWindow( sender ) )->getNoteId(), title, body );
    Notebook::SaveToFile( filename );
}
