.486
.model flat
.data
	g dq 1.0
	r dq 0
	f dq 0
.code
func proc C x:qword, e:qword
		mov ebx, 3
		fld x
		fstp r
		loo:
		fld x
		mov ecx, ebx
		dec ecx
		step :
		cmp ecx,0
		je prod
			fld x
			fmul
			loop step
			prod:
		fld g
		mov eax, ebx
		jmp f4
			f3:
		fmul
		dec eax
		cmp eax,1
			je f5
			f4:
		mov ecx, 1
			fld g
			fa:
			inc ecx
			fld g
			fadd
			cmp eax, ecx
			je f3
			jmp fa
				f5:
			fdiv
				fst f
				fld r
				fadd
				fstp r
				fld f
				fabs
				fcom e
				fstsw  ax
				test ax, 1 shl 8
				jnz ex
				fstp f
				inc ebx
				inc ebx
				jmp loo
				ex:
				fstp f
				fld r
        ret 
func endp
end