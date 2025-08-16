#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Filme{
	
	private:
		
	string titulo;
	string diretor;
	int duracao;
	
	public:
		filme(string x, string y, int z){
			
			titulo = x;
			diretor = y;
			duracao = z;
			
		}
		void apresentar(){
			cout << "O filme " << titulo << " foi feito por " << diretor << ", tendo a duracao de " << duracao << " min innutos" << endl;
		}
	
	public:
		
		EditarT(){
			
			int tempo;	
			int z = tempo;
			
		}
			
};

int main(int argc, char** argv) { 
		
		Filme filme;
		
		filme.apresentar(); 
	
	return 0;
}
