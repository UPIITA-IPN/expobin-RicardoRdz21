#include <stdio.h>
#include <stdlib.h>

unsigned long long potencia_modular(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(int argc, char *argv[]) {
    // Si no se pasan los 3 argumentos (M, e, n), termina
    if (argc < 4) {
        printf("Uso: %s <M> <e> <n>\n", argv[0]);
        return 1;
    }

    // Convertimos los argumentos de texto a números
    unsigned long long M = strtoull(argv[1], NULL, 10);
    unsigned long long e = strtoull(argv[2], NULL, 10);
    unsigned long long n = strtoull(argv[3], NULL, 10);

    unsigned long long C = potencia_modular(M, e, n);
    
    // Imprimimos solo el resultado para que el test lo lea fácil
    printf("%llu\n", C);

    return 0;
}