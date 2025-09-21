#include <iostream>

using namespace std;

// Estrutura para representar um nó na arvore binaria de busca
struct No {
    int chave;
    No* esquerda;
    No* direita;

    // Construtor para inicializar um novo nó
    No(int valor) : chave(valor), esquerda(nullptr), direita(nullptr) {}
};

// Funcao para inserir um novo nó na arvore
No* inserirNo(No* raiz, int chave) {
    // Se a arvore estiver vazia, retorna um novo nó
    if (raiz == nullptr) {
        return new No(chave);
    }

    // Caso contrario, percorre a arvore
    if (chave < raiz->chave) {
        // Se a chave for menor, insere na subarvore da esquerda
        raiz->esquerda = inserirNo(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        // Se a chave for maior, insere na subarvore da direita
        raiz->direita = inserirNo(raiz->direita, chave);
    }
    // Retorna o ponteiro (inalterado) do nó
    return raiz;
}

// Funcao auxiliar para encontrar o nó com o menor valor (o sucessor inorder)
No* encontrarNoComValorMinimo(No* no) {
    No* atual = no;
    // Percorre a subarvore da esquerda para encontrar o menor valor
    while (atual && atual->esquerda != nullptr) {
        atual = atual->esquerda;
    }
    return atual;
}

// Funcao para remover um nó da arvore
No* removerNo(No* raiz, int chave) {
    // Caso base: se a arvore estiver vazia
    if (raiz == nullptr) {
        return raiz;
    }

    // Se a chave for menor que a raiz, busca na subarvore da esquerda
    if (chave < raiz->chave) {
        raiz->esquerda = removerNo(raiz->esquerda, chave);
    }
    // Se a chave for maior que a raiz, busca na subarvore da direita
    else if (chave > raiz->chave) {
        raiz->direita = removerNo(raiz->direita, chave);
    }
    // Se a chave for igual a raiz, entao este é o nó a ser removido
    else {
        // Caso 1: Nó com apenas um filho ou nenhum filho
        if (raiz->esquerda == nullptr) {
            No* temp = raiz->direita;
            delete raiz; // Libera a memória do nó
            return temp;
        } else if (raiz->direita == nullptr) {
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }

        // Caso 2: Nó com dois filhos
        // Encontra o sucessor (menor nó na subarvore da direita)
        No* temp = encontrarNoComValorMinimo(raiz->direita);

        // Copia o valor do sucessor para este nó
        raiz->chave = temp->chave;

        // Remove o sucessor (que agora é um nó com 0 ou 1 filho)
        raiz->direita = removerNo(raiz->direita, temp->chave);
    }
    return raiz;
}

// Funcao para percorrer a arvore em ordem (inorder traversal)
void percorrerEmOrdem(No* raiz) {
    if (raiz != nullptr) {
        percorrerEmOrdem(raiz->esquerda);
        cout << raiz->chave << " ";
        percorrerEmOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = nullptr;

    // Construção inicial da arvore
    raiz = inserirNo(raiz, 10);
    raiz = inserirNo(raiz, 5);
    raiz = inserirNo(raiz, 15);
    raiz = inserirNo(raiz, 2);
    raiz = inserirNo(raiz, 7);
    raiz = inserirNo(raiz, 20);

    // Exibição da arvore original
    cout << "Arvore original (percurso em ordem): ";
    percorrerEmOrdem(raiz);
    cout << endl;

    // Teste de inserção
    cout << "\nInserindo o valor 12..." << endl;
    raiz = inserirNo(raiz, 12);
    cout << "Arvore apos a insercao de 12 (percurso em ordem): ";
    percorrerEmOrdem(raiz);
    cout << endl;

    // Teste de exclusão
    cout << "\nRemovendo o no com valor 15..." << endl;
    raiz = removerNo(raiz, 15);
    cout << "Arvore apos a remocao de 15 (percurso em ordem): ";
    percorrerEmOrdem(raiz);
    cout << endl;

    return 0;
}
