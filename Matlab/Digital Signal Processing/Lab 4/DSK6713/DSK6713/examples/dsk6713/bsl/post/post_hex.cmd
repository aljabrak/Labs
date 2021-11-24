debug\post.out
-a
-memwidth  8
-map post_hex.map
-boot
-bootorg 0x90000400
-bootsection .boot_load 0x90000000

ROMS
{
    FLASH:  org = 0x90000000, len = 0x10000, romwidth = 8, files = {post.hex}
}
