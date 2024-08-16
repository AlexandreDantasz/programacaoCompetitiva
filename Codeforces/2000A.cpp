#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

int main()
{
    //freopen("a.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    while (t--)
    {
        string number;
        cin >> number;

        int size = number.size();
        if (size < 3) cout << "NO\n";
        else
        {
            bool verify_ten = number[0] == '1' && number[1] == '0';
            if (verify_ten)
            {
                int char_value = ((int) number[2]) - 48;
                if (size == 3)
                    cout << (char_value < 2 ? "NO\n" : "YES\n");
                else
                    cout << (char_value == 0 ? "NO\n" : "YES\n");
            }
            else cout << "NO\n";
        }
    }

    return 0;
}