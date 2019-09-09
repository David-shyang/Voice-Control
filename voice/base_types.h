/*
	Copyright (c) 2002 Cyberon Corp.  All right reserved.
	File: base_types.h
	Desc: Define all base types
	Author: Alan
	Date: 2002/7/21
	FixBug: 2002/11/18 William
	Version : 1.30.00
*/

#ifndef	__BASE_TYPES_H
#define	__BASE_TYPES_H

	typedef signed char CHAR;
	typedef unsigned char BYTE;
	typedef signed short SHORT;
	typedef unsigned short WORD;
	typedef signed long LONG;
	typedef unsigned int DWORD;
	typedef signed int INT;
	typedef unsigned int UINT;
	typedef void *HANDLE;
	typedef int BOOL;
	typedef WORD UNICODE;
	typedef void VOID;

#ifndef TRUE
#define TRUE	(1 == 1)
#endif

#ifndef FALSE
#define FALSE	(1 == 0)
#endif

#endif	/* #ifndef	__BASE_TYPES_H */
