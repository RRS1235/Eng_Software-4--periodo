#include <iostream>
using namespace std;

int quadratico(int n) {
	
    int cont = 0;
    
    for (int i = 0; i < n; i++) { // Loop externo
    
        for (int j = 0; j < n; j++) { // Loop interno
            cont++;
        }
    }
    return cont;
}

int main(int argc, char** argv) {
	
	//int num;
	
	cout << "Escolha um numero: ";
	
	int num; cin >> num;
	
	int result = quadratico(num);
	
	cout << "Resultado ao quadrado: " << result << endl;
	
	return 0;
}
