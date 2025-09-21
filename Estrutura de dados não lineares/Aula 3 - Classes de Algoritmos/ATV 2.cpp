#include <iostream>
#include <vector>
#include <functional>

// Funções de exemplo com complexidades diferentes

// No O(n) o tempo foi de 0.67 segundos
long long f_linear(long long n) {
    long long cont = 0;
    for (long long i = 0; i < n; i++) {
        cont++;
    }
    return cont;
}

// No O(n^2) o tempo foi de 20.98 segundos
long long f_quadratic(long long n) {
    long long cont = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            cont++;
        }
    }
    return cont;
}

// No O(n log n) o tempo foi de 0.57 segundos
long long f_nlogn(long long n) {
    long long cont = 0;
    for (long long i = 0; i < n; i++) {
        long long temp = n;
        while (temp > 1) {
            temp /= 2;
            cont++;
        }
    }
    return cont;
}

// Estrutura para agrupar nome e função
struct FunctionTest {
    const char* name;
    std::function<long long(long long)> func;
};

int main() {
    std::cout << "Calculando o numero de operacoes...\n\n";

    std::vector<long long> n_values = {1000, 10000, 100000};
    std::vector<FunctionTest> tests = {
        {"(O(n)) = ", f_linear},
        {"(O(n^2)) = ", f_quadratic},
        {"(O(n log n)) = ", f_nlogn}
    };

    for (long long n : n_values) {
        std::cout << "Para n = " << n << ":\n";
        for (const auto& test : tests) {
            long long resultado = test.func(n);
            std::cout << "  - " << test.name << ": " << resultado << " operacoes\n";
        }
        std::cout << "\n";
    }

    return 0;
}
