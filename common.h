#ifndef __COMMON_H
#define __COMMON_H

#define DEVICE_ID_MAX_LENGTH    128 //设备id最大长度
#define DEVICE_NAME_MAX_LENGTH  128 //设备name最大长度
#define AUTH_CODE_MAX_LENGTH    64  //设备授权码最大长度

#define FREE_RES(res)   if (NULL != res) free(res), res = NULL
#define DELETE_RES(res) if (NULL != res) delete res, res = NULL

#define TRACE(msg)  wxLogDebug(wxT(msg))

#endif // __COMMON_H
