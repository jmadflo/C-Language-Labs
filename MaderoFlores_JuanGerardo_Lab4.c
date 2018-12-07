#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    if (n % 2 == 0 && n > 2){
        return 0;
    }
    for(int i = 3; i < n/2; i += 2){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(void) {
    FILE *randoms;
    randoms = fopen("random_ints.txt", "w");
    FILE *primes;
    primes = fopen("primes.txt", "w");
    
    printf("Enter number of random ints.\n");
    int n;
    scanf("%d", &n);
    int i = 0;
    
    // Initializes random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    // Generate n random ints
    while(i < n){
        int r = 2 + rand() % 999999;
        if (i == n - 1){
            fprintf(randoms, "%d", r);
        }
        else {
            fprintf(randoms, "%d,", r);
        }
        if (isPrime(r) == 1){
            fprintf(primes, "%d,", r);
        }
        i++;
    }
    
    fclose(randoms);
    fclose(primes);
    
    return 0;
}