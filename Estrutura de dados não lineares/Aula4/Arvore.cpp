#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Raiz {
	string valor;
	Raiz* rigth;
	Raiz* left;
};

void imprimirArvore(Raiz* no) {
    if (no == nullptr) return;

    cout << no->valor << endl;            // Visita o nó atual
    imprimirArvore(no->left);             // Visita o filho à esquerda
    imprimirArvore(no->rigth);            // Visita o filho à direita
}

int main(){
	
	string tree[] = {"!", "&", "?", "emManutecao", "%", "MartinsLuc", "seguenoinstagram"};

	Raiz* galho = new Raiz{"!", nullptr, nullptr};
	galho->left = new Raiz{"&", nullptr, nullptr};
	galho->rigth = new Raiz{"?", nullptr, nullptr};
	
	galho->left->left = new Raiz{"emManutencao", nullptr, nullptr}; 
	galho->left->rigth = new Raiz{"%", nullptr, nullptr};
	
	galho->rigth->left = new Raiz{"MartinsLuc", nullptr, nullptr}; 
	galho->rigth->rigth = new Raiz{"seguenoinstagram", nullptr, nullptr};
		
	imprimirArvore(galho);
	
	return 0;
}
