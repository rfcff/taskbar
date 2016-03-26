/***************************************************************
 * Name:      XlinkTaskbarApp.h
 * Purpose:   Defines Application Class
 * Author:    gaoshiqiang (gaoshiqiang@xlink.cn)
 * Created:   2016-03-22
 * Copyright: gaoshiqiang ()
 * License:
 **************************************************************/

#ifndef XLINKTASKBARAPP_H
#define XLINKTASKBARAPP_H

#include <wx/app.h>
#include "TaskBarIcon.h"

class XlinkTaskbarApp : public wxApp
{
public:
    virtual bool OnInit();
    virtual int OnExit();
private:
    TaskBarIcon *m_taskBarIcon;
#if defined(__WXOSX__) && wxOSX_USE_COCOA
    TaskBarIcon *m_dockIcon;
#endif
};

#endif // XLINKTASKBARAPP_H
