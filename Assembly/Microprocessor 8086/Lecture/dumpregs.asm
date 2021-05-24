INCLUDE Irvine32.inc
.stack 100h
.data
.code

main PROC

  mov eax,10000h
  add eax,32000h
  sub eax,22000h
  call DumpRegs
  
  exit

main ENDP
END main
