#include <iostream>
#include <vector>
#include <list>
using namespace std;

class GrafoLista {
private:
    int numVertices;
    vector<list<int>> listaAdj;

public:
    // Construtor
    GrafoLista(int vertices) : numVertices(vertices) {
        listaAdj.resize(vertices);
    }
    
    // Adicionar aresta
    void adicionarAresta(int origem, int destino) {
        if (origem >= 0 && origem < numVertices && 
            destino >= 0 && destino < numVertices) {
            listaAdj[origem].push_back(destino);
            // Para grafo não-direcionado:
            // listaAdj[destino].push_back(origem);
        }
    }
    
    // Remover aresta
    void removerAresta(int origem, int destino) {
        if (origem >= 0 && origem < numVertices && 
            destino >= 0 && destino < numVertices) {
            listaAdj[origem].remove(destino);
            // Para grafo não-direcionado:
            // listaAdj[destino].remove(origem);
        }
    }
    
    // Verificar se existe aresta
    bool existeAresta(int origem, int destino) {
        if (origem >= 0 && origem < numVertices && 
            destino >= 0 && destino < numVertices) {
            for (int vizinho : listaAdj[origem]) {
                if (vizinho == destino) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // Obter vizinhos de um vértice
    list<int> obterVizinhos(int vertice) {
        if (vertice >= 0 && vertice < numVertices) {
            return listaAdj[vertice];
        }
        return list<int>();
    }
    
    // Imprimir lista
    void imprimir() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int vizinho : listaAdj[i]) {
                cout << vizinho << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Criar grafo com 4 vértices
    GrafoLista grafo(4);
    
    // Adicionar arestas
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 3);
    
    // Imprimir lista
    cout << "Lista de Adjacência:" << endl;
    grafo.imprimir();
    
    // Verificar arestas
    cout << "\nExiste aresta (0,1)? " 
         << (grafo.existeAresta(0, 1) ? "Sim" : "Não") << endl;
    cout << "Existe aresta (1,3)? " 
         << (grafo.existeAresta(1, 3) ? "Sim" : "Não") << endl;
    
    // Obter vizinhos
    cout << "\nVizinhos do vértice 0: ";
    for (int vizinho : grafo.obterVizinhos(0)) {
        cout << vizinho << " ";
    }
    cout << endl;
    
    return 0;
}
