#include <iostream>
using namespace std;

// FUNÇÃO INSERTION SORT
int* insertion_sort(int lista[], int tamanho){

    for(int i = 1; i < tamanho; i++){
        int j = i - 1;
        int atual = lista[i];
        while(j >= 0 && lista[j] > atual){
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = atual;
    }
    return lista;
}

// FUNÇÃO PRINCIPAL
int main(){

    // vetor pra teste
    int lista[] = {5, 3, 8, 1, 4};
    int tamanho = 5;

    int* lista_ordenada = insertion_sort(lista, tamanho);

    // imprimindo
    cout << "Lista ordenada: ";
    for (int i = 0; i < tamanho; i++) {
        cout << lista_ordenada[i] << " ";
    }
    cout << endl;

    return 0;
}