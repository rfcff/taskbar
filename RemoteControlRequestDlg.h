#ifndef __REMOTE_CONTROL_REQUEST_DLG_H
#define __REMOTE_CONTROL_REQUEST_DLG_H

//(*Headers(RemoteControlRequestDlg)
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class RemoteControlRequestDialog : public wxDialog
{
public:
    RemoteControlRequestDialog(const wxString&, const wxString&);
    virtual ~RemoteControlRequestDialog();
private:
    void OnAcceptClicked(wxCommandEvent&);
    void OnRejectClicked(wxCommandEvent&);
    static const long ID_BTNACCEPT;
    static const long ID_BTNDENY;
    wxString mRequestController;
    DECLARE_EVENT_TABLE()
};

#endif // __REMOTE_CONTROL_REQUEST_DLG_H
