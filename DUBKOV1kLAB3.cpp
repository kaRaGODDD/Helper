#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>

int main() {

	char _str[256]{};
	char _buff[256]{};
	char _second_str[256]{};

	std::cout << "Enter text\n";
	std::cin.getline(_str, 100);

	int length_of_the_word{};
	int real_count{};
	int index_to_end{};
	int fake_length{};
	int qlen = strlen(_str);
	
	_str[qlen] = ' '; 
	int len = strlen(_str);

	__asm {
		xor edx, edx
		xor edi,edi
		xor ebx, ebx
		xor eax, eax
		xor ecx, ecx
	_start:
		    cmp len, 0
			jne _forward_iteration
			je  _end_of_the_program
	_forward_iteration :
		    mov ah, [_str + ebx]
			cmp ah, ' '
			jne _continue
			je _check_the_block
	_continue :
		    mov[_buff + edx], ah
			inc length_of_the_word
			inc ebx
			inc edx
			dec len
			jmp _start
	_check_the_block :
		    mov eax, length_of_the_word
			mov[_buff + eax], '\0'
			jmp _block
	}

	__asm {
	_block:
		    xor edx, edx
			mov ecx, length_of_the_word
			mov index_to_end, ecx
			mov length_of_the_word, 0
			inc ebx
			mov fake_length, ecx
			lea esi, _buff
	_checker :
		    cmp fake_length, 0
			jg _begin
			je _next_start
	_begin :
		    mov al, [esi]
			cmp al, 'A'
			jl _goto
			cmp al, 'Z'
			ja _goto
			
			inc esi
			dec fake_length
			inc real_count
			jmp _checker
	}
	

	__asm {
	_goto:
			mov real_count,0
		    cmp ecx, 0
			jne _not_zero_down
			je _start
	_not_zero_down :
		    mov [_buff + ecx -1], ' ' 
			inc esi
			dec ecx
	jmp _goto
	}
	
	__asm {
	_next_start:
		mov edx, real_count
		xor ecx,ecx 
	_asdf :
		    cmp edx, 0
			jne _next_iter
			je _mine
	_next_iter:
		    mov ah, [_buff + ecx]
			mov [_second_str+edi], ah
			inc esi
			dec edx
			inc ecx
			inc edi
			jmp _asdf
	_mine :
			mov [_second_str+edi], ' '
			inc edi
			mov real_count, 0
		    cmp ecx, 0
			jne _replace
			je _start
	_replace :
		    dec ecx
			mov[_buff + ecx], ' '
			jmp _mine
	}



	__asm {
	_end_of_the_program:
		nop
	}

	std::cout << _second_str;

	return EXIT_SUCCESS;
}


