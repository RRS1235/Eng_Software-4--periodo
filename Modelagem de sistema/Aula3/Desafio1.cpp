#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Livro{
	
	private:
		
	string titulo;
	string autor;
	float preco;
	
	public:
		
		Livro(string x, string y, float z){
			
			titulo = x;
			autor = y;
			preco = z;
			
		}
		void apresentar(){
			cout << "O livro "<< titulo << " Foi escrito por " << autor << " e esta a venda por " << "R$" << preco << endl;
		}
		
};

int main(int argc, char** argv) {
	
	Livro p1("Carros muinto rapidos", "DaviS Silva", 9.99);
	
	p1.apresentar();
	
	return 0;
}
