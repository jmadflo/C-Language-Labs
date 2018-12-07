#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int n;
    printf("Enter n >= 0: ");
    scanf("%d", &n);
    int ** a = (int **) malloc(sizeof(int*)*n);
    // create each row
    unsigned int i, count;
    for(i = 0; i <= n; i++){
        a[i] = (int*) malloc(sizeof(int)*(i+1));
        if (i == 0){
            a[0][0] = 1;
            printf("%d\n", a[0][0]);
        }
        else if (i == 1){
            a[1][0] = 1;
            a[1][1] = 1;
            printf("%d %d\n", a[1][0], a[1][1]);
        }
        else if (i > 1){
            for(int j = 0; j <= i; j++){
                if (j == 0){
                    a[i][0] = 1;
                    printf("%d ", a[i][0]);
                }
                else if (j == i){
                    a[i][j] = 1;
                    printf("%d\n", a[i][j]);
                }
                else {
                    a[i][j] = a[i-1][j-1] + a[i-1][j];
                    printf("%d ", a[i][j]);
                }
            }
        }
    }
    return 0;
}