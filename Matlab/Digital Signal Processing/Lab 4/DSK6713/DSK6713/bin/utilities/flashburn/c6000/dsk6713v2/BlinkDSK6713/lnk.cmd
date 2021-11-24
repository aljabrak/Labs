MEMORY
{
    vecs:          o = 00000000h   l = 00000200h
    boot:          o = 00000200h   l = 00000200h
    IRAM:          o = 00000400h   l = 0000FA00h                           
    CE0:	       o = 80000000h   l = 01000000h 
                                                              
}

SECTIONS
{
    "vectors"   >       vecs
    "bootload"  >       boot
    .cinit      >       IRAM
    .text       >       IRAM
    .stack      >       IRAM
    .bss        >       IRAM
    .const      >       IRAM
    .data       >       IRAM
    .far        >       IRAM
    .switch     >       IRAM
    .sysmem     >       IRAM
    .tables     >       IRAM
    .cio        >       IRAM
}                             

 
