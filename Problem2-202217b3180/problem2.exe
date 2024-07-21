/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> // for malloc and free
#define MAX_TERMS 10

struct poly {
    int coeff;  // coefficient of the term
    int expo;   // exponent of the term
};

int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    struct poly *p1, *p2, *p3;
    int t1, t2, t3;

    // Allocate memory for p1, p2, and p3
    p1 = (struct poly *)malloc(MAX_TERMS * sizeof(struct poly));
    p2 = (struct poly *)malloc(MAX_TERMS * sizeof(struct poly));
    p3 = (struct poly *)malloc(MAX_TERMS * sizeof(struct poly));

    if (p1 == NULL || p2 == NULL || p3 == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1); // or return an error code, handle gracefully
    }

    // read and display first polynomial
    t1 = readPoly(p1);
    printf("\nFirst polynomial : ");
    displayPoly(p1, t1);

    // read and display second polynomial
    t2 = readPoly(p2);
    printf("\nSecond polynomial : ");
    displayPoly(p2, t2);

    // add two polynomials and display resultant polynomial
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition : ");
    displayPoly(p3, t3);

    // Free dynamically allocated memory
    free(p1);
    free(p2);
    free(p3);

    printf("\n");
    return 0;
}

int readPoly(struct poly p[]) {
    int t1, i;

    printf("\nEnter the total number of terms in the polynomial:");
    scanf("%d", &t1);

    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < t1; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);

        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }

    return t1;
}

int addPoly(struct poly p1[], struct poly p2[], int t1, int t2, struct poly p3[]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
        }
        k++;
    }

    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k; // Return the number of terms in the resultant polynomial p3
}

void displayPoly(struct poly p[], int term) {
    int k;

    for (k = 0; k < term - 1; k++) {
        printf("%dx^%d + ", p[k].coeff, p[k].expo);
    }
    printf("%dx^%d\n", p[term - 1].coeff, p[term - 1].expo);
}
