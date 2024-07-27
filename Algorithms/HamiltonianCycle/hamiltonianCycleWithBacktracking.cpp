// My notebook's link (PT-BR):
// https://www.evernote.com/shard/s704/sh/d2041c0f-dd1e-b205-2071-c14dfe283dbf/aJX0hWPyhvAoFqPCx7UcKwZR_HLDGVyEJnai6wtybStG3cGJCUFmjzWOdg

#include <bits/stdc++.h>

using namespace std;

int numeroDeSetores, limite;

bool verificaAdj(string a, string b) 
{
    if (a.size() != b.size()) return false;

    int contador = 0;
    for (int i = 0; contador <= limite && i < a.size(); i++)
        if (a[i] != b[i]) contador++;

    return contador <= limite;
}

bool verificaCaminho(int verticeAtual, bool ** mat, int * caminho, int pos)
{
    // verificando se o vertice atual não tem adjacência com o vértice anterior ao caminho
    if (mat[caminho[pos - 1]][verticeAtual] == 0) return false;

    // verificando se esse vértice atual já não foi adicionado no caminho
    for (int i = 0; i < pos; i++) if (caminho[i] == verticeAtual) return false;

    return true;
}

bool cicloHamiltoniano(bool ** mat, int * caminho, int pos)
{
    // verificando o caso base
    if (pos == numeroDeSetores) 
    { // é preciso verificar se o último vértice forma um ciclo com o primeiro vértice
        return mat[caminho[pos - 1]][caminho[0]];
    }

    for (int i = 1; i < numeroDeSetores; i++)
    {
        if (verificaCaminho(i, mat, caminho, pos))
        {
            // adiciona possível caminho
            caminho[pos] = i;
            // tentando construir o restante do caminho (Backtracking)
            if (cicloHamiltoniano(mat, caminho, pos + 1)) return true;
            // retira a tentativa de caminho que não deu certo
            caminho[pos] = -1;

        }
    }

    return false;
}

void mostrarCaminho(int * caminho, string * setores)
{
    int i;
    for (i = 0; i < numeroDeSetores; i++) 
    {
        if (i != 0) cout  << " -> ";
        cout << setores[caminho[i]];
    }
    if (numeroDeSetores > 1) cout << " -> " << setores[caminho[0]] << endl;
}

int main()
{   
    cin >> numeroDeSetores >> limite;

    string setores[numeroDeSetores];
    int pos = 0;
    for (int i = 0; i < numeroDeSetores; i++) cin >> setores[pos++];
    
    // construindo a matriz de adjacência
    bool ** matrizDeAdj = (bool **) malloc(numeroDeSetores * sizeof(bool *));
    for (int i = 0; i < numeroDeSetores; i++) matrizDeAdj[i] = (bool *) malloc(numeroDeSetores * sizeof(bool));

    for (int i = 0; i < numeroDeSetores; i++)
    {
        for (int j = i + 1; j < numeroDeSetores; j++)
            matrizDeAdj[i][j] = matrizDeAdj[j][i] = verificaAdj(setores[i], setores[j]);
    }

    // construindo o vetor de caminho para o algoritmo do ciclo hamiltoniano
    int caminho[numeroDeSetores];
    for (int i = 1; i < numeroDeSetores; i++) caminho[i] = -1;
    caminho[0] = 0;

    if (cicloHamiltoniano(matrizDeAdj, caminho, 1)) mostrarCaminho(caminho, setores);
    else puts("impossivel");
    return 0;
}