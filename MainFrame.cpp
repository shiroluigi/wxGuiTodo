#include "MainFrame.h"



MainFrame::MainFrame(const char* title) : 
	wxFrame(nullptr,wxID_ANY,title, wxDefaultPosition ,wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{

}

MainFrame::~MainFrame()
{

}
