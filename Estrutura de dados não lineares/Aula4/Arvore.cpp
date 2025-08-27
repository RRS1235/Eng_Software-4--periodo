#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Raiz {
	string valor;
	Raiz* rigth;
	Raiz* left;
};

int main(){
	
	string tree[] = {"!", "&", "?", "emManutecao", "%", "MartinsLuc", "seguenoinstagram"};

	Raiz* galho = new Raiz{"!", nullptr, nullptr};
	galho->left = new Raiz{"&", nullptr, nullptr};
	galho->rigth = new Raiz{"?", nullptr, nullptr};
	
	galho->left->left = new Raiz{"emManutencao", nullptr, nullptr}; 
	galho->left->rigth = new Raiz{"%", nullptr, nullptr};
	
	galho->rigth->left = new Raiz{"MartinsLuc", nullptr, nullptr}; 
	galho->rigth->rigth = new Raiz{"seguenoinstagram", nullptr, nullptr};
		
	cout << galho->valor << endl;
	
	return 0;
}
