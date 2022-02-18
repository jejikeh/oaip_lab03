// lab03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>



int main()
{
    void task_1();
    void task_2();
    void task_3();
    void task_4();
    void task_5();


    void* malloc(size_t bytes); // функция для выделения памяти
    void* calloc(size_t num, size_t size); // выделяет память для num объектов 
    void* realloc(void* ptr, size_t size); // копирует содержимое блока ptr до size
    void free(void* ptr); // освобождает память

    float task;
    printf("TASK = "); scanf_s("%f", &task);

    // 1

    if (task == 1) {
        task_1();
    }
    else if (task == 2) {
        task_2();
    }
    else if (task == 3) {
        task_3();
    }
    else if (task == 4) {
        task_4();
    }
    else if (task == 5) {
        task_5();
    }
    else {
        printf("WRONG TASK \n");
        main();
    }



    /*
        char* p = (char*)malloc(18 * sizeof(char)); // указатель для которого выделено памяти на 18 int;
        if (!p) { std::cout << "out of memory." << std::endl; exit(1); }

        strcpy(p, "whit is 17 symbol");
        p = (char*) realloc(p, 19);
        if (!p) { std::cout << "out of memory." << std::endl; exit(1); }

        strcat(p, ".");
        printf(p);
        free(p);
    */


    /*
        int* a;
        int i, n;

        std::cout << "Input size of array: ";
        std::cin >> n;

        a = (int*)malloc(n * sizeof(int)); // выделение памяти n bytes

        for (i = 0; i < n; i++) {
            std::cout << "a [" << i << "] = ";
            std::cin >> a[i];
        }

        for (i = 0; i < n; i++) {
            std::cout << " [" << a[i] << "] ";
        }
        std::cout << std::endl;

        free(a); // освобождение памяти
        return 0;

    */

    

}

void task_1() {

    char* strcpy(char* dest, const char* src);
    char* a;

    a = (char*)malloc(sizeof(char*));
    if (!a) { std::cout << "out of memory." << std::endl; exit(1); }
    strcpy(a, "a");

    printf(a);
    free(a);
    std::cout << std::endl;
    main();
}

void task_3() {

    int* a;
    int i, n;

    std::cout << "Input size of array: ";
    std::cin >> n;

    a = (int*)malloc(n * sizeof(int)); // выделение памяти n bytes

    for (i = 0; i < n; i++) {
        std::cout << "a [" << i << "] = ";
        std::cin >> a[i];
    }

    for (i = 0; i < n; i++) {
        std::cout << " [" << a[i] << "] ";
    }
    std::cout << std::endl;

    free(a); // освобождение памяти
    main();
}

void task_2() {
    char* strcat(char* dst, const char* src);
    char* strcpy(char* dest, const char* src);
    char* strncpy(char* dst, const char* src, size_t num);
    void* realloc(void* ptr, size_t size); // копирует содержимое блока ptr до size
    char* a;
    int n,m;
    size_t size;
    std::cout << "Input a string length: ";
    std::cin >> n;
    a = (char*)malloc(n * sizeof(char));
    if (!a) { std::cout << "out of memory." << std::endl; exit(1); }
    std::cout << "Input a string: ";
    std::cin >> a;
    if (strlen(a) > 5) {
        for (int i = 0; i < strlen(a); i++) {
            if (i < 5) {
                continue;
            }
            else {
                a[i] = NULL;
            }
        }
    }
    strcat(a, "\0");
    printf(a);
    std::cout << std::endl;


    std::cout << "add length: ";
    std::cin >> m;
    char* old_a;
    size = _msize(a);
    //std::cout << size;
    std::cout << std::endl;
    a = (char*) realloc(a, size + (m * sizeof(char) + (1 * sizeof(char))));
    //p = (char*)malloc(n + m);
    //strcpy(p, a);

    //free(a);
    int n_size;
    n_size = _msize(a);
    //std::cout << n_size;
    std::cout << std::endl;



    for (int i = size; i < n_size ; i++) {
        a[i] = 42;
    }
    for (int i = 0; i < n_size - 1; i++){
        std::cout << a[i];
    }

    //printf(a);
    free(a);
    std::cout << std::endl;
    main();
}


void task_4() {
    char** a;
    int i, j, n, * m;

    std::cout << "Input a number of rows: "; std::cin >> n;

    a = (char**)malloc(n * sizeof(char*)); // память для хранения указателей
    m = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) { // строчки
        std::cout << "Input a number of collumns "<< i << " : ";
        std::cin >> m[i];
        a[i] = (char*)malloc(m[i] * sizeof(char)); // память для хранения строк
        for (j = 0; j < m[i]; j++) { // столбцы
            std::cout << "a [" << i << "]  [" << j << "] = ";
            std::cin >> a[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m[i]; j++) {
            std::cout << " [" << a[i][j] << "] ";
        }
        free(a[i]); // освобождение памяти под строки
        std::cout << std::endl;
    }
    free(a); // освобождение памяти под указатели
    free(m);

    main();
}

void task_5() {
    char** a;
    int i, j, n, * m;
    std::cout << "Input a number of rows: "; std::cin >> n;

    a = (char**)malloc(n * sizeof(char*)); // память для хранения указателей
    m = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) { // строчки
        std::cout << "Input a number of collumns " << i << " : ";
        std::cin >> m[i];
        a[i] = (char*)malloc(m[i] * sizeof(char)); // память для хранения строк
        for (j = 0; j < m[i]; j++) { // столбцы
            std::cout << "a [" << i << "] " << " [" << j << "] = ";
            char s[] = "";
            std::cin >> s;
            std::cout << int(s);
            a[i][j] = int(s);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m[i]; j++) {
            std::cout << " [" << char(a[i][j]) << "] ";
        }
       free(a[i]); // освобождение памяти под строки
        std::cout << std::endl;
    }
    free(a); // освобождение памяти под указатели
    free(m);

    main();


}