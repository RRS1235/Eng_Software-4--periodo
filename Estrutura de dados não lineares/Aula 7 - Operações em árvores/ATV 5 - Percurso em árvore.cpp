#include <iostream>

using namespace std;

// atv7
// Estrutura para representar um nó da árvore
struct No {
    int chave;
    No* esquerda;
    No* direita;

    // Construtor para criar um novo nó
    No(int valor) : chave(valor), esquerda(nullptr), direita(nullptr) {}
};

// Função para inserir um novo nó na árvore de busca binária
No* inserirNo(No* raiz, int chave) {
    // Se a raiz for nula, cria e retorna um novo nó
    if (raiz == nullptr) {
        return new No(chave);
    }

    // Se a chave for menor que a chave da raiz, insere na subárvore esquerda
    if (chave < raiz->chave) {
        raiz->esquerda = inserirNo(raiz->esquerda, chave);
    } 
    // Se a chave for maior que a chave da raiz, insere na subárvore direita
    else if (chave > raiz->chave) {
        raiz->direita = inserirNo(raiz->direita, chave);
    }

    // Retorna o ponteiro (inalterado) da raiz
    return raiz;
}

// Percurso em ordem: esquerda -> raiz -> direita
void percursoEmOrdem(No* raiz) {
    if (raiz != nullptr) {
        percursoEmOrdem(raiz->esquerda);
        cout << raiz->chave << " ";
        percursoEmOrdem(raiz->direita);
    }
}

// Percurso em pré-ordem: raiz -> esquerda -> direita
void percursoEmPreOrdem(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->chave << " ";
        percursoEmPreOrdem(raiz->esquerda);
        percursoEmPreOrdem(raiz->direita);
    }
}

// Percurso em pós-ordem: esquerda -> direita -> raiz
void percursoEmPosOrdem(No* raiz) {
    if (raiz != nullptr) {
        percursoEmPosOrdem(raiz->esquerda);
        percursoEmPosOrdem(raiz->direita);
        cout << raiz->chave << " ";
    }
}

int main() {
    No* raiz = nullptr;
    raiz = inserirNo(raiz, 10);
    raiz = inserirNo(raiz, 5);
    raiz = inserirNo(raiz, 15);
    raiz = inserirNo(raiz, 2);
    raiz = inserirNo(raiz, 7);
    raiz = inserirNo(raiz, 20);
    
    cout << "Percurso em Ordem (In-Order):" << endl;
    percursoEmOrdem(raiz);
    cout << endl << "-----------------------------------" << endl;
    
    cout << "Percurso em Pre-Ordem (Pre-Order):" << endl;
    percursoEmPreOrdem(raiz);
    cout << endl << "-----------------------------------" << endl;
    
    cout << "Percurso em Pos-Ordem (Post-Order):" << endl;
    percursoEmPosOrdem(raiz);
    cout << endl << "-----------------------------------" << endl;

    return 0;
}
