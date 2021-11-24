/* FlashBlink_hex.cmd -- Hex Converter
 *                       for FlashBlink Demo
 */

/* To use this, from a DOS window.
   To build a hex file, build the
   FlashBlink application using CCS
 * FlashBlink.mak file. After that,
 * open a DOS window in the same dir.
 * and type
 *    >hex6x FlashBlink_ahex.cmd
 *
 * to produce .hex for downloading.
 * Use the FlashBurn application to download.
 */

BlinkDSK6713.out

-a

-memwidth  8

-image

ROMS
{
  FLASH: org = 000h, len = 0x3000,romwidth = 8, files = {BlinkDSK6713.hex}
}
