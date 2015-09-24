#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		int curr_length = 0, max_length = 0;
		int length = S.length();
		int numb_r = 0, numb_k = 0;
		for(int i = 0; i < length; i++) {
			if (S[i] == 'K')
			{
				++numb_k;
				++curr_length;
				if(max_length < curr_length)
					max_length = curr_length;
				//cout << max_length << "K-" << curr_length << endl;
			}
			else
			{
				++numb_r;
				if(max_length < curr_length)
					max_length = curr_length;
				curr_length--;
				if(curr_length < 0)
					curr_length = 0;
				//cout << numb_r << "R" << endl << max_length << "K" << endl;
			}
		}
		if (numb_k == 0)
			max_length = -1;
		cout << numb_r + max_length << endl;
	}
	return 0;
}