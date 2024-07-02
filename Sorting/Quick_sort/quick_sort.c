#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// Utility functions
void swap(int Ls[], int i, int j)
{
    int temp = Ls[i];
    Ls[i] = Ls[j];
    Ls[j] = temp;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

// Partition function using the hoare partitioning scheme
// Ls[lo..hi] is the input array; Ls[pInd] is the pivot
int partition(int Ls[], int lo, int hi, int pInd)
{
    swap(Ls, pInd, hi);
    int pivPos, lt, rt, pv;
    lt = lo;
    rt = hi - 1;
    pv = Ls[hi];
    while (lt < rt)
    {
        for (; lt < hi && Ls[lt] <= pv; lt++);
        // Ls[j]<=pv  for j in lo..lt-1
        for (; Ls[rt] > pv; rt--);
        // Ls[j]>pv  for j in rt+1..hi
        if (lt < rt)
        {
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if (Ls[rt] > pv && rt >= lo)
        pivPos = rt;
    else
        pivPos = rt + 1;
    swap(Ls, hi, pivPos);
    // Postcond.: (Ls[j]<=pv for j in lo..pivPos-1) and 
    // (Ls[j]>pv for j in pivPos+1..hi)
    return pivPos;
}


void quicksort(int Ls[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = hi;
        p = partition(Ls, lo, hi, p);
        /*
        (Ls[j]<=Ls[p] for j in lo..pPos-1) and
        (Ls[j]>Ls[p] for j in pPos+1..hi)
        */
        quicksort(Ls, lo, p - 1);
        quicksort(Ls, p + 1, hi);
    }
}

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    int n;
    fscanf(fp, "%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);        
    }
    fclose(fp);
        
    struct timeval start, end;    
    gettimeofday(&start, NULL);
    quicksort(arr, 0, n - 1);
    gettimeofday(&end, NULL);
    printf("Time taken for Sorting: %f seconds\n", 
    (end.tv_sec - start.tv_sec) * 1000000 + 
    (end.tv_usec - start.tv_usec) / 1000000.0);

    fp = fopen("sorted_numbers.txt", "w");
    for (int j = 0; j < n; j++)
    {
        fprintf(fp, "%d\n", arr[j]);
    }
    fclose(fp);

    printf("Success\n");
    return 0;
}