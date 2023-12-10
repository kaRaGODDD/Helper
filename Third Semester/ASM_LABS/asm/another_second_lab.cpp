#include <iostream>

int main() {
    setlocale(LC_ALL, "RUS");
    int n{}, N{}, temp{}, another{};
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Число должно быть больше нуля!\n";
        return 1;
    }

    int* a = new int[n];
    
    std::cout << "Сколько наименьших чисел вы хотите удалить?\nВведите количество: ";
    std::cin >> N;
    if (N <= 0 || N > n) {
        std::cout << "Число должно быть больше нуля и меньше размера массива!\n";
        return 1;
    }

    std::cout << "Введите элементы массива: ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << "Результат: ";

    // сортировка
    __asm {
        xor eax, eax
        xor ebx, ebx
        xor edx, edx
        xor ecx, ecx
        xor esi, esi
        xor edi, edi
        
        mov edi, a
        mov edx, n
        
    _start_external:
        xor esi, esi
        inc ecx
        cmp ecx, n
        je _end
        mov eax, [edi][ecx * 4]
    _inner_start:
        cmp esi, edx
        je _start_external
        mov ebx, [edi][esi * 4]
        cmp ebx, eax
        jge _first_loop
        jle _inc   
     _first_loop:
        mov edx, [edi][ecx * 4]
        mov temp, eax
        mov eax, [edi][esi * 4]
        mov [edi][esi * 4], edx
        mov edx, eax
        mov [edi][ecx * 4],edx
        xor edx, edx
        mov edx, n
    _inc:
        inc esi
        jmp _inner_start
    }

    __asm {
    _end:
        nop
    }

    // заполнение нулями
    __asm {
        xor eax,eax
        xor ebx,ebx
        xor edx,edx
        xor ecx,ecx
        xor esi,esi
        xor edi,edi

        mov edi, a
        mov ecx, n
        mov edx, N

    _zero_fill:
        cmp edx, 0
        je _replace
        push edx
        xor edx, edx
        mov [edi][esi * 4], edx
        pop edx
        inc esi
        dec edx
        jmp _zero_fill
    }

    __asm {
    _replace:
        nop
    }

    __asm {
        xor eax, eax
        xor ebx, ebx
        xor edx, edx
        xor ecx, ecx
        xor esi, esi
        xor edi, edi

        mov edi, a
        mov ecx, 0
        mov ecx, n
      _move_elements :
       cmp ecx, 0
       je _exit1
       mov eax, [edi][esi*4]
       cmp eax, 0
       jne _output1
       inc esi
       dec ecx
    jmp _move_elements
    }

    __asm {
    _output1:
        mov edx, [edi][esi*4]
        mov another, edx
        inc esi
        dec ecx
        push esi
        push ecx
    }

    std::cout << another << " ";

    __asm {
        xor eax, eax
        xor ebx, ebx
        xor edx, edx
        xor ecx, ecx
        xor esi, esi
        xor edi, edi

        mov edi, a
        pop ecx
        pop esi
        jmp _move_elements
    }
    
    __asm {
    _exit1:
        nop
    }
    
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << 0 << " ";
    }


    return 0;
}
