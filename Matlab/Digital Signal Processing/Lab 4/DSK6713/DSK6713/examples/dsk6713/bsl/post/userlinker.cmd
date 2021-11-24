/*
 *  userlinker.cmd
 *
 *  This file is a user specified linker command file that adds a logical
 *  memory section called .boot_load whose contents should be put in the
 *  physical BOOT section specified in the BIOS configuration file post.cdb.
 *
 *  postcfg.cmd is the auto-generated linker command file that reflects
 *  the BIOS configuration settings in the file post.cdb.  The main
 *  memory section definitions and libraries that need to be linked in are
 *  all specified there.  The Code Composer project for the POST uses 
 *  userlinker.cmd as its linker command file.  Post.cmd in turn includes
 *  postcfg.cmd to create a full set of linker definitions. 
 */
 
-l postcfg.cmd

SECTIONS {

    .boot_load > BOOT
 
} 
