#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int, int>

using namespace std;

int ans = 0;

void Solution(pii suneet, pii slavic)
{
    // scoreboard
    pii playersWins = {0, 0};

    // first round
    if (suneet.f != slavic.f)
    {
        if (suneet.f > slavic.f) playersWins.f++;
        else playersWins.s++;
    }

    // second round
    if (suneet.s != slavic.s)
    {
        if (suneet.s > slavic.s) playersWins.f++;
        else playersWins.s++;
    }

    if (playersWins.f > playersWins.s) ans++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int cards[4];
        for (auto &value : cards) cin >> value;

        ans = 0;
        // permutation
        Solution({cards[0], cards[1]}, {cards[2], cards[3]});
        Solution({cards[0], cards[1]}, {cards[3], cards[2]});
        Solution({cards[1], cards[0]}, {cards[2], cards[3]});
        Solution({cards[1], cards[0]}, {cards[3], cards[2]});
        cout << ans << '\n';
    }

    return 0;
}