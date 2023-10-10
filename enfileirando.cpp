#include <iostream>

using namespace std;

typedef struct no {
  int dado;
  struct no *proximo;
} No;

void enfileirar(No **fila, int num) {

  No* aux, *novo = (No*)malloc(sizeof(No));

  if (novo) {
    novo->dado = num;
    novo->proximo = NULL;

    if (*fila == NULL) {
      *fila = novo;
    }

    else {
      aux = *fila;
      while (aux->proximo) {
        aux = aux->proximo;
      }

      aux->proximo = novo;
    }
  }

  else {
    cout << "\nErro ao alocar memoria"<< endl;
  }
}

No *desenfileirar(No **fila) {
  No *remover = NULL;

  if (*fila) {
    remover = *fila;
    *fila = remover->proximo;
  }

  return remover;
}

int main() {
  int N, i, valor;
  char op;

  while (cin >> N && N != 0) {

    No *fila = NULL, *r;

    for (i = 0; i < N; i++) {
      cin.ignore();
      cin >> op;
      if (op == 'E') {
        cin >> valor;
        enfileirar(&fila, valor);
      }

      else if (op == 'D') {
        r = desenfileirar(&fila);
        if (r) {
          free(r);
        }
      }

      No *aux = fila;
      if(!aux)
      {
         cout << "*";
      }

      else while(aux) {
        cout << aux->dado << " ";
        aux = aux->proximo;
      }
        cout << endl;


    }
            cout << endl;

  }


  return 0;
}

