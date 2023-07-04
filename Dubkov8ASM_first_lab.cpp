#include <iostream>

/*
Из записи натурального числа N выбросить все цифры, кратные заданной, оставив прежним порядок остальных цифр.
*/
int main() {

	int a,
		k,
		sum{},
		i = 1,
		ten = 10;

	std::cin >> a >> k;

	__asm {
		xor eax,eax
		xor ecx,ecx
		mov eax,a
	_start:
			xor edx, edx
			cmp eax, 0
			je _nothing

			div ten
			mov ecx, eax
			mov eax, edx
			xor edx,edx
			div k
			cmp edx,0
			jne _yeah 
			je _yep
	_yeah:
		mov esi,edx
		xor edx,edx
		mul k
		add eax,esi
		xor esi,esi
		mul i //123456789  
		add sum,eax
		xor eax, eax
		cmp ecx,0
		je L1
		mov eax, i
		mul ten
		mov i,eax
		mov eax,ecx
		xor ecx,ecx		
		L1 :
		jmp _start
	_yep:
		mov eax,ecx
		xor ecx,ecx
		jmp _start
			
	jmp _start
	_nothing:
		nop
			
	}
	std::cout << sum << "\n";
	return EXIT_SUCCESS;
}

