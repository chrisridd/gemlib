/*
 *  $Id$
 */

#include "gem_aesP.h"

/** displays the system file selector and offers
 *  the user an opportunity to choose a complete GEMDOS path
 *  specification.
 *
 *  @param path should be a pointer to a character buffer at least 128
 *		   bytes long (applications wishing to access CD-ROM's  should
 *		   allocate at least 200 bytes). On input the buffer should
 *		   contain a complete GEMDOS path specification including
 *		   a drive specifier, path string, and wildcard mask as
 *		   follows: 'drive:\\path\\mask'. The mask can be any valid
 *		   GEMDOS wildcard (usually *.*).\n
 *         On function exit, \p path contains final path of the selected
 *         file (you will have to strip the mask)
 *  @param file should point to a character buffer 13 bytes long (12
 *         character filename plus NULL). On input its contents will
 *         be placed on the filename line of the selector (usually
 *         this value can simply be a empty string). On function exit,
 *         file contains the filename which the user selected.
 *  @param exit_but is a short pointer which upon function exit will
 *         contain FSEL_CANCEL (0) if the user selected CANCEL or
 *         FSEL_OK (1) if OK.
 *  @param title should be a pointer to a character string up to 30
 *         characters long which contains the title to appear in the
 *         file selector (usually indicates which action the user is
 *         about to take).
 *  @param global_aes global AES array
 *
 *  @return 0 if an error occured and 1 otherwise.
 *
 *  @since Available from AES version 1.40. If an older AES version is detected,
 *         this function will redirect the call to mt_fsel_input().
 *
 *  The path parameter to this function should be validated to
 *  ensure that the path actually exists prior to calling this
 *  function to prevent confusing the user.
 *
 *  This call should always be used as opposed to mt_fsel_input()
 *  when it is available (ie always with this lib). Otherwise, the user has no reminder
 *  as to what function s/he is actually undertaking.
 */

short
mt_fsel_exinput (char *path, char *file, short *exit_but, const char *title, short *global_aes)
{
	if((((gl_ap_version>>8)==1)&&((gl_ap_version&0xFF)>=40))||((gl_ap_version>>8)>1))
	{
		long *ptr_l;
		
		AES_PARAMS(91,0,2,3,0);

		ptr_l = aes_addrin;
		*(ptr_l ++) = (long)path;			/* aes_addrin[0] */
		*(ptr_l ++) = (long)file;			/* aes_addrin[1] */
		*(ptr_l)    = (long)title;			/* aes_addrin[2] */

		AES_TRAP(aes_params);
	
		*exit_but = aes_intout[1];

		return  aes_intout[0];
	}
	else return(mt_fsel_input (path, file, exit_but, global_aes));
}
