#pragma once
#include <wx/wx.h>

class App : public wxApp
{
public:
	bool OnInit();
private:
	void mainMenu(wxFrame* frame,wxPanel* panel);
	void addItems(wxCommandEvent& e);
	void deleteItems(wxCommandEvent& e);
	void clearList(wxCommandEvent& e);
	wxCheckListBox* wbox = nullptr;
	wxTextCtrl* txt = nullptr;
	std::vector<wxString> todolist;
	int lastIndex = 0;
};

