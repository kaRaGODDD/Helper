.386
PUBLIC  _under
.model flat
.code

_under proc
	push ebp
	mov ebp, esp

	xor eax,eax
	xor edx,edx
	xor esi,esi
	xor edi,edi
	xor ecx,ecx
	xor ebx,ebx

	mov ecx, [ebp+8]
	mov ebx, [ebp + 12]
	mov eax, [ebx]

	_for:
	cmp eax, [ebx]
	jg greater
	mov eax, [ebx]
	mov edx, esi
	greater:
	add ebx,4
	inc esi
	loop _for
	
	xor ebx,ebx
	xor eax,eax
	xor esi,esi
	xor eax,eax

	mov ebx, [ebp + 12]
	mov eax, [ebx]
	mov ecx, [ebp+8]

	_less:
	cmp eax, [ebx]
	jl less
	mov eax, [ebx]
	mov edi, esi
	less:
	add ebx,4
	inc esi
	loop _less

	;edi - less esi - greater

	; change максимальный и первый

	xor ebx,ebx
	xor eax,eax
	xor esi,esi
	xor eax,eax
	
	mov ebx, [ebp + 12]
	mov eax, [ebx]

	mov ecx, [ebx+4*edx]
	xchg ecx,eax
	mov [ebx], eax
	mov [ebx+4*edx],ecx
	

	mov ecx, [ebp+8]
	xor eax,eax

	mov edx, [ebx+ecx*4-4]
	mov esi, [ebx+edi*4]
	xchg esi,edx
	mov [ebx+ecx*4-4], edx
	mov [ebx+edi*4], esi

	pop ebp
	ret 
_under endp
end