.486
.model flat
.data
s1 byte '\0'
s2 byte '\n'
.code
Public _plek
_plek proc
		push ebp
        mov ebp,esp
		mov ecx, [ebp+8]
		cld
		mov esi, [ebp+12]
		g1 : 
		mov edi, [ebp+16]
			mov al, [edi]
			repne scasb
			jcxz vi
			dec esi
			g2:
		inc esi
			inc edi
			mov al, [edi]
			cmp al, s1
			je vr
			cmp al, s2
			je vr
			cmp al,[esi]
			je g2
			jmp g1
			vi:
		mov eax,0
		jmp vt
			vr:
			mov eax,1
			vt:
	    pop ebp
        ret 
_plek endp
end