#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n, k;
		cin >> n >> k;
		map <int, int> m;
		while(n--)
		{
			string str;
			cin >> str;
			int len = str.length();
			map<int, int> :: iterator it;
			it = m.find(len);
			if(it != m.end())
				it->second++;
			else
				m.insert(make_pair(len, 1));
		}
		map <int,int> :: iterator it;
		int flag=0;
		for(it = m.begin(); it !=m.end(); it++)
		{
			if(*it->second % k != 0)
			{
				flag =1;
				cout << "Not possible" << endl;
				break;
			}
		}
		if(!flag)
			cout << "Possible" << endl;
	}
	return 0;
}