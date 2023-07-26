#include "leitura.hpp"
#include <time.h>
#include <locale>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main() {
    _;

    setlocale(LC_ALL, "pt_BR.UTF-8");

    double timespent = 0.0;

    clock_t begin = clock();
    readPrincipal();
    clock_t end = clock();

    timespent += (double)(end - begin) / CLOCKS_PER_SEC;

    cout << timespent << endl;

    return 0;
}
