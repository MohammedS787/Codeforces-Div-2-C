#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;
	map<string,int>mp;

	while(n--){
		string s;
		cin >> s;
		if(mp[s] == 0){
			cout << "OK" << endl;
			mp[s]++;
		}
		else{
			cout << s << mp[s]++ << endl;
		}
	}
}
