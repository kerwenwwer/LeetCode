/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <limits.h>

void merge(int array[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L_tmp[n1 + 1], R_tmp[n2 + 1];
    
    for(int i = 0; i < n1; i++){
        L_tmp[i] = array[left+i];
    }
    for(int i = 0; i < n2; i++){
        R_tmp[i] = array[mid + 1 + i];
    }
    
    L_tmp[n1] = INT_MAX;
    R_tmp[n2] = INT_MAX;
    
    int l_curr = 0, r_curr = 0;
    for (int i = left; i <= right; i++){
        if(L_tmp[l_curr] <= R_tmp[r_curr]){
            array[i] = L_tmp[l_curr];
            l_curr++;
        } else {
            array[i] = R_tmp[r_curr];
            r_curr++;
        }
    }
}

void mergeSort(int array[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int array[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(array)/sizeof(int);
    
    printf("Given array is \n");
    printArray(array, arr_size);

    mergeSort(array, 0, arr_size - 1);

    printf("Sorted array is \n");
    printArray(array, arr_size);
    
    return 0;
}

