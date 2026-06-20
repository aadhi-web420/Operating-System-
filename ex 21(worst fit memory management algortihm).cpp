#include <stdio.h>

#define MAX 20

int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, highest = 0;
    static int bf[MAX], ff[MAX];

    printf("\n\tMemory Management Scheme - Worst Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("Enter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++) {
        highest = -1;
        for(j = 1; j <= nb; j++) {
            if(bf[j] != 1) { // if block is not allocated
                temp = b[j] - f[i];
                if(temp >= 0) {
                    if(highest == -1 || b[j] > b[highest]) {
                        highest = j;
                    }
                }
            }
        }
        if(highest != -1) {
            ff[i] = highest;
            frag[i] = b[highest] - f[i];
            bf[highest] = 1;
        } else {
            ff[i] = 0;
            frag[i] = 0;
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n");
    for(i = 1; i <= nf; i++) {
        if(ff[i] != 0)
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i, f[i]);
    }
    return 0;
}
