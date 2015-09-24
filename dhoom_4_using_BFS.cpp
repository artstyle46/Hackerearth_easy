#include <iostream>
#include <queue>
#include <stdlib.h>
#define mod 100000

using namespace std;

int main()
{
	int key , lock;
	cin >> key >> lock;
	int n;
	cin >> n;
	int value[n];
	for(int i =0; i<n; i++)
		cin >> value[i];
	int visited[100005] = memset(visited,-1,100005);
	queue <int> q;
	q.push(key);
	visited[key] = 0;
	while(!q.empty())
	{
		int val = q.front();
		q.pop();
		if(val == lock)
			break;
		for(int i = 0; i<n; i++)
		{
			int temp = (arr[i] *val)%mod;
			if(visited[temp] == -1)
			{
				visited[temp] = visited[val] + 1;
				q.push(temp);
			}
		}
	}
	cout << visited[lock] << endl;
	return 0;
}