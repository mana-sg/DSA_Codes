#include<stdio.h>
#define MAX 50

int* maxHeapifyBottomUp(int *a, int n){
    int elt, c, p, k;
    for (k=n/2-1; k>=0;k--) 
    {
        p=k;
        elt=a[p];
        c=2*p+1;
        while(c<n) 
        {
            if(c+1<n) 
            {
                if(a[c+1]>a[c])
                    c=c+1;
            }
            if(elt<a[c])
            {    
                a[p]=a[c];
                p=c;
                c=2*p+1;
            } 
            else 
            {
                break;
            }
        }
        a[p]=elt; 
    }
    return a;
}

int* minHeapifyBottomUp(int *a, int n){
    int elt, c, p, k;
    for (k=n/2-1; k>=0;k--) 
    {
        p=k;
        elt=a[p];
        c=2*p+1;
        while(c<n) 
        {
            if(c+1<n) 
            {
                if(a[c+1]<a[c])
                    c=c+1;
            }
            if(elt>a[c])
            {    
                a[p]=a[c];
                p=c;
                c=2*p+1;
            } 
            else 
            {
                break;
            }
        }
        a[p]=elt; 
    }
    return a;
}

int* maxHeapifyTopDown(int *a, int n){
    int i, c, p, elt;
    for(i = 1; i < n; i++){
        elt = a[i];
        c = i;
        p = (c-1)/2;
        while(c > 0 && a[p] < elt){
            a[c] = a[p];
            c = p;
            p = (c-1)/2;
        }
        a[c] = elt;
    }
    return a;
}

int* minHeapifyTopDown(int *a, int n){
    int i, c, p, elt;
    for(i = 1; i < n; i++){
        elt = a[i];
        c = i;
        p = (c-1)/2;
        while(c > 0 && a[p] > elt){
            a[c] = a[p];
            c = p;
            p = (c-1)/2;
        }
        a[c] = elt;
    }
    return a;
}

int main()
{
	int a[MAX];
	int i,c,p,n,elt;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
        
    int choice;
    printf("1. Heapify Max(TopDown)\n2. Heapify Min(TopDown\n3. Heapify Min(BottomUp)\n4. Heapify Min(BottomUp)\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            maxHeapifyTopDown(a, n);
            break;
        case 2:
            minHeapifyTopDown(a, n);
            break;
        case 3:
            minHeapifyBottomUp(a, n);
            break;
        case 4:
            minHeapifyBottomUp(a, n);
            break;
        default:
            printf("Invalid choice\n");
    }
 
	printf("\nElements of heap:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	return 0;
}