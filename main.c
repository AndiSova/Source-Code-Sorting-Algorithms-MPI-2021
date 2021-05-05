#include <stdio.h>
#include <stdlib.h>


int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void countingSort(int a[], int n, int x)
{
    static int r[9999999];
    int i, k[10] = { 0 };
    for (int i = 0; i <= n; i++) {
        k[(a[i] / x) % 10]++;
    }
    for (int i = 1; i <= 10; i++)
        k[i] += k[i - 1];
    for (int i = n -1; i >= 0; i--) {
        r[k[(a[i] / x) % 10] - 1] = a[i];
        k[(a[i] / x) % 10]--;
    }
    for (int i = 0; i <= n; i++)
        a[i] = r[i];
}

void RadixSort(int a[], int n)
{
    int max = getMax(a, n);
    for (int x = 1; max / x > 0; x *= 10)
        countingSort(a, n, x);
}

void printarray (int n, int a[])
{
    int i;
    for (i=1; i<=n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

void InsertionSort(int n,int a[])
{
    int i, j;
    for (i = 1; i <= n; i++) {
        j = i;
        while (j > 0 && a[j-1] > a[j]) {
            int temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j = j - 1;
        }
    }
}

void Merge(int a[], int p, int m, int r)
{
    int *t = malloc((r-p+1) * sizeof *t);
	int i = p, j = m+1, x = 0;
	while(i <= m && j <= r) {
		if(a[i] <= a[j]) {
			t[x] = a[i];
			x += 1; i += 1;
		}
		else {
			t[x] = a[j];
			x += 1; j += 1;
		}
	}
	while(i <= m) {
		t[x] = a[i];
		x += 1; i += 1;
	}
	while(j <= r) {
		t[x] = a[j];
		x += 1; j += 1;
	}
	for(i = p; i <= r; i += 1) {
		a[i] = t[i - p];
	}
	free(t);
}

void Mergesort(int a[], int p, int r)
{
	if(p < r) {
		int m = (p + r) / 2;
		Mergesort(a, p, m);
		Mergesort(a, m+1, r);
		Merge(a, p, m, r);
	}
}

void Bubblesort(int a[], int n)
{
    int i, j;
    for (i = 0; i <= n-1; i++)
        for (j = 0; j <= n-i-1; j++)
            if (a[j] > a[j+1]) {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}

void Selectionsort(int a[],int n)
{
    int i,s,k,j;
    for (i=0; i<n; i++) {
        s=i;
        for (j=i+1; j<=n; j++)
            if (a[j]<a[s])
                s=j;
        k=a[i];
        a[i]=a[s];
        a[s]=k;
    }
}

void Quicksort(int a[], int p, int r)
{
    if(p < r) {
        int q;
        q = Partition(a, p, r);
        Quicksort(a, p, q-1);
        Quicksort(a, q+1, r);
    }
}

int Partition(int a[], int p, int r)
{
    int x = a[r];
    int i = (p - 1);
    for (int j = p; j <= r- 1; j++) {
        if (a[j] <= x) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}

void swap(int* x, int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void Heapify(int a[], int n, int i)
{
    int x = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[x])
        x = l;
    if (r < n && a[r] > a[x])
        x = r;
    if (x != i) {
        swap(&a[i], &a[x]);
        Heapify(a, n, x);
    }
}

void BuildHeap(int a[],int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);
}

void Heapsort(int a[], int n) {
    BuildHeap(a,n);
    for (int i = n ; i >= 0; i--) {
        swap(&a[0], &a[i]);
        Heapify(a, i, 0);
    }
}

int main()
{
    int i=0;
    int *a =(int*) malloc(sizeof(int)*1000000);
    FILE* file;
    file = fopen("10k negative elements.txt", "r");
    while(fscanf(file, "%d", &a[i]) == 1) {
        i++;
    }
    Bubblesort(a,500000);
    //printarray(i,a);
    return 0;
}
