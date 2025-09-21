#include <iostream>
#include <cmath>

// Função que estima as comparações do Bubble Sort (O(n^2))
// A fórmula para o pior caso é aproximadamente n^2.
// Para uma estimativa mais precisa do número de comparações, a fórmula é (n * (n - 1)) / 2.
long long estimarComparacoesBubbleSort(long long n) {
    if (n < 2) return 0;
    return (n * (n - 1)) / 2;
}

// Função que estima as comparações do Merge Sort (O(n log n))
// A fórmula para o número de comparações é n * log2(n).
long long estimarComparacoesMergeSort(long long n) {
    if (n <= 1) return 0;
    return n * log2(n);
}

int main() {
    long long n;
    std::cout << "Insira o numero de elementos para estimar as comparacoes: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "O numero de elementos deve ser maior que zero." << std::endl;
        return 1;
    }

    std::cout << "\n--- Estimativas para n = " << n << " ---\n";
    
    long long comps_bubble = estimarComparacoesBubbleSort(n);
    std::cout << "Bubble Sort (O(n^2)): " << comps_bubble << " comparacoes\n";

    long long comps_merge = estimarComparacoesMergeSort(n);
    std::cout << "Merge Sort (O(n log n)): " << comps_merge << " comparacoes (aproximadas)\n";

    return 0;
}
// Compilação de 1000 feito em 2.913 segundos
// Compilação de 10000 feito em  4.454 segundos
// Compilação de 1000000 feito em 7.652 segundos
