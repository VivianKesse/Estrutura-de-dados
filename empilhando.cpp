#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N, i, valor;
    char operacao;
    while (cin >> N && N != 0) {
        stack<int> pilha;
        for (i = 0; i < N; i++) {
            cin >> operacao;

            if (operacao == 'E')
            {
                cin >> valor;
                pilha.push(valor);
            }

            else if (operacao == 'D')
            {
                if (!pilha.empty())
                {
                    pilha.pop();
                }
            }

            if (pilha.empty())
            {
                cout << "*";
            }

            else
            {
                stack<int> aux = pilha;
                string resultado;
                while (!aux.empty()) {
                    resultado += to_string(aux.top()) + " ";
                    aux.pop();
                }
                resultado.pop_back();
                cout << resultado;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}


