/* Tcl/Tk command interface for Insight
   Copyright (C) 2001-2017 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#if !defined(GDBTK_CMDS_H)
#define GDBTK_CMDS_H 1

/* A generic call-wrapper to catch longjmps when calling C commands from
   tcl. ALL tcl commands should be wrapped in this call. */
extern int gdbtk_call_wrapper (ClientData, Tcl_Interp *, int, Tcl_Obj * CONST[]);

/* Returns the source (demangled) name for a function at PC. Returns empty string
   if not found. Memory is owned by gdb. Do not free it. */
extern const char *pc_function_name (CORE_ADDR pc);

/* Convenience function to sprintf something(s) into a new element in
   a Tcl list object. */
extern void sprintf_append_element_to_obj (Tcl_Obj * objp, char *format, ...);

/* printf-like function to return error messages */
extern void gdbtk_set_result (Tcl_Interp *interp, const char *fmt,...);

/* Module init routines: Each module of commands should be declared here. */
extern int Gdbtk_Breakpoint_Init (Tcl_Interp *interp);
extern int Gdbtk_Stack_Init (Tcl_Interp *interp);
extern int Gdbtk_Register_Init (Tcl_Interp *interp);

/* replacement for removed gdb function */
const char *symtab_to_filename (struct symtab *s);

#endif /* GDBTK_CMDS_H */
