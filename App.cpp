#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>




enum IDs
{
    MAIN_MENU_SUBMIT = wxID_LAST + 1,
    MAIN_MENU_TEXTAREA = wxID_LAST + 2,
    MAIN_MENU_STATICTEXT = wxID_LAST + 3,
    MAIN_MENU_CLEARBUTTON = wxID_LAST + 4
};



wxIMPLEMENT_APP(App);



bool App::OnInit() 
{
    MainFrame* frame = new MainFrame("My gui window");
    frame->SetClientSize(wxSize(800, 600));
    wxPanel* panel = new wxPanel(frame);

    mainMenu(frame, panel);

    frame->Center();
    frame->Show();
    return true;
}

void App::mainMenu( wxFrame* frame, wxPanel* panel)
{
    txt = new wxTextCtrl(panel, IDs(MAIN_MENU_TEXTAREA), "", wxPoint(10, 10), wxSize(600, 25));
    wxButton* addbtn = new wxButton(panel, IDs(MAIN_MENU_SUBMIT), "Add", wxPoint(610, 10), wxSize(180, 25));
    wbox = new wxCheckListBox(panel, IDs(MAIN_MENU_STATICTEXT), wxPoint(10, 40), wxSize(800 - 20, 600 - 100));
    wxButton* deletebutton = new wxButton(panel, IDs(MAIN_MENU_CLEARBUTTON), "Delete", wxPoint(10, 550), wxSize(400 - 20, 25));
    wxButton* clearbtn = new wxButton(panel, IDs(MAIN_MENU_CLEARBUTTON), "Clear", wxPoint(410, 550), wxSize(400 - 20, 25));


    wbox->SetBackgroundColour(wxColour(wxString("white")));


    addbtn->Bind(wxEVT_BUTTON,&App::addItems,this);
    deletebutton->Bind(wxEVT_BUTTON, &App::deleteItems,this);
    clearbtn->Bind(wxEVT_BUTTON, &App::clearList, this);

    frame->CreateStatusBar();
    wxLogStatus("Ready...");
}



void App::addItems(wxCommandEvent& e)
{
    this->wbox->Clear();
    wxString value = this->txt->GetValue();

    if (!value.IsNull())
    {
        this->todolist.push_back(value);
    }
    if (this->todolist.empty())
    {
        return;
    }
    wxLogStatus("Inserted");
    this->txt->Clear();
    this->txt->SetFocus();
    this->wbox->Insert(todolist,0);
}

void App::deleteItems(wxCommandEvent& e)
{
    wxArrayInt items;
    this->wbox->GetCheckedItems(items);
    if (items.IsEmpty()) return;
    for (int i : items)
    {
        this->todolist[i] = wxString(std::to_string(-1));
    }
    while(std::find(this->todolist.begin(), this->todolist.end(), "-1") != this->todolist.end())
        this->todolist.erase(std::find(this->todolist.begin(), this->todolist.end(), "-1"));
    this->wbox->Clear();
    if (this->todolist.empty())
    {
        this->txt->SetFocus();
        return;
    }
    wxLogStatus("Deleted");
    this->txt->SetFocus();
    this->wbox->Insert(todolist, 0);
}

void App::clearList(wxCommandEvent& e)
{
    this->wbox->Clear();
    this->todolist.clear();
    this->txt->SetFocus();
    wxLogStatus("Cleared");
}
