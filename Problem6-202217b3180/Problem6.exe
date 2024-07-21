#include<stdio.h> 
#include<stdlib.h> // for exit()

void main() 
{
    int n, *a, *b, *t, *w, *g;
    float att = 0, awt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory dynamically based on the number of processes
    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));
    t = (int *)malloc(n * sizeof(int));
    w = (int *)malloc(n * sizeof(int));
    g = (int *)malloc((n + 1) * sizeof(int));

    printf("Enter the burst times for each process:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", &b[i]);

    printf("Enter the arrival times for each process:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", &a[i]);

    g[0] = 0;
    for(int i = 0; i < n; i++) 
        g[i + 1] = g[i] + b[i];

    for(int i = 0; i < n; i++) 
    { 
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt += w[i];
        att += t[i];
    } 

    awt /= n;
    att /= n;

    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n"); 
    for(int i = 0; i < n; i++) 
    { 
        printf("\tP%d\t\t%d\t\t%d\n", i, w[i], t[i]); 
    } 
    printf("Average Waiting Time: %f\n", awt); 
    printf("Average Turnaround Time: %f\n", att); 

    // Free allocated memory
    free(a);
    free(b);
    free(t);
    free(w);
    free(g);

    // Pause before closing
    printf("\nPress any key to exit...\n");
    getch(); // Specific to certain compilers
}