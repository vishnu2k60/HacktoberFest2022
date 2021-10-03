#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int *randomNumberGen(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand()%100;
    }
    return arr;
}
void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void heapify(int *arr, int n, int i)
{
    int max = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
  
    if (leftChild < n && arr[leftChild] > arr[max])
        max = leftChild;
  
    if (rightChild < n && arr[rightChild] > arr[max])
        max = rightChild;
  
    if (max != i) 
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

void heapSort(int *arr, int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);  
        heapify(arr, i, 0);
    }
}
void sortDescending(int *arr,int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    } 
}

void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}

int largest(int *arr, int n) 
{ 
    int i; 
    int max = arr[0]; 
  
    for (i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
  
    printf("Maximum element is: %d\n",max); 
}

void delete(int *arr,int n) 
{ 
    int last = arr[n - 1]; 
  
    arr[0] = last;   
    heapSort(arr,n); 
}
void insert(int *arr,int n,int key) 
{ 
    arr[n-1] = key;
  
    heapSort(arr, n); 
} 
void replace(int *arr,int n)
{
    int k,in;
    printf("Enter Element and Index of Replacement:\n");
    scanf("%d%d",&k,&in);
    arr[in]=k;
    heapSort(arr,n);
}
int main()
{
    int choice,n;
    do
    {
        printf("0. Exit\n1. Insert Random Elements\n2. Display the Array\n3. Sort the Array in Ascending Order by using Max-Heap Sort Algorithm\n4. Sort the Array in Descending Order by using any sorting algorithm\n5. Time Complexity to sort ascending of random data\n6. Time Complexity to sort ascending of data already sorted in ascending order\n7. Time Complexity to sort ascending of data already sorted in descending order\n8. Time Complexity to sort ascending of data for all Cases.\n9. Maximum Element\n10. Replace value at a node with new value. \n11. Insert a new element.\n12. Delete an element\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:printf("Exiting !!!\n");
            exit(1);
            case 1: 
            
            printf("Enter N:");
            scanf("%d", &n);
            int *arr;
            arr = randomNumberGen(n);
            break;
            case 2:
            printArray(arr,n);
            break;
            case 3:
            heapSort(arr, n);
            break;
            case 4:
            sortDescending(arr,n);
            break;
            case 5:
            
            printf("\n");
            int *arr1;
            arr1=randomNumberGen(10000);
            clock_t start,end;
            double total=0.0; 
            start=clock();
            heapSort(arr1, 10000);
            end=clock();
            total+=(double)(end-start)/CLOCKS_PER_SEC;
            printf("\nTime elpased is %f seconds\n", total);
            
            printf("Time Complexity=O(nlog n)\n\n");
            break;
            case 6:

            printf("\n");
            clock_t start1,end1;
            double total1=0.0; 
            start1=clock();
            heapSort(arr1, 10000);
            end1=clock();
            total1+=(double)(end1-start1)/CLOCKS_PER_SEC;
            printf("\nTime elpased is %f seconds\n", total1);
            printf("Time Complexity=O(nlog n)\n");
            break;
            case 7:

            sortDescending(arr1,10000);
            clock_t start2,end2;
            double total2=0.0; 
            start2=clock();
            heapSort(arr1, 10000);
            end2=clock();
            total2+=(double)(end2-start2)/CLOCKS_PER_SEC;
            printf("\nTime elpased is %f seconds\n", total2);
            printf("Time Complexity=O(nlog n)\n");
            break;

            case 8:

            printf("Already Sorted: O(nlog n)\n");
            printf("Reverse Sorted: O(nlog n)\n");
            printf("Random Sample:  O(nlog n)\n");
            break;

            case 9:
            
            largest(arr,n);
            break;

            case 10:

            replace(arr,n);
            break;

            case 11:
            printf("Enter the Element\n");
            int key;
            scanf("%d",&key);
            n=n+1;
            insert(arr,n,key);

            case 12:
            n=n-1;
            delete(arr,n);
            break;

        }
    }while (choice!=0);   
    return 0;
}
