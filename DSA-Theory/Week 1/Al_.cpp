#include <stdio.h>
#include <stdlib.h>
#include <time.h>


 int Bruteforce1(int a[],int n)
{
	int i;
    int maxA = a[0];
    for ( i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += a[k];
            if (maxA < sum)
                maxA = sum;
        }
    return maxA;
} 

int bruteforce2(int a[],int n)
{

    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum > max)
                max = sum;
        }
    }
    return max;
}

int max(int a, int b)
{
    if (a < b)
        return b;
    else
        return a;
}
int Dynamicprogram(int a[], int n)
{
    int e = a[0];
    int s = a[0];
    for (int i = 1; i < n ; i++)
    {
        e = max(a[i], a[i] + e);
        s = max(e, s);
    }
    return s;
} 



int main()
{	int i; 
	
    int n; printf("Enter n:"); scanf("%d",&n);
    int a[n];
    for (i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + rand() % 100;
	}
	
    time_t startT, endT;
    startT = clock();
    int b = Bruteforce1(a,n);
    endT = clock();
    printf("The maximum subarray by using BF1: %d\n", b);
    printf("--> Time: %.30f\n",(float)(endT - startT)/CLOCKS_PER_SEC); 
    
    startT = clock();
    int c = bruteforce2(a,n);
    printf("The maximum subarray by using BF2: %d\n", c);
	endT = clock();
	printf("--> Time: %.10f\n",(float)(endT - startT)/CLOCKS_PER_SEC);
	
	startT = clock();
    int c1 = Dynamicprogram(a,	n);
    endT = clock();
    printf("The maximum subarray by using DP: %d\n", c1); 
    printf("--> Time: %.10f\n",(float)(endT - startT)/CLOCKS_PER_SEC);
    
    return 0;
}
