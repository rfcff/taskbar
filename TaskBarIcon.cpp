#include "TaskBarIcon.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(TaskBarIcon)
#include <wx/intl.h>
#include <wx/string.h>
//*)
#include "common.h"
#include "Resource.h"

wxBEGIN_EVENT_TABLE(TaskBarIcon, wxTaskBarIcon)
    EVT_MENU(PU_ABOUT ,TaskBarIcon::OnMenuAbout)
    EVT_MENU(PU_SETTINGS ,TaskBarIcon::OnMenuSetting)
    EVT_MENU(PU_REMOTECONTROL ,TaskBarIcon::OnMenuRemoteControl)
    EVT_MENU(PU_EXIT ,TaskBarIcon::OnMenuExit)
wxEND_EVENT_TABLE()

void TaskBarIcon::OnMenuAbout(wxCommandEvent&)
{
    TRACE("about clicked");
}

void TaskBarIcon::OnMenuSetting(wxCommandEvent&)
{
    wxLogDebug(wxT("OnMenuSetting clicked"));
}

void TaskBarIcon::OnMenuExit(wxCommandEvent&)
{
    wxLogDebug(wxT("OnMenuExit clicked"));
}

void TaskBarIcon::OnMenuRemoteControl(wxCommandEvent&)
{
    wxLogDebug(wxT("OnMenuRemoteControl clicked"));
}

wxMenu *TaskBarIcon::CreatePopupMenu()
{
    wxMenu *menu = new wxMenu();
    menu->Append(PU_ABOUT, wxT("关于"));
    menu->Append(PU_SETTINGS, wxT("设置"));
    menu->Append(PU_REMOTECONTROL, wxT("远控会话窗口"));
    /* OSX has built-in quit menu for the dock menu, but not for the status item */
#ifdef __WXOSX__
    if (OSXIsStatusItem())
#endif // __WXOSX__
    {
        menu->AppendSeparator();
        menu->Append(PU_EXIT, wxT("退出"));
    }
    return menu;
}

