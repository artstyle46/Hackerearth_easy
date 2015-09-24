#include <iostream>
#include <stdlib.h>

using namespace std;


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n, m;
		cin >> m >> n;
		int *Hb, *Hg;
		Hb = (int *)malloc(sizeof(int) * 100000);
		Hg = (int *)malloc(sizeof(int) * 100000);
		for(int i =0; i < m; i++)
			cin >> Hb[i];
		for(int j =0; j< n; j++)
			cin >> Hg[j];
		int arr_size = sizeof(Hb)/sizeof(Hb[0]);
	//	cout << arr_size << endl;
		mergesort(Hb,0,m-1);
		arr_size = sizeof(Hg)/sizeof(Hg[0]);
	//	cout << arr_size << endl;
		mergesort(Hg,0,n -1);
	//	for (int i = 0; i<m; i++)
	//		cout << Hb[i] << "boys" << Hg[i] << "girls" << endl;
		int flag = 0;
		if(m > n)
		{
			cout << "NO" << endl;
			flag = 1;
		}
		else{
		for(int i = 0; i< m; i++)
		{
			if(Hb[i] <= Hg[i])
			{
				cout << "NO" << endl;
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout << "YES" << endl;}
	}
	return 0;
}