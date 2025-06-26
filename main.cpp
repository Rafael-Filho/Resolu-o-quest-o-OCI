#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {-1, 1, 0, 0}; // direções: cima, baixo, esquerda, direita
const int dy[] = {0, 0, -1, 1};

int prioridade (char minerio){ // cálculo do desempate
    switch (minerio){
        case 'c':return 0;
        case 'f':return 1;
        case 'o':return 2;
        case 'e':return 3;
        case 'd':return 4;
    }
}

int dfs(int i, int j, vector<vector<char>>& mat,  char minerio, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] != minerio) return 0;
    mat[i][j] = '*'; // marca que já foi explorado 
    int tam = 1;
    for (int k = 0; k < 4; ++k) {
        tam += dfs(i + dx[k], j + dy[k], mat, minerio, m, n);
    }
    return tam;
}

int main() {
    int m, n;
    while (cin >> m >> n, m != 0) {
        vector<vector<char>> mat(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }
        char minerio_max = 'c';
        int tamanho_max = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] != '*') {
                    char minerio = mat[i][j];
                    int tamanho = dfs(i, j, mat, minerio, m, n);
                    if (tamanho > tamanho_max || (tamanho == tamanho_max && prioridade(minerio_max) < prioridade(minerio))) {
                        tamanho_max = tamanho;
                        minerio_max = minerio;
                    }
                }
            }
        }

        if (tamanho_max == 0) cout << "nenhum" << endl;
        else cout << minerio_max << " " << tamanho_max << endl;
    }
    return 0;
}
