/*
 *  $Id$
 */

#include "gem_vdiP.h"
#include "vdi_userdef.h"


/** returns a string from the keyboard, and returns if the maximum string length is reached or if the user has pressed 
 *  RETURN.
 *
 *  @param handle Device handle
 *  @param len is the maximum length of the string returned in \p vdi_intout.
 *         If \p len 
 *         is negative, the absolute value is considered to be the maximum length and scan 
 *         codes are returned instead of ASCII values.
 *  @param echo 0: no output 1: echo
 *  @param echoxy 
 *  @param str input buffer
 *
 *  @since all VDI versions
 *  @note Use it for work with userdef, not reentrant function!
 */

void
udef_vrq_string (short handle, short len, short echo, short echoxy[], char *str)
{

	VDI_PARAMS(_VDIParBlk.vdi_control, _VDIParBlk.vdi_intin, echoxy, _VDIParBlk.vdi_intout, vdi_dummy );
	
	_VDIParBlk.vdi_intin[0]      = len;
	_VDIParBlk.vdi_intin[1]      = echo;
	
	VDI_TRAP (vdi_params, handle, 31, 1,2);
	
	vdi_array2str (_VDIParBlk.vdi_intout, str, _VDIParBlk.vdi_control[4]);
}
