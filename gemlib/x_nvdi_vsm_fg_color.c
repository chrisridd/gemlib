
#include "gemx.h"


int
vsm_fg_color (int handle, long color_space, COLOR_ENTRY * fg_color)
{
	*(long *) &vdi_intin[0] = color_space;
	*(COLOR_ENTRY *) & vdi_intin[2] = *fg_color;

	vdi_control[0] = 200;
	vdi_control[1] = 0;
	vdi_control[3] = 6;
	vdi_control[5] = 3;
	vdi_control[6] = handle;
	vdi (&vdi_params);

	return vdi_intout[0];
}

/*
 * * NOTE: requires NVDI version 5.x or higher
 */
