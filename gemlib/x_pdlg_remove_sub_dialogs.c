
#include "gemx.h"


int
pdlg_remove_sub_dialogs (PRN_DIALOG * prn_dialog)
{
	aes_intin[0] = 4;
	aes_addrin[0] = (long) prn_dialog;
	aes_control[0] = 205;
	aes_control[1] = 1;
	aes_control[2] = 1;
	aes_control[3] = 1;
	aes_control[4] = 0;
	aes (&aes_params);
	return aes_intout[0];
}
