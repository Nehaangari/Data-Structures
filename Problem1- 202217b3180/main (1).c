#include <stdio.h>

#define MAX 20 // Changed MAX to match array size

// Function prototypes
void create(int b[], int *n);
void insert(int b[], int *n);
void deletion(int b[], int *n);
void search(int b[], int n);
void display(int b[], int n);

int main()
{
    int b[MAX]; // Array to hold list elements
    int n = 0;  // Variable to track number of elements in list
    int ch;
    char g = 'y';

    do
    {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create(b, &n);
            break;
        case 2:
            deletion(b, &n);
            break;
        case 3:
            search(b, n);
            break;
        case 4:
            insert(b, &n);
            break;
        case 5:
            display(b, n);
            break;
        case 6:
            return 0; // Exit the program
        default:
            printf("\nEnter the correct choice!\n");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g); // Added space before %c to consume newline

    } while (g == 'y' || g == 'Y');

    return 0;
}

void create(int b[], int *n)
{
    printf("\nEnter the number of elements: ");
    scanf("%d", n);

    if (*n > MAX || *n < 1)
    {
        printf("\nInvalid number of elements!\n");
        *n = 0; // Reset number of elements
        return;
    }

    printf("\nEnter the elements:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion(int b[], int *n)
{
    if (*n == 0)
    {
        printf("\nThe list is empty!\n");
        return;
    }

    int pos;
    printf("\nEnter the position to delete (1 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("\nInvalid position!\n");
        return;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < *n - 1; i++)
    {
        b[i] = b[i + 1];
    }
    (*n)--;

    printf("\nThe elements after deletion:\n");
    display(b, *n);
}

void search(int b[], int n)
{
    if (n == 0)
    {
        printf("\nThe list is empty!\n");
        return;
    }

    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++)
    {
        if (b[i] == e)
        {
            printf("Element %d found at position %d.\n", e, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element %d not found in the list.\n", e);
    }
}

void insert(int b[], int *n)
{
    if (*n == MAX)
    {
        printf("\nThe list is full!\n");
        return;
    }

    int pos, e;
    printf("\nEnter the position to insert (1 to %d): ", *n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1)
    {
        printf("\nInvalid position!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &e);

    // Shift elements to the right
    for (int i = *n - 1; i >= pos - 1; i--)
    {
        b[i + 1] = b[i];
    }
    b[pos - 1] = e;
    (*n)++;

    printf("\nThe list after insertion:\n");
    display(b, *n);
}

void display(int b[], int n)
{
    if (n == 0)
    {
        printf("\nThe list is empty.\n");
        return;
    }

    printf("\nThe elements in the list are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
