#ifndef	_errno_h_
#define	_errno_h_

#define E2BIG            1 /*Argument list too long.*/
#define EACCES           2 /*Permission denied.*/
#define EADDRINUSE       3 /*Address in use.*/
#define EADDRNOTAVAIL    4 /*Address not available.*/
#define EAFNOSUPPORT     5 /*Address family not supported.*/
#define EAGAIN           6 /*Resource unavailable, try again (may be the same value as [EWOULDBLOCK]).*/
#define EALREADY         7 /*Connection already in progress.*/
#define EBADF            8/* Bad file descriptor.*/
#define EBADMSG          9 /*Bad message.*/
#define EBUSY           10 /*Device or resource busy.*/
#define ECANCELED       11 /*Operation canceled.*/
#define ECHILD          12 /*No child processes.*/
#define ECONNABORTED    13 /*Connection aborted.*/
#define ECONNREFUSED    14 /*Connection refused.*/
#define ECONNRESET      15 /*Connection reset.*/
#define EDEADLK         16 /*Resource deadlock would occur.*/
#define EDESTADDRREQ    17 /*Destination address required.*/
#define EDOM            18 /*Mathematics argument out of domain of function.*/
#define EDQUOT          19 /*Reserved.*/
#define EEXIST          20 /*File exists.*/
#define EFAULT          21 /*Bad address.*/
#define EFBIG           22 /*File too large.*/
#define EHOSTUNREACH    23 /*Host is unreachable.*/
#define EIDRM           24 /*Identifier removed.*/
#define EILSEQ          25 /*Illegal byte sequence.*/
#define EINPROGRESS     26 /*Operation in progress.*/
#define EINTR           27 /*Interrupted function.*/
#define EINVAL          28 /*Invalid argument.*/
#define EIO             29 /*I/O error.*/
#define EISCONN         30 /*Socket is connected.*/
#define EISDIR          31 /*Is a directory.*/
#define ELOOP           32 /*Too many levels of symbolic links.*/
#define EMFILE          33 /*Too many open files.*/
#define EMLINK          34 /*Too many links.*/
#define EMSGSIZE        35 /*Message too large.*/
#define EMULTIHOP       36 /*Reserved.*/
#define ENAMETOOLONG    37 /*Filename too long.*/
#define ENETDOWN        38 /*Network is down.*/
#define ENETRESET       39 /*Connection aborted by network.*/
#define ENETUNREACH     40 /*Network unreachable.*/
#define ENFILE          41 /*Too many files open in system.*/
#define ENOBUFS         42 /*No buffer space available.*/
#define ENODATA         43 /*[XSR] [Option Start] No message is available on the STREAM head read queue. [Option End]*/
#define ENODEV          44 /*No such device.*/
#define ENOENT          45 /*No such file or directory.*/
#define ENOEXEC         46 /*Executable file format error.*/
#define ENOLCK          47 /*No locks available.*/
#define ENOLINK         48 /*Reserved.*/
#define ENOMEM          49 /*Not enough space.*/
#define ENOMSG          50 /*No message of the desired type.*/
#define ENOPROTOOPT     51 /*Protocol not available.*/
#define ENOSPC          52 /*No space left on device.*/
#define ENOSR           53 /*[XSR] [Option Start] No STREAM resources. [Option End]*/
#define ENOSTR          54 /*[XSR] [Option Start] Not a STREAM. [Option End]*/
#define ENOSYS          55 /*Function not supported.*/
#define ENOTCONN        56 /*The socket is not connected.*/
#define ENOTDIR         57 /*Not a directory.*/
#define ENOTEMPTY       58 /*Directory not empty.*/
#define ENOTSOCK        59 /*Not a socket.*/
#define ENOTSUP         60 /*Not supported.*/
#define ENOTTY          61 /*Inappropriate I/O control operation.*/
#define ENXIO           62 /*No such device or address.*/
#define EOPNOTSUPP      63 /*Operation not supported on socket.*/
#define EOVERFLOW       64 /*Value too large to be stored in data type.*/
#define EPERM           65 /*Operation not permitted.*/
#define EPIPE           66 /*Broken pipe.*/
#define EPROTO          67 /*Protocol error.*/
#define EPROTONOSUPPORT 68 /*Protocol not supported.*/
#define EPROTOTYPE      69 /*Protocol wrong type for socket.*/
#define ERANGE          70 /*Result too large.*/
#define EROFS           71 /*Read-only file system.*/
#define ESPIPE          72 /*Invalid seek.*/
#define ESRCH           73 /* No such process.*/
#define ESTALE          74 /*Reserved.*/
#define ETIME           75 /*[XSR] [Option Start] Stream ioctl() timeout. [Option End]*/
#define ETIMEDOUT       76 /*Connection timed out.*/
#define ETXTBSY         77 /*Text file busy.*/
#define EWOULDBLOCK     78 /*Operation would block (may be the same value as [EAGAIN]).*/
#define EXDEV           79 /*Cross-device link.*/

#endif
