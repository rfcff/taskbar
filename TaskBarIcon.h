#ifndef TASK_BAR_ICON_H
#define TASK_BAR_ICON_H

#include "wx/wx.h"
#include <wx/taskbar.h>
#include <wx/menu.h>

class TaskBarIcon : public wxTaskBarIcon
{
public:
#if defined(__WXOSX__) && wxOSX_USE_COCOA
    TaskBarIcon(wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE)
        :wxTaskBarIcon(iconType)
#else
    TaskBarIcon()
#endif
    {}

    void OnMenuExit(wxCommandEvent&);
    void OnMenuAbout(wxCommandEvent&);
    void OnMenuSetting(wxCommandEvent&);
    void OnMenuRemoteControl(wxCommandEvent&);
    virtual wxMenu *CreatePopupMenu() wxOVERRIDE;

    wxDECLARE_EVENT_TABLE();
};

#endif // TASK_BAR_ICON_H
