#include <iostream>
#include <set>
using namespace std;

int main()
{
    int T, k, n;
    char c;
    
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> k;
        multiset<int> Q;
        for(int j = 0; j < k; j++)
        {
            cin >> c >> n;
            if (c == 'I')
            {
                Q.insert(n);
            }
            else if (c == 'D')
            {
                if (Q.empty())
                    continue;
                if (n == -1)
                    Q.erase(Q.begin());
                if (n == 1)
                    Q.erase(--Q.end());
            }
        }

        if (Q.size() == 0)
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << *(--Q.end()) << ' ' << *Q.begin() << '\n';
        }
    }

    return (0);
}