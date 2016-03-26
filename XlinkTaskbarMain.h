/***************************************************************
 * Name:      XlinkTaskbarMain.h
 * Purpose:   Defines Application Frame
 * Author:    gaoshiqiang (gaoshiqiang@xlink.cn)
 * Created:   2016-03-22
 * Copyright: gaoshiqiang ()
 * License:
 **************************************************************/

#ifndef XLINKTASKBARMAIN_H
#define XLINKTASKBARMAIN_H

//(*Headers(XlinkTaskbarDialog)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "TaskBarIcon.h"

class XlinkTaskbarDialog: public wxDialog
{
    public:

        XlinkTaskbarDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~XlinkTaskbarDialog();
        void showControlHint(const char *controller);

    private:

        //(*Handlers(XlinkTaskbarDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnNotebook1PageChanged(wxNotebookEvent& event);
        void OnBasicInfoPaint(wxPaintEvent& event);
        void OnCheckBoxRemoteWindowClick(wxCommandEvent& event);
        void OnCheckBoxAuthAccessClick(wxCommandEvent& event);
        void OnRadioButtonRandomAuthSelect(wxCommandEvent& event);
        void OnRadioButtonFixAuthSelect(wxCommandEvent& event);
        void OnCheckBoxAutoStartClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(XlinkTaskbarDialog)
        static const long ID_TXT_STATUS;
        static const long ID_STATICLINE1;
        static const long ID_TXT_DEVICEID;
        static const long ID_TEXT_DEVICEID;
        static const long ID_STATIC_DEVICENAME;
        static const long ID_TEXT_DEVNAME;
        static const long ID_STATICLINE2;
        static const long ID_CHECKBOX_AUTOSTART;
        static const long ID_CHECKBOX_REMOTE_WINDOW;
        static const long ID_TAB_BASICINFO;
        static const long ID_CHECK_AUTHACCESS;
        static const long ID_RADIOBUTTON_RANDOM_AUTH;
        static const long ID_TEXTCTRL_RANDOM_AUTH;
        static const long ID_RADIOBUTTON_FIX_AUTH;
        static const long ID_TEXTCTRL_FIX_AUTH;
        static const long ID_TEXTCTRL1;
        static const long ID_TAB_SECURITY;
        static const long ID_STATICTEXT_LOG;
        static const long ID_TAB_ACCESSLOG;
        static const long ID_NOTEBOOK1;
        static const long ID_BTNOK;
        static const long ID_BTNCANCEL;
        //*)

        //(*Declarations(XlinkTaskbarDialog)
        wxTextCtrl* TextDevID;
        wxTextCtrl* TextCtrlFixAuth;
        wxStaticText* Status;
        wxNotebook* Notebook1;
        wxPanel* AccessLog;
        wxStaticText* StaticTextLog;
        wxCheckBox* CheckBoxRemoteWindow;
        wxPanel* SecuritySettings;
        wxButton* Button1;
        wxBoxSizer* BoxSizer2;
        wxCheckBox* CheckBoxAutoStart;
        wxButton* Button2;
        wxStaticLine* StaticLine2;
        wxStaticText* Name;
        wxPanel* BasicInfo;
        wxRadioButton* RadioButtonFixAuth;
        wxRadioButton* RadioButtonRandomAuth;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrlRandomAuth;
        wxTextCtrl* TextDevName;
        wxTextCtrl* TextCtrl3;
        wxStaticText* DeviceID;
        wxCheckBox* CheckBoxAuthAccess;
        //*)

        TaskBarIcon *m_taskBarIcon;
#if defined(__WXOSX__) && wxOSX_USE_COCOA
        TaskBarIcon *m_dockIcon;
#endif
        DECLARE_EVENT_TABLE()
};

#endif // XLINKTASKBARMAIN_H
