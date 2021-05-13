#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> path;
    string command, paramter;
    while (n--)
    {
        cin >> command;
        if (command.compare("pwd") == 0)
        {
            cout << '/';
            for (int i = 0; i < path.size(); i++)
                cout << path[i] << '/';
            cout << endl;
        }
        else
        {
            cin >> paramter;
            int pos = 0;
            if (paramter[0] == '/')
                path.clear(), pos = 1;
            while (true)
            {
                int nextPosition = paramter.find('/', pos);
                if (nextPosition != string::npos)
                {
                    string dir = paramter.substr(pos, nextPosition - pos);
                    if (dir.compare("..") != 0)
                        path.push_back(dir);
                    else if (!path.empty())
                        path.pop_back();
                    pos = nextPosition + 1;
                }
                else
                {
                    string dir = paramter.substr(pos, string::npos);
                    if (dir.compare("..") != 0)
                        path.push_back(dir);
                    else if (!path.empty())
                        path.pop_back();
                    break;
                }
            }
        }
    }
}
