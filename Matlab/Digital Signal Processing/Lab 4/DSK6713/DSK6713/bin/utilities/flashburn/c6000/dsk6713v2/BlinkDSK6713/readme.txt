ReadMe.txt for the BlinkDSK6713 example program
---------------------------------------------


04/11/03 R. Heeschen, Texas Instruments, Inc.
BlinkDSK6713 is an adapted DSK6713 Blink example.


To build and burn the BlinkDSK6713 example program into the Flash Memory of
the DSK6713 (assumes CCS v2.2 is installed):

1) The project file BlinkDSK6713.pjt was created to reside in directory
           C:\ti\bin\utilities\FlashBurn\c6000\DSK6713\FlashBlink6416\
   and assumes that CCS resides in directory
           C:\ti\
2) Create a folder (call it "flash") in the c:\ti\myprojects folder.
   If CCS is installed elsewhere, create a folder within the myprojects folder
   in the location where CCS is installed.

3) Copy all of the files from the BlinkDSK6713 folder this new folder.

4) Run CCS and use the Project Menu to open the project "BlinkDSK6713.pjt"
   CCS may tell you it cannot find library files.

   If you installed Code Composer Studio other than in
   C:\ti\, then you will have to provide paths to the three
   libraries:

       CCS v2.2
       --------
       csl6400.lib ( usually in C:\ti\c6000\cgtools\lib\ )
       rts6400.lib ( usually in C:\ti\c6000\cgtools\lib\ )
          
5) Build the project. This should create the BlinkDSK6713.out file.

6) Set your paths so Windows can find the TI utilties.

      > cd c:\ti
      > dosrun

7) In a DOS window, change to the project directory and run the hex
   conversion utility:

      > cd c:\ti\myprojects\flash
      > hex6x FlashBlink_hex.cmd

   This runs the hex conversion utility (hex6x.exe) with the options
   stated in the command file, FlashBlink_hex.cmd. 
   The hex conversion utility outputs a hex file, BlinkDSK6713.hex.
   The .hex file is the downloadable code.
   NOTE: You can have FlashBurn run the Hex Conversion for you by
         entering "FlashBlink_hex.cmd" into the Conversion Command
         field of a FlashBurn .cdd document. See the FlashBurn
         Application docs and Help for details.

8) Now use the FlashBurn application to program the on-board flash memory.
   You'll get the best results if you run CCS and load and run
   the Gel File, DSK6713.gel

9) After using the FlashBurn application to burn-in the FlashBlink
   program, you can run the FlashBlink program as follows:
   - Close the FlashBurn and CCS applications,
   - Remove and  reapply power to the board.
   You will see the LEDs cycle in an orderly way.
