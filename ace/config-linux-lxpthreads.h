/* -*- C++ -*- */
// $Id$

// The following configuration file is designed to work for Linux
// platforms using GNU C++ and L. Xavier's pthreads package.

#if !defined (ACE_CONFIG_H)
#define ACE_CONFIG_H

// Fixes a problem with new versions of Linux...
#ifndef msg_accrights
#undef msg_control
#define msg_accrights msg_control
#endif

#ifndef msg_accrightslen
#undef msg_controllen
#define msg_accrightslen msg_controllen
#endif

#define ACE_HAS_POSIX_TIME
#define ACE_LACKS_STRRECVFD

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC			

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYSCALL_H

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Platforms lacks UNIX domain sockets.
//#define ACE_LACKS_UNIX_DOMAIN_SOCKETS

// Compiler/platform supports alloca().
#define ACE_HAS_ALLOCA

//#define ACE_LACKS_SENDMSG
//#define ACE_LACKS_RECVMSG
#define ACE_LACKS_MSYNC
#define ACE_LACKS_MADVISE

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Compiler/platform supports sys_siglist array.
#define ACE_HAS_SYS_SIGLIST

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

#define ACE_HAS_SUNOS4_GETTIMEOFDAY
#define LINUX 1.2.10

// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
#define ACE_NTRACE 1
#endif /* ACE_NTRACE */

// Linux defines struct msghdr in /usr/include/socket.h
#define ACE_HAS_MSG

// TDN - adapted from file for SunOS4 platforms using the GNU g++ compiler
// Compiler's template mechanism must see source code (i.e., .C files).
#define ACE_TEMPLATES_REQUIRE_SOURCE

#define ACE_TEMPLATES_REQUIRE_SPECIALIZATION

// Compiler doesn't support static data member templates.
#define ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES

// Yes, we do have threads.
#define ACE_HAS_THREADS
// And they're even POSIX pthreads (MIT implementation)
#define ACE_HAS_PTHREADS
#define ACE_MT_SAFE
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_HAS_PTHREADS_XAVIER		// JCEJ 12/19/96
#define ACE_HAS_SIGWAIT
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_THREAD_STACK_ADDR	// JCEJ 12/17/96
#define ACE_LACKS_THREAD_STACK_SIZE	// JCEJ 12/17/96

// To use pthreads on Linux you'll need to use the MIT version, for
// now...
#define _MIT_POSIX_THREADS 1
#include /**/ <pthread.h>

#endif /* ACE_CONFIG_H */
