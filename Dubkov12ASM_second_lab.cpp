#include <iostream>

int main() {

	int n, max_index{}, min_index{};

	std::cout << "Input size of the array\n";

	std::cin >> n;


	int* a = new int[n];
	
	std::cout << "Input the elemets of the array\n";

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	int min = a[0], max = a[0];

	__asm {
		xor eax, eax
		xor ebx, ebx
		xor ecx, ecx
		xor esi, esi
		mov ecx,n
	_start:
		mov ebx,a
		mov eax,[ebx][4*esi]
		cmp eax,max
		jnle L1
		jnge L2
	L1:
		mov max,eax
		mov max_index,esi
	L2 :
		nop
	inc esi
	loop _start
	}

	__asm {
		xor eax, eax
		xor ebx, ebx
		xor ecx, ecx
		xor esi, esi
		mov ecx, n
	_begin :
		mov ebx, a
		mov eax, [ebx][4 * esi]
		cmp eax, min
		jl L3
		jg L4
	L3 :
		mov min, eax
		mov min_index, esi
	L4 :
		nop
	inc esi
	loop _begin
	}
	
	__asm {
		mov eax,max_index
		mov ecx,4
		mul ecx
		mov max_index,eax
	}
	
	__asm {
		mov eax, min_index
		mov ecx, 4
		mul ecx
		mov min_index, eax
	}

	std::cout << "\nMin value = " << min << " Max value = " << max << "\nMin index = " << min_index << " Max index = " << max_index;

	std::cout << "\n\n--------------------------------\n\n";
	//1 2 3 4 5 
	__asm {
		mov ecx, max_index
		mov ebx, a
		mov eax, [ebx][ecx]
		mov edx, [ebx][0]
		xchg eax, edx
		mov[ebx][ecx], eax
		mov[ebx][0], edx
	}
	
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << "\t";
	}

	std::cout << "\n\n--------------------------------\n\n";

	int last = (4 * n) - 4;

	//std::cout << "With original array there is an exchange\n";
	
	//5 2 3 4 1
	__asm {
		mov ecx,last
		mov esi,min_index
		mov ebx,a
		mov eax,[ebx][ecx]
		mov edx,[ebx][esi]
		xchg eax,edx
		mov [ebx][ecx],eax
		mov [ebx][esi],edx
	}
	
	for (int i = 0; i < n; ++i) {
		std::cout  << a[i] << "\t";
	}
	

	delete[] a;
	return EXIT_SUCCESS;
}