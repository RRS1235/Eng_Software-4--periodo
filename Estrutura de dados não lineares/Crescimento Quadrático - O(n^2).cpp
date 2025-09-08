#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int exemplo(int n) {
	
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
	
	
	
	int result = exemplo(num);
	
	cout << "Resultado ao quadrado: " << result << endl;
	
	return 0;
}
