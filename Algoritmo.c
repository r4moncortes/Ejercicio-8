#include <stdio.h>

// Función recursiva para contar las formas de subir la escalera
int count_ways_recursive(int n) {
    if (n <= 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 4;
    } else {
        return count_ways_recursive(n-1) + count_ways_recursive(n-2) + count_ways_recursive(n-3);
    }
}

// Función de memoización para contar las formas de subir la escalera
int count_ways_memo(int n, int memo[]) {
    if (n <= 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 4;
    } else if (memo[n] != 0) {
        return memo[n];
    } else {
        memo[n] = count_ways_memo(n-1, memo) + count_ways_memo(n-2, memo) + count_ways_memo(n-3, memo);
        return memo[n];
    }
}

// Función principal
int main() {
    int test_cases[] = {4, 5, 6, 10};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_cases; ++i) {
        int n = test_cases[i];
        printf("Escalera de %d peldanos:\n", n);
        printf("Recursividad plana: %d\n", count_ways_recursive(n));
        
        // Inicializar el array de memoización con 0
        int memo[n+1];
        for (int j = 0; j <= n; ++j) {
            memo[j] = 0;
        }
        
        printf("Memoizacion: %d\n\n", count_ways_memo(n, memo));
    }

    return 0;
}

