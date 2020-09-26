#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <windows.h>
#include <ctype.h>

using namespace std;

int sorteiaPedra()
{
    return rand() % 75 + 1;
}

int main()
{

    int cartela[5][5];
    int pedrasSorteadas[75], verifica, contaColuna = 0, contaLinha = 0;
    int i, j, k, resposta = 1, sorteada, contaPedra = 0;
    bool repetido;

    //SORTEADOR DE CARTELA

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {

            verifica = cartela[i][j];

            if (j == 2 && i == 2) {
                cartela[i][j] = 00;
                continue;
            }

            if (j == 0) {
                cartela[i][j] = rand() % 15 + 1;

                for (k = 0; k < i; k++) {
                    if (cartela[i][j] == cartela[k][j]) {
                        cartela[i][j] = rand() % 15 + 1;
                        k = 0;
                    }
                }
            }

            if (j == 1) {
                cartela[i][j] = rand() % 15 + 16;

                for (k = 0; k < i; k++) {
                    if (cartela[i][j] == cartela[k][j]) {
                        cartela[i][j] = rand() % 15 + 16;
                        k = 0;
                    }
                }
            }

            if (j == 2) {
                cartela[i][j] = rand() % 15 + 31;

                for (k = 0; k < i; k++) {
                    if (cartela[i][j] == cartela[k][j]) {
                        cartela[i][j] = rand() % 15 + 31;
                        k = 0;
                    }
                }
            }

            if (j == 3) {
                cartela[i][j] = rand() % 15 + 46;

                for (k = 0; k < i; k++) {
                    if (cartela[i][j] == cartela[k][j]) {
                        cartela[i][j] = rand() % 15 + 46;
                        k = 0;
                    }
                }
            }

            if (j == 4) {
                cartela[i][j] = rand() % 15 + 61;

                for (k = 0; k < i; k++) {
                    if (cartela[i][j] == cartela[k][j]) {
                        cartela[i][j] = rand() % 15 + 61;
                        k = 0;
                    }
                }
            }
        }
    }

    cout << "BEM VINDO AO JOGO DO BINGO!\n ESTA EH SUA CARTELA: \n\n";

    for (i = 0; i < 5; i++) //MOSTRA CARTELA
    {
        cout << endl;

        for (j = 0; j < 5; j++) {

            cout << cartela[i][j] << " | ";
        }
    }

    for (i = 0; i < 75; i++) //SORTEADOR NÚMEROS
    {
        pedrasSorteadas[i] = (rand() % 75) + 1;

        for (j = 0; j < i; j++) {
            if (pedrasSorteadas[j] == pedrasSorteadas[i]) {
                pedrasSorteadas[i] = (rand() % 75) + 1;
                j = 0;
            }
        }
    }

    while (resposta == 1) {
        cout << "\n\nRetirar nova pedra? (1- Sim | 2- Nao)" << endl;
        cin >> resposta;

        if (resposta == 1) { //contabiliza uma nova pedra apenas se chamarmos uma nova pedra
            sorteada = pedrasSorteadas[contaPedra];
            contaPedra++;
            cout << "\n\nPedra da rodada: " << sorteada << endl;
            cout << "Pedras ja sorteadas: ";
            for (i = 0; i < contaPedra; i++) {
                cout << pedrasSorteadas[i] << " | ";
            }

            for (i = 0; i < 5; i++) {

                for (j = 0; j < 5; j++) {

                    if (cartela[i][j] == sorteada) {

                        cartela[i][j] = 0;

                        if ((cartela[i][0] == 0) && (cartela[i][1] == 0) && (cartela[i][2] == 0) && (cartela[i][3] == 0) && (cartela[i][4] == 0)) {
                            cout << "\n\n\n\n\nBINGOOOOOOOOOOOOOOOOOOOO\n\n\n\n LINHA " << i + 1 << endl;
                        }

                        else if ((cartela[0][j] == 0) && (cartela[1][j] == 0) && (cartela[2][j] == 0) && (cartela[3][j] == 0) && (cartela[4][j] == 0))
                            cout << "\n\n\n\n\nBINGOOOOOOOOOOOOOOOOOOOO\n\n\n\n COLUNA " << j + 1 << endl;

                        else
                            cout << endl
                                 << "MARCOU UMA!" << endl;
                        for (i = 0; i < 5; i++) //MOSTRA CARTELA
                        {
                            cout << endl;
                            for (j = 0; j < 5; j++) {
                                cout << cartela[i][j] << " | ";
                            }
                        }
                    }
                }
            }
        }
    }
}
