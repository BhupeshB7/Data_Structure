#include <stdio.h>
#include <stdlib.h>
// Define a structure for items
typedef struct
{
    int weight; 
    int value;
    double ratio;
} Item;

// Function prototypes
void merge_sort(Item items[], int left, int right);
void merge(Item items[], int left, int mid, int right);
double knapsack(Item items[], int n, int capacity);

// Main function
int main()
{
    int n, capacity;

    // User inputs
    scanf("%d", &n);

    Item items[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    scanf("%d", &capacity);

    // Calculate the maximum value
    double max_value = knapsack(items, n, capacity);
    printf("%.2f\n", max_value);

    return 0;
}

// Function to merge two halves
void merge(Item items[], int left, int mid, int right)
{
    // TODO: Implement merge function
        int n1 = mid - left + 1;
    int n2 = right - mid;

    Item L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = items[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = items[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i].ratio >= R[j].ratio)
        {
            items[k] = L[i];
            i++;
        }
        else
        {
            items[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        items[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        items[k] = R[j];
        j++;
        k++;
    }

}

// Function to implement merge sort
void merge_sort(Item items[], int left, int right)
{
    // TODO: Implement merge sort function
     if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(items, left, mid);
        merge_sort(items, mid + 1, right);
        merge(items, left, mid, right);
    }
}

// Function to calculate the maximum value in the knapsack
double knapsack(Item items[], int n, int capacity)
{
    // TODO: Implement fractional knapsack function
    merge_sort(items, 0, n - 1);

    double total_value = 0.0;
    int current_weight = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_weight + items[i].weight <= capacity)
        {
            current_weight += items[i].weight;
            total_value += items[i].value;
        }
        else
        {
            int remaining_capacity = capacity - current_weight;
            total_value += items[i].value * ((double)remaining_capacity / items[i].weight);
            break;
        }
    }

    return total_value;
}
