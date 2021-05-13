#include<bits/stdc++.h>
using namespace std;

int main(){

    string str;
    stack <char> u, t;
    int freq[26] = {0};

    cin >> str;

    for (int i = 0; i < (int)str.size(); ++i){
        ++freq[str[i] - 'a'];
    }

    char c = 'a';

    for (int i = 0; i < (int)str.size(); ++i){
        while(!freq[c-'a']){
            ++c;
        }

        while(!u.empty() && u.top() <= c){
            t.push(u.top());
            u.pop();
        }


        if(str[i] == c){
            t.push(str[i]);
        }else{
            u.push(str[i]);
        }
        --freq[str[i]-'a'];
    }

    while(!u.empty()){
        t.push(u.top());
        u.pop();
    }


    for (int i = (int)str.size()-1; ~i ; --i){
        str[i] = t.top();
        t.pop();
    }

    cout << str << "\n";

    return 0;
}
