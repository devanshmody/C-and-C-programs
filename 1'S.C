mov r0,#08h
mov r1,#00h
mov dptr,#0000h
movx a,@dptr
again: rlc a
jnc ahead
inc r1
ahead: djnz r0,again

mov a,r1
mov dptr,#0010h
movx @dptr,a
ret
