#include "gem_vdiP.h"

/** same as v_gtext()
 *
 *  @param handle Device handle
 *  @param pos coordinate
 *  @param wstr string, with 16 bits per character.
 *  @param num len of the string
 *
 *  @since all VDI versions
 *
 */

void
v_gtext16n (short handle, PXY pos, const short *wstr, short num)
{
	short vdi_control[VDI_CNTRLMAX]; 

	VDI_PARAMS(vdi_control, wstr, (short*)&pos, vdi_dummy, vdi_dummy );
	
	VDI_TRAP (vdi_params, handle, 8, 1,num);
}

