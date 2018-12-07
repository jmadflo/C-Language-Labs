#include <stdio.h>

int main(void) {
    printf("Please enter the integer number of lines that you want the pyramid to have.\n");
    int n;
    scanf("%d", &n);
    int i = 0;
    int temp_n = n;
    
    while (i <= n){
        while(temp_n > 1){
            if (temp_n <= i){
                printf("%d " , temp_n);
            } else {
                printf("  ");
            }
            temp_n--;
        }
        while (temp_n < n+1){
            if (temp_n <= i){
                printf("%d ", temp_n);
            } else {
                printf(" ");
            }
            temp_n++;
        }
        i++;
        printf("\n");
    }
    return 0;
}