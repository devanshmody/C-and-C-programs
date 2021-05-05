mov dptr,#0000h
movx a,@dptr
mov 0f0h,a
mov dptr,#0010h
movx a,@dptr
subb a,b
mov dptr,#0020h
movx @dptr,a
ret