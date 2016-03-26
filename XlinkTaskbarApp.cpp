/***************************************************************
 * Name:      XlinkTaskbarApp.cpp
 * Purpose:   Code for Application Class
 * Author:    gaoshiqiang (gaoshiqiang@xlink.cn)
 * Created:   2016-03-22
 * Copyright: gaoshiqiang ()
 * License:
 **************************************************************/

#include "XlinkTaskbarApp.h"

#include "XlinkTaskbarMain.h"
#include <wx/image.h>
#include "common.h"

IMPLEMENT_APP(XlinkTaskbarApp);

bool XlinkTaskbarApp::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        // 设置任务栏的taskbar
        m_taskBarIcon = new TaskBarIcon();
        if (!m_taskBarIcon->SetIcon(wxICON(taskbar), "Xlink Settings"))
        {
            wxLogError(wxT("Could not set icon."));
        }

#if defined(__WXOSX__) && wxOSX_USE_COCOA
        m_dockIcon = new TaskBarIcon(wxTBI_DOCK);
        if ( !m_dockIcon->SetIcon(wxICON(sample)) )
        {
            wxLogError(wxT("Could not set icon."));
        }
#endif
#if 0
    	XlinkTaskbarDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
#endif // 0
    }
    return wxsOK;
}

int XlinkTaskbarApp::OnExit()
{
    DELETE_RES(m_taskBarIcon);
#if defined(__WXOSX__) && wxOSX_USE_COCOA
    DELETE_RES(m_dockIcon);
#endif // defined
    return 0;
}
