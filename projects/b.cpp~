
#include <bits/stdc++.h>

using namespace std;

struct MatchResult {
    int team1;
    int team2;
    int score1;
    int score2;
};

bool compareTeams(pair<int, pair<int, int>> team1, pair<int, pair<int, int>> team2) {
    if (team1.first != team2.first) {
        return team1.first > team2.first;
    } else if (team1.second.first != team2.second.first) {
        return team1.second.first > team2.second.first;
    } else if (team1.second.second != team2.second.second) {
        return team1.second.second > team2.second.second;
    } else {
        return team1.first < team2.first;
    }
}

int main() {
    int K;
    cin >> K;

    vector<pair<int, pair<int, int>>> teams;
	for (int i = 0; i < 4; ++i) {
        teams.push_back({0, {0, 0}});
    }

    for (int i = 0; i < K; ++i) {
        MatchResult match;
        cin >> match.team1 >> match.team2 >> match.score1 >> match.score2;

        teams[match.team1 - 1].first += (match.score1 > match.score2) ? 3 : ((match.score1 == match.score2) ? 1 : 0);
        teams[match.team2 - 1].first += (match.score2 > match.score1) ? 3 : ((match.score2 == match.score1) ? 1 : 0);
        teams[match.team1 - 1].second.first += match.score1 - match.score2;
        teams[match.team2 - 1].second.first += match.score2 - match.score1;
        teams[match.team1 - 1].second.second += match.score1;
        teams[match.team2 - 1].second.second += match.score2;
    }

    sort(teams.begin(), teams.end(), compareTeams);

    for (int i = 0; i < 4; ++i) {
        cout << teams[i].first;
        if (i < 3) {
            cout << " ";
        }
    }

    return 0;
}
