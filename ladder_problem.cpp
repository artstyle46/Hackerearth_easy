#include <bits/stdc++.h>
#define MAX 1000005
#define MOD 1000000007
using namespace std;

long long int arr[MAX], arr1[MAX];

int main()
{
	long long int T, n;
	cin >> T >> n;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 0;
	arr[4] = 1;
	arr[5] = 1;
	for(long long int i = 6; i <= n; i++)
		arr[i] = (arr[i-2] + arr[i-5])%MOD;
	while(T--)
	{
		long long int cur,k;
		cin >> cur >> k;
		if(k == 2 || k == 5 || k > cur)
			cout << arr[cur] << endl;
		else if (cur == k)
			cout << (arr[cur]+1)%MOD << endl;
		else
		{
			for(long long int i = 0; i < k; i++)
				arr1[i] = arr[i];
			arr1[k] = (arr[k] + 1)%MOD;
			for(long long int i = k + 1; i<=cur; i++)
			{
				arr1[i] = (arr1[i-2] + arr1[i-5] + arr1[i-k])%MOD;
			}
			cout << arr1[cur] << endl;
		}
	}
	return 0;
}