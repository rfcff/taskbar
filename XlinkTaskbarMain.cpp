/***************************************************************
 * Name:      XlinkTaskbarMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    gaoshiqiang (gaoshiqiang@xlink.cn)
 * Created:   2016-03-22
 * Copyright: gaoshiqiang ()
 * License:
 **************************************************************/

#include "XlinkTaskbarMain.h"
#include "RemoteControlRequestDlg.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(XlinkTaskbarDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(XlinkTaskbarDialog)
const long XlinkTaskbarDialog::ID_TXT_STATUS = wxNewId();
const long XlinkTaskbarDialog::ID_STATICLINE1 = wxNewId();
const long XlinkTaskbarDialog::ID_TXT_DEVICEID = wxNewId();
const long XlinkTaskbarDialog::ID_TEXT_DEVICEID = wxNewId();
const long XlinkTaskbarDialog::ID_STATIC_DEVICENAME = wxNewId();
const long XlinkTaskbarDialog::ID_TEXT_DEVNAME = wxNewId();
const long XlinkTaskbarDialog::ID_STATICLINE2 = wxNewId();
const long XlinkTaskbarDialog::ID_CHECKBOX_AUTOSTART = wxNewId();
const long XlinkTaskbarDialog::ID_CHECKBOX_REMOTE_WINDOW = wxNewId();
const long XlinkTaskbarDialog::ID_TAB_BASICINFO = wxNewId();
const long XlinkTaskbarDialog::ID_CHECK_AUTHACCESS = wxNewId();
const long XlinkTaskbarDialog::ID_RADIOBUTTON_RANDOM_AUTH = wxNewId();
const long XlinkTaskbarDialog::ID_TEXTCTRL_RANDOM_AUTH = wxNewId();
const long XlinkTaskbarDialog::ID_RADIOBUTTON_FIX_AUTH = wxNewId();
const long XlinkTaskbarDialog::ID_TEXTCTRL_FIX_AUTH = wxNewId();
const long XlinkTaskbarDialog::ID_TEXTCTRL1 = wxNewId();
const long XlinkTaskbarDialog::ID_TAB_SECURITY = wxNewId();
const long XlinkTaskbarDialog::ID_STATICTEXT_LOG = wxNewId();
const long XlinkTaskbarDialog::ID_TAB_ACCESSLOG = wxNewId();
const long XlinkTaskbarDialog::ID_NOTEBOOK1 = wxNewId();
const long XlinkTaskbarDialog::ID_BTNOK = wxNewId();
const long XlinkTaskbarDialog::ID_BTNCANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(XlinkTaskbarDialog,wxDialog)
    //(*EventTable(XlinkTaskbarDialog)
    //*)
END_EVENT_TABLE()

XlinkTaskbarDialog::XlinkTaskbarDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(XlinkTaskbarDialog)
    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Notebook1->SetFocus();
    BasicInfo = new wxPanel(Notebook1, ID_TAB_BASICINFO, wxDefaultPosition, wxSize(540,300), wxTAB_TRAVERSAL, _T("ID_TAB_BASICINFO"));
    Status = new wxStaticText(BasicInfo, ID_TXT_STATUS, _("程序状态：未登录"), wxPoint(15,20), wxDefaultSize, 0, _T("ID_TXT_STATUS"));
    StaticLine1 = new wxStaticLine(BasicInfo, ID_STATICLINE1, wxPoint(15,50), wxSize(515,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    DeviceID = new wxStaticText(BasicInfo, ID_TXT_DEVICEID, _("设备ID："), wxPoint(15,70), wxDefaultSize, 0, _T("ID_TXT_DEVICEID"));
    TextDevID = new wxTextCtrl(BasicInfo, ID_TEXT_DEVICEID, wxEmptyString, wxPoint(15,90), wxSize(500,25), 0, wxDefaultValidator, _T("ID_TEXT_DEVICEID"));
    TextDevID->SetMaxLength(128);
    TextDevID->SetHelpText(_("设备ID"));
    Name = new wxStaticText(BasicInfo, ID_STATIC_DEVICENAME, _("名称："), wxPoint(15,130), wxDefaultSize, 0, _T("ID_STATIC_DEVICENAME"));
    TextDevName = new wxTextCtrl(BasicInfo, ID_TEXT_DEVNAME, wxEmptyString, wxPoint(15,150), wxSize(500,25), 0, wxDefaultValidator, _T("ID_TEXT_DEVNAME"));
    TextDevName->SetMaxLength(128);
    TextDevName->SetHelpText(_("设备名字"));
    StaticLine2 = new wxStaticLine(BasicInfo, ID_STATICLINE2, wxPoint(15,190), wxSize(515,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    CheckBoxAutoStart = new wxCheckBox(BasicInfo, ID_CHECKBOX_AUTOSTART, _("随计算机启动"), wxPoint(15,210), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_AUTOSTART"));
    CheckBoxAutoStart->SetValue(false);
    CheckBoxRemoteWindow = new wxCheckBox(BasicInfo, ID_CHECKBOX_REMOTE_WINDOW, _("远程时自动显示会话窗口"), wxPoint(15,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_REMOTE_WINDOW"));
    CheckBoxRemoteWindow->SetValue(false);
    SecuritySettings = new wxPanel(Notebook1, ID_TAB_SECURITY, wxDefaultPosition, wxSize(540,300), wxTAB_TRAVERSAL, _T("ID_TAB_SECURITY"));
    CheckBoxAuthAccess = new wxCheckBox(SecuritySettings, ID_CHECK_AUTHACCESS, _("启用授权码访问"), wxPoint(15,20), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECK_AUTHACCESS"));
    CheckBoxAuthAccess->SetValue(false);
    RadioButtonRandomAuth = new wxRadioButton(SecuritySettings, ID_RADIOBUTTON_RANDOM_AUTH, _("使用随机授权码"), wxPoint(30,55), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON_RANDOM_AUTH"));
    RadioButtonRandomAuth->Disable();
    TextCtrlRandomAuth = new wxTextCtrl(SecuritySettings, ID_TEXTCTRL_RANDOM_AUTH, wxEmptyString, wxPoint(30,80), wxSize(200,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL_RANDOM_AUTH"));
    TextCtrlRandomAuth->SetMaxLength(64);
    TextCtrlRandomAuth->Disable();
    RadioButtonFixAuth = new wxRadioButton(SecuritySettings, ID_RADIOBUTTON_FIX_AUTH, _("使用固定授权码"), wxPoint(30,125), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON_FIX_AUTH"));
    RadioButtonFixAuth->Disable();
    TextCtrlFixAuth = new wxTextCtrl(SecuritySettings, ID_TEXTCTRL_FIX_AUTH, wxEmptyString, wxPoint(30,150), wxSize(200,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL_FIX_AUTH"));
    TextCtrlFixAuth->SetMaxLength(64);
    TextCtrlFixAuth->Disable();
    TextCtrl3 = new wxTextCtrl(SecuritySettings, ID_TEXTCTRL1, wxEmptyString, wxPoint(250,150), wxSize(200,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl3->SetMaxLength(64);
    TextCtrl3->Disable();
    AccessLog = new wxPanel(Notebook1, ID_TAB_ACCESSLOG, wxDefaultPosition, wxSize(540,300), wxTAB_TRAVERSAL, _T("ID_TAB_ACCESSLOG"));
    StaticTextLog = new wxStaticText(AccessLog, ID_STATICTEXT_LOG, _("当前无系统日志"), wxPoint(0,0), wxSize(540,300), 0, _T("ID_STATICTEXT_LOG"));
    Notebook1->AddPage(BasicInfo, _("基本信息"), false);
    Notebook1->AddPage(SecuritySettings, _("安全设置"), false);
    Notebook1->AddPage(AccessLog, _("访问日志"), false);
    BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND, 10);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BTNOK, _("确 定"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNOK"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BTNCANCEL, _("取 消"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNCANCEL"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_RIGHT, 10);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_CHECKBOX_AUTOSTART,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnCheckBoxAutoStartClick);
    Connect(ID_CHECKBOX_REMOTE_WINDOW,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnCheckBoxRemoteWindowClick);
    BasicInfo->Connect(wxEVT_PAINT,(wxObjectEventFunction)&XlinkTaskbarDialog::OnBasicInfoPaint,0,this);
    Connect(ID_CHECK_AUTHACCESS,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnCheckBoxAuthAccessClick);
    Connect(ID_RADIOBUTTON_RANDOM_AUTH,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnRadioButtonRandomAuthSelect);
    Connect(ID_RADIOBUTTON_FIX_AUTH,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnRadioButtonFixAuthSelect);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnNotebook1PageChanged);
    Connect(ID_BTNOK,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnAbout);
    Connect(ID_BTNCANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XlinkTaskbarDialog::OnQuit);
    //*)

    // 设置任务栏的taskbar
    m_taskBarIcon = new TaskBarIcon();
    if (!m_taskBarIcon->SetIcon(wxICON(taskbar), "Xlink Settings")) {
        wxLogError(wxT("Could not set icon."));
    }

#if defined(__WXOSX__) && wxOSX_USE_COCOA
    m_dockIcon = new TaskBarIcon(wxTBI_DOCK);
    if ( !m_dockIcon->SetIcon(wxICON(sample)) )
    {
        wxLogError(wxT("Could not set icon."));
    }
#endif

    showControlHint("gaoshiqiang");

    RemoteControlRequestDialog *pRequestControlDlg = new RemoteControlRequestDialog(wxT("远程控制"), "gaoshiqiang");
    pRequestControlDlg->Show();
}

XlinkTaskbarDialog::~XlinkTaskbarDialog()
{
    //(*Destroy(XlinkTaskbarDialog)
    //*)
}

void XlinkTaskbarDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void XlinkTaskbarDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void XlinkTaskbarDialog::OnNotebook1PageChanged(wxNotebookEvent& event)
{
}

void XlinkTaskbarDialog::OnBasicInfoPaint(wxPaintEvent& event)
{
}

void XlinkTaskbarDialog::OnCheckBoxRemoteWindowClick(wxCommandEvent& event)
{
}

void XlinkTaskbarDialog::OnCheckBoxAuthAccessClick(wxCommandEvent& event)
{
}

void XlinkTaskbarDialog::OnRadioButtonRandomAuthSelect(wxCommandEvent& event)
{
}

void XlinkTaskbarDialog::OnRadioButtonFixAuthSelect(wxCommandEvent& event)
{
}

void XlinkTaskbarDialog::OnCheckBoxAutoStartClick(wxCommandEvent& event)
{
}

/** \brief
 * 收到被控制消息时任务栏弹出提示
 * \param controller const char* 控制者名字
 * \return void
 *
 */
void XlinkTaskbarDialog::showControlHint(const char *controller)
{
    static const char * const title = "About wxWidgets Taskbar Sample";
    wxString message(controller);
    message += wxT("正在控制您的计算机。按Ctrl + Alt + Esc终止远程控制。");

#if defined(__WXMSW__) && wxUSE_TASKBARICON_BALLOONS
    m_taskBarIcon->ShowBalloon(title, message, 15000, wxICON_INFORMATION);
#else // !__WXMSW__
    wxMessageBox(message, title, wxICON_INFORMATION|wxOK, this);
#endif // __WXMSW__/!__WXMSW__
}
