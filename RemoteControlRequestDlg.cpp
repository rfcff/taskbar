#include "RemoteControlRequestDlg.h"
#include "common.h"
#include "Resource.h"

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

const long RemoteControlRequestDialog::ID_BTNACCEPT = wxNewId();
const long RemoteControlRequestDialog::ID_BTNDENY = wxNewId();

wxBEGIN_EVENT_TABLE(RemoteControlRequestDialog, wxDialog)

wxEND_EVENT_TABLE()

RemoteControlRequestDialog::RemoteControlRequestDialog(const wxString& title, const wxString& controller)
    :wxDialog(NULL, wxID_ANY, title),mRequestController(controller)
{
    wxSizer * const sizerTop = new wxBoxSizer(wxVERTICAL);
    wxSizerFlags flags;
    flags.Border(wxALL, 10);
    sizerTop->Add(new wxStaticText
                      (this,
                        wxID_ANY,
                        controller + wxT("请求远程控制您的计算机。")
                      ), flags);
    //sizerTop->AddStretchSpacer()->SetBorder(10);
    sizerTop->Fit(this);
    wxSizer * const sizerBtns = new wxBoxSizer(wxHORIZONTAL);
    sizerBtns->Add(new wxButton(this, ID_BTNACCEPT, wxT("同 意")), flags);
    sizerBtns->Add(new wxButton(this, ID_BTNDENY, wxT("拒 绝")), flags);
    sizerBtns->AddStretchSpacer()->SetMinSize(wxSize(-1, -1));

    sizerTop->Add(sizerBtns, flags.Align(wxALIGN_CENTER_HORIZONTAL));
    SetSizerAndFit(sizerTop);
    Centre();
}

RemoteControlRequestDialog::~RemoteControlRequestDialog()
{

}

void RemoteControlRequestDialog::OnAcceptClicked(wxCommandEvent&)
{

}



