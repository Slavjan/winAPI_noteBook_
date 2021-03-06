#include "MainWindow.h"
#include "Button.h"
#include "ListBox.h"
#include "Edit.h"
#include "ChildWindow.h"
#include "Note.h"

MainWindow::MainWindow( HINSTANCE hInstance, int nCmdShow ) : BaseWindow( hInstance, nCmdShow )
{
    Notebook::ReadFromFile( filename );
    hwnd = CreateWindow(wcl_name, "Note Book (WinAPI)",
                        WS_SYSMENU | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
                        0, 0, 230, 180, HWND_DESKTOP, NULL, hInstance, NULL);
    if( !hwnd ) return;

    BaseWindow::AddWindow( hwnd, this );
    MainWindow::InitializeComponent();
    ShowWindow( hwnd, nCmdShow );
    UpdateWindow( hwnd );
}

MainWindow::~MainWindow()
{
    Notebook::SaveToFile( filename );
}

void MainWindow::InitializeComponent()
{

    AddComponent( mainCmpNames::btnAdd, new CppButton( hwnd, 150, 110, 50, 20, "Add", buttonAdd_Click ) );
    AddComponent( mainCmpNames::btnDel, new CppButton( hwnd, 150, 10, 50, 23, "-", buttonDel_Click ) );
    AddComponent( mainCmpNames::listBox, new TListBox( hwnd, 10, 10, 130, 100, listBox1_Click ) );
    AddComponent( mainCmpNames::editTitle, new CppEdit( hwnd, 10, 110, 130, 20, NULL ) );

    UpdateListBox( hwnd );
}

void MainWindow::buttonAdd_Click( HWND sender )
{
    CppEdit *edit1 = ( CppEdit* )_components[sender][mainCmpNames::editTitle];
    CppButton *listBox1 = ( CppButton* )_components[sender][mainCmpNames::listBox];
    GetDlgItemText( sender, edit1->getId(), buf, BUFSIZE );

    SYSTEMTIME time;
    GetSystemTime( &time );
    sprintf_s( buf2, BUFSIZE, "%d:%d", time.wHour, time.wMinute );
    Note note( std::string( buf ), "", std::string( buf2 ) );
    Notebook::AddNote( note );
    Notebook::SaveToFile( filename );

    sprintf_s( buf, BUFSIZE, "%s | %s", note.datetime.c_str(), note.title.c_str() );
    SendMessage( listBox1->getHWND(), LB_ADDSTRING, 0, ( LPARAM )buf );
    SetDlgItemText( sender, edit1->getId(), "" );
}

void MainWindow::buttonDel_Click( HWND sender )
{

    TListBox *listBox1 = ( TListBox* )_components[sender][mainCmpNames::listBox];
    int cur = SendMessage( listBox1->getHWND(), LB_GETCURSEL, 0, 0 );
    Notebook::DeleteNote( cur );

    UpdateListBox( sender );
}

void MainWindow::listBox1_Click( HWND sender )
{

    TListBox *listBox1 = ( TListBox* )_components[sender][mainCmpNames::listBox];
    int cur = SendMessage( listBox1->getHWND(), LB_GETCURSEL, 0, 0 );

    ChildWindow *mw2 = new ChildWindow( NULL, sender, 4, cur );
    mw2->ListenMessages();
    delete mw2;

    UpdateListBox( sender );

    SetActiveWindow( sender );
}

void MainWindow::UpdateListBox( HWND sender )
{
    TListBox *listBox1 = ( TListBox* )_components[sender][mainCmpNames::listBox];
    SendMessage( listBox1->getHWND(), LB_RESETCONTENT, 0, 0 );
    auto notes = Notebook::GetNotes();
    for( auto note = notes.begin(); note != notes.end(); ++note ){
        sprintf_s( buf, BUFSIZE, "%s | %s", note->datetime.c_str(), note->title.c_str() );
        SendMessage( listBox1->getHWND(), LB_ADDSTRING, 0, ( LPARAM )buf );
    }
}
