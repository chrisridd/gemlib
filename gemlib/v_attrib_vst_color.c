
#include "gem.h"


int
vst_color (int handle, int index)
{
	vdi_intin[0] = index;
	vdi_control[0] = 22;
	vdi_control[1] = 0;
	vdi_control[3] = 1;
	vdi_control[6] = handle;
	vdi (&vdi_params);
	return (int) vdi_intout[0];
}

/*
 * * text attribute
 */
