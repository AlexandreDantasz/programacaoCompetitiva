#include <bits/stdc++.h>

using namespace std;

char generateLetter(char a, char b)
{
    char ans = a;
    while (ans == a || ans == b)  ans = (char)(((rand() + 1) % 122) % 26 + 97);
    return ans;
}

char generateLetter(char a)
{
    char ans = a;
    while (ans == a) ans = (char)(((rand() + 1) % 122) % 26 + 97);
    return ans;
}

int recognizeNodes(string str)
{
    int counter = 1;
    for (int i = 0; i < str.size(); i++)
        if (i && str[i - 1] != str[i]) counter++;

    return counter;
}

string buildAnswer(string str, int a, int b)
{
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        ans += str[i];
        if (a < 0 || a == i) ans += generateLetter(str[a], str[b]);
    }
    
    return ans;
}

int main() 
{
    
    int t;
    cin >> t;

    while (t--)
    {
        string password;
        cin >> password;

        int pt_a = 0, pt_b = 1, solve = 0, bestValue = recognizeNodes(password);
        string ans, tempStr;

        while (pt_b < password.size())
        {
            tempStr = buildAnswer(password, pt_a, pt_b);
            if (recognizeNodes(tempStr) > bestValue)
            {
                bestValue = recognizeNodes(tempStr);
                ans = tempStr;
                solve = 1;
            }

            pt_a++;
            pt_b++;
        }

        if (!solve) 
        {
            int i;
            for (i = 0; i < password.size() - 1; i++) cout << password[i];
            cout << generateLetter(password[i]) << password[i];
        }
        else cout << ans;
        cout << '\n';
    }

    return 0;
}