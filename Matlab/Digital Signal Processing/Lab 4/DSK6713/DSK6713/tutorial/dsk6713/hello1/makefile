#  Makefile for creation of the program named by the PROG variable
#
#  The following naming conventions are used by this makefile:
#	<prog>.asm	- C67 assembly language source file
#	<prog>.obj	- C67 object file (compiled/assembled source)
#	<prog>.out	- C67 executable (fully linked program)
#	<prog>cfg.s67	- configuration assembly source file generated
#			  by Configuration Tool
#	<prog>cfg.h67	- configuration assembly header file generated
#			  by Configuration Tool
#	<prog>cfg.cmd	- configuration linker command file generated
#			  by Configuration Tool
#

TI_DIR  := $(subst \,/,$(TI_DIR))
include $(TI_DIR)/c6000/bios/include/c67rules.mak

#
#  Compiler, assembler, and linker options.
#
# -g enable symbolic debugging
CC67OPTS = -g
# -g enable symbolic debugging
AS67OPTS = -g
# -c            ROM autoinotoalization model
# -stack 0x400  set C stack syze to 0x400 words
# -heap 0x400   set heap size to 0x400 words
# -q            quiet run
LD67OPTS = -c -stack 0x400 -heap 0x400 -q

PROG	= hello
OBJS	= vectors.obj
LIBS 	= -lrts6700.lib
CMDS	= $(PROG).cmd

#
#  Targets:
#
all:: $(PROG).out

$(PROG).out: $(OBJS) $(CMDS)
$(PROG).obj:

.clean clean::
	@ echo removing object files and binaries ...
	@$(REMOVE) -f *.obj *.out *.lst *.map



