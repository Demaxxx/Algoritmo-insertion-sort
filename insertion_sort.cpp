#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//==================================================================
// STRUCT PARA TESTE DE ESTABILIDADE
struct Item {
    int valor; // para ordenar
    char id; // para rastrear a posição original
};

//==================================================================
// FUNÇÃO INSERTION SORT
void insertion_sort(int lista[], int tamanho, int& cont){

    for(int i = 1; i < tamanho; i++){
        cont++; // conta iteração do for
        int j = i - 1;
        int atual = lista[i];
        while(j >= 0 && lista[j] > atual){
            cont++; // Conta a comparação do while
            lista[j + 1] = lista[j];
            cont++; // Conta a movimentação
            j = j - 1;
        }
        cont++; // Conta a última comparação do while
        lista[j + 1] = atual;
        cont++; // Conta a inserção do valor 'atual' na posição correta
    }
}

//==================================================================
// FUNÇÃO INSERTION SORT PARA TESTE DE ESTABILIDADE
void insertion_sort_estabilidade(Item lista[], int tamanho) {

    for(int i = 1; i < tamanho; i++) {
        Item atual = lista[i];
        int j = i - 1;

        // Usa > em vez de >=
        // Isso garante estabilidade, pois elementos iguais
        // não são movidos entre si.
        while(j >= 0 && lista[j].valor > atual.valor) {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = atual;
    }
}

//==================================================================
// FUNÇÕES PARA GERAR VETORES ALEATÓRIOS
void gerarOrdenado(int lista[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        lista[i] = i + 1;
    }
}

void gerarAleatorio(int lista[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        lista[i] = rand() % 10000;
    }
}

void gerarDecrescente(int lista[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        lista[i] = tamanho - i;
    }
}

//==================================================================
// FUNÇÃO PRINCIPAL
int main(){
    //==================================================================
    // TESTE COM DIFERENTES TAMANHOS

    srand(time(0));

    int tamanhos[] = {100, 500, 1000};
    int qtdTamanhos = 3;

    for(int k = 0; k < qtdTamanhos; k++) {

        int tamanho = tamanhos[k];

        // Vetores (um tamanho máximo pra todos os testes)
        int listaOrd[1000];
        int listaAle[1000];
        int listaDec[1000];

        // Gerando os 3 casos
        gerarOrdenado(listaOrd, tamanho);
        gerarAleatorio(listaAle, tamanho);
        gerarDecrescente(listaDec, tamanho);

        // Contadores
        int contadorOrd = 0;
        int contadorAle = 0;
        int contadorDec = 0;

        // Executando insertion sort
        insertion_sort(listaOrd, tamanho, contadorOrd);
        insertion_sort(listaAle, tamanho, contadorAle);
        insertion_sort(listaDec, tamanho, contadorDec);

        // Exibindo resultados
        cout << "\n==============================" << endl;
        cout << "Tamanho do vetor: " << tamanho << endl;
        cout << "Melhor caso: " << contadorOrd << endl;
        cout << "Caso medio: " << contadorAle << endl;
        cout << "Pior caso: " << contadorDec << endl;
    }

    //==================================================================
    // TESTE DE ESTABILIDADE

    Item teste[] = {
        {5, 'A'},
        {3, 'B'},
        {5, 'C'},
        {2, 'D'}
    };

    int tamanhoTeste = 4;

    cout << "\n==============================" << endl;
    cout << "TESTE DE ESTABILIDADE" << endl;

    cout << "\nAntes da ordenacao:\n";
    for(int i = 0; i < tamanhoTeste; i++) {
        cout << "(" << teste[i].valor << "," << teste[i].id << ") ";
    }
    cout << endl;

    insertion_sort_estabilidade(teste, tamanhoTeste);

    cout << "\nDepois da ordenacao:\n";
    for(int i = 0; i < tamanhoTeste; i++) {
        cout << "(" << teste[i].valor << "," << teste[i].id << ") ";
    }
    cout << endl << endl;

    return 0;
}