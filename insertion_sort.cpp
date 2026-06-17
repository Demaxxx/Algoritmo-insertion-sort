#include <iostream>
using namespace std;

// FUNÇÃO INSERTION SORT
int* insertion_sort(int lista[], int tamanho, int& cont){

    //int cont = 0;

    for(int i = 1; i < tamanho; i++){
        int j = i - 1;
        int atual = lista[i];
        while(j >= 0 && lista[j] > atual){
            cont++;
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = atual;
    }
    return lista;
}

// FUNÇÃO PRINCIPAL
int main(){

    // teste melhor caso (vetor ordenado)
    int listaOrd[] = {1, 2, 3, 4, 5};
    int tamanhoOrd = 5;
    int contadorOrd = 0;
    int* lista_ordenada = insertion_sort(listaOrd, tamanhoOrd, contadorOrd);

    // imprimindo
    cout << "Lista ordenada: ";
    for (int i = 0; i < tamanhoOrd; i++) {
        cout << lista_ordenada[i] << " ";
    }
    cout << endl;
    cout << "Total de instrucoes: " << contadorOrd << endl;

    //===================================================================

    // teste médio caso (vetor aleatorio)
    int listaAle[] = {2, 1, 3, 5, 4};
    int tamanhoAle = 5;
    int contadorAle = 0;
    int* lista_Aleatoria = insertion_sort(listaAle, tamanhoAle, contadorAle);

    // imprimindo
    cout << "Lista ordenada: ";
    for (int i = 0; i < tamanhoAle; i++) {
        cout << lista_Aleatoria[i] << " ";
    }
    cout << endl;
    cout << "Total de instrucoes: " << contadorAle << endl;

    //===================================================================

    // teste pior caso (vetor decrescente)
    int listaDec[] = {5, 4, 3, 2, 1};
    int tamanhoDec = 5;
    int contadorDec = 0;
    int* lista_Decrescente = insertion_sort(listaDec, tamanhoDec, contadorDec);

    // imprimindo
    cout << "Lista ordenada: ";
    for (int i = 0; i < tamanhoDec; i++) {
        cout << lista_Decrescente[i] << " ";
    }
    cout << endl;
    cout << "Total de instrucoes: " << contadorDec << endl;

    return 0;
}