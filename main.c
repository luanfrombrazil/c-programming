#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arremesso() {
    int buraco, velocidade;
    while (1) {
        scanf("%d %d", &buraco, &velocidade);
        if (buraco == 0)
            return 0;
        int encontrado = 0;

        for (int i = velocidade; i > 0; i--) {
            int path = 0;
            encontrado = 0;
            for (int j = i; j > 0; j--) {
                for (int k = j; k > 0; k--) {
                    path += j;
                    if (path == buraco) {
                        encontrado = 1;
                        break;
                    }
                    if (path > buraco && encontrado ==0) {
                        break;
                    }
                }
                if (encontrado) break;
            }
            if (encontrado) break;
        }
        if (encontrado) {
            printf("possivel\n");
        }else{
            printf("impossivel\n");
        }
    }
}

// Função para comparar dois arquivos linha a linha ignorando linhas vazias
int compara_arquivos(const char* arq1, const char* arq2) {
    FILE *f1 = fopen(arq1, "r");
    FILE *f2 = fopen(arq2, "r");
    if (!f1 || !f2) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return 0;
    }
    char linha1[256], linha2[256];
    int iguais = 1;
    char *p1, *p2;
    while (1) {
        // Lê próxima linha não vazia de f1
        do {
            p1 = fgets(linha1, sizeof(linha1), f1);
        } while (p1 && (linha1[0] == '\n' || linha1[0] == '\r' || linha1[0] == '\0'));
        // Lê próxima linha não vazia de f2
        do {
            p2 = fgets(linha2, sizeof(linha2), f2);
        } while (p2 && (linha2[0] == '\n' || linha2[0] == '\r' || linha2[0] == '\0'));
        if (!p1 && !p2) break; // ambos terminaram
        if (!p1 || !p2 || strcmp(linha1, linha2) != 0) {
            iguais = 0;
            break;
        }
    }
    fclose(f1);
    fclose(f2);
    return iguais;
}

int main() {
    char* tests[] = {"arremesso/1", "arremesso/2", "arremesso/3"};
    int ntests = 3;
    for (int i = 0; i < ntests; i++) {
        char in[64], out[64], myout[64];
        snprintf(in, sizeof(in), "%s.in", tests[i]);
        snprintf(out, sizeof(out), "%s.out", tests[i]);
        snprintf(myout, sizeof(myout), "%s.myout", tests[i]);

        FILE* fin = fopen(in, "r");
        if (!fin) {
            printf("[ERRO] Não foi possível abrir %s\n", in);
            continue;
        }
        FILE* fout = freopen(myout, "w", stdout);
        if (!fout) {
            printf("[ERRO] Não foi possível redirecionar saída para %s\n", myout);
            fclose(fin);
            continue;
        }
        // Redireciona stdin
        freopen(in, "r", stdin);
        arremesso();
        fflush(stdout);
        fclose(fout);
        // Restaura stdout
        freopen("CON", "w", stdout);
        // Compara saída
        if (compara_arquivos(out, myout)) {
            printf("[OK] %s\n", tests[i]);
        } else {
            printf("[ERRO] %s\n", tests[i]);
        }
    }
    return 0;
}
