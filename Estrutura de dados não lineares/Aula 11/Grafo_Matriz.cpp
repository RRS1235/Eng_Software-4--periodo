#include <iostream>
#include <vector>
using namespace std;

class GrafoMatriz {
private:
    int numVertices;
    vector<vector<int>> matriz;

public:
    // Construtor
    GrafoMatriz(int vertices) : numVertices(vertices) {
        matriz.resize(vertices, vector<int>(vertices, 0));
    }
    
    // Adicionar aresta
    void adicionarAresta(int origem, int destino) {
        if (origem >= 0 && origem < numVertices && 
            destino >= 0 && destino < numVertices) {
            matriz[origem][destino] = 1;
            // Para grafo não-direcionado:
            // matriz[destino][origem] = 1;
        }
    }
    
    // Remover aresta
    void removerAresta(int origem, int destino) {
        if (origem >= 0 && origem < numVertices && 
            destino >= 0 && destino < numVertices) {
            matriz[origem][destino] = 0;
            // Para grafo não-direcionado:
            // matriz[destino][origem] = 0;
        }
    }
    
    // Verificar se existe aresta
    bool existeAresta(int origem, int destino) {
        if (origem >= 0 && origem < numVertices && 
            destino >= 0 && destino < numVertices) {
            return matriz[origem][destino] == 1;
        }
        return false;
    }
    
    // Imprimir matriz
    void imprimir() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Criar grafo com 4 vértices
    GrafoMatriz grafo(4);
    
    // Adicionar arestas
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 3);
    
    // Imprimir matriz
    cout << "Matriz de Adjacência:" << endl;
    grafo.imprimir();
    
    // Verificar arestas
    cout << "\nExiste aresta (0,1)? " 
         << (grafo.existeAresta(0, 1) ? "Sim" : "Não") << endl;
    cout << "Existe aresta (1,3)? " 
         << (grafo.existeAresta(1, 3) ? "Sim" : "Não") << endl;
    
    return 0;
}
