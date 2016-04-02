#ifndef __INCLUDES_H
#define __INCLUDES_H


#pragma comment(lib, "fs_stub")
#pragma comment(lib, "sysmodule_stub")
#pragma comment(lib, "c")

// LV2 Access
//#include <ppu-lv2.h>
//#include <ppu-types.h>


#include <cstdlib>
#include <string>
#include <typeinfo>
#include <vector>

#include <assert.h>
#include <cellstatus.h>
#include <fastmath.h>
#include <locale.h>
#include <math.h>
#include <ppu_intrinsics.h>
#include <pthread.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#include <cell/cell_fs.h>
#include <cell/dbgfont.h>
#include <cell/error.h>
#include <cell/sysmodule.h>
//#include "cellframework/utility/OSKUtil.h"
//#include "cellframework/input/cellInput.h"
#include <cell/fs/cell_fs_errno.h>
#include <cell/fs/cell_fs_file_api.h>
//#include <cell/pad/libpad.h>
#include <cell/pad.h>

#include <sys/memory.h>
#include <sys/paths.h>
#include <sys/ppu_thread.h>
#include <sys/process.h>
#include <sys/prx.h>
#include <sys/random_number.h>
#include <sys/return_code.h>
#include <sys/spu_initialize.h>
#include <sys/syscall.h>
#include <sys/sys_time.h>
#include <sys/socket.h>
#include <sys/time_util.h>
#include <sys/timer.h>
#include <sys/types.h>

#include <sysutil/sysutil_oskdialog.h>
#include <sysutil/sysutil_msgdialog.h>
//#include <sysutil/sysutil_rec.h>
//#include <sysutil/sysutil_video_upload.h>

//#include <net\if_dl.h>
//#include <netinet/in.h>
//#include <netinet/in.h>

//#include <arpa/inet.h>

#include <PSGL/psglu.h>

//#include "Common/gfxCommon.h"


#define _sprintf(out, t, ...) Natives::snprintf(out, sizeof(out), t, __VA_ARGS__)//Thanks Cael

#define Print(out, t, ...) Natives::snprintf(out, sizeof(out), t, __VA_ARGS__)



#endif

