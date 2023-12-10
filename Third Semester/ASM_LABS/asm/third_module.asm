.386
PUBLIC  @joke@8
.model flat
.code
@joke@8 proc

	mov ebx, ecx 
	mov ecx, edx 
	mov edx, ebx
	mov eax,[ebx]

	

	xor edi,edi
	xor esi,esi

	_for:
	cmp eax, [ebx]
	jg greater
	mov eax, [ebx]
	mov edi, esi
	greater:
	add ebx,4
	inc esi
	loop _for

	mov ebx,edx
	mov ecx, esi
	xor esi,esi


	_less:
	cmp eax, [ebx]
	jl less
	mov eax, [ebx]
	mov edx, esi
	less:
	add ebx,4
	inc esi
	loop _less

	mov ecx,esi

	_asdf: 
	cmp esi, 0
	je _continue
	jne _mark
	_mark:
		sub ebx, 4
		dec esi
	jmp _asdf



	_continue:
	
	
	mov eax,[ebx] 
	mov esi,[ebx+edi*4] 
	xchg eax,esi
	mov [ebx], eax
	mov [ebx+edi*4], esi

	xor esi,esi
	xor eax,eax
	
	mov eax,[ebx+ecx*4-4]
	mov esi,[ebx+edx*4]
	xchg eax,esi
	mov [ebx+ecx*4-4], eax
	mov [ebx+edx*4],esi
	
	

	ret
@joke@8 endp
end