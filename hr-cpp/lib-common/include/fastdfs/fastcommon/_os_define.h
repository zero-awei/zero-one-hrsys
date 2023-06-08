#ifndef _OS_DEFINE_H
#define _OS_DEFINE_H

#define OS_BITS  64
#define OFF_BITS 64

#ifndef OS_LINUX
#define OS_LINUX  1
#endif

#ifndef IOEVENT_USE_EPOLL
#define IOEVENT_USE_EPOLL  1
#endif

#ifndef HAVE_VMMETER_H
#define HAVE_VMMETER_H 0
#endif

#ifndef HAVE_USER_H
#define HAVE_USER_H 0
#endif

#define HAVE_DIRENT_D_TYPE  1
#define HAVE_DIRENT_D_RECLEN  1
#define HAVE_DIRENT_D_OFF  1

#endif
