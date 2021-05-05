mov dptr,#0000h
movx a,@dptr
cpl a
inc a
mov dptr,#0010h
movx @dptr,a
ret