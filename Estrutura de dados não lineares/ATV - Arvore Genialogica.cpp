#include <iostream>
using namespace std;

struct Raiz {
	string valor;
	Raiz* rigth;
	Raiz* left;
};

void imprimirArvore(Raiz* no, int nivel = 0) {
    if (no == nullptr) return;

    for (int i = 0; i < nivel; i++) {
        cout << "   ";
    }

    cout << "|-- " << no->valor << endl;

    imprimirArvore(no->left, nivel + 1);
    imprimirArvore(no->rigth, nivel + 1);
}

int main(){
	
	string tree[] = {"Rodrigo Junior", "Rodrigo Rodrigues", "Laiz Alves", "Creuza Aparecida", "Terezinha de Fatima", "Joao Pereira", "Lionel Alves"};

	Raiz* galho = new Raiz{"Rodrigo Junior", nullptr, nullptr};
	galho->left = new Raiz{"Rodrigo Rodrigues", nullptr, nullptr};
	galho->rigth = new Raiz{"Laiz Alves", nullptr, nullptr};
	
	galho->left->left = new Raiz{"Terezinha de Fatima", nullptr, nullptr}; 
	galho->left->rigth = new Raiz{"Joao Pereira", nullptr, nullptr};
	
	galho->rigth->left = new Raiz{"Creuza Aparecida", nullptr, nullptr}; 
	galho->rigth->rigth = new Raiz{"Lionel Alves", nullptr, nullptr};
		
	imprimirArvore(galho);
	
	return 0;
}
