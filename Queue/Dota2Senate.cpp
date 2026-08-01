 #include <string>
 #include <queue>
using namespace std;

 string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();

            if (r < d) {
                radiant.push(r + n); // Radiant acts first, bans Dire, survives to next round
            } else {
                dire.push(d + n); // Dire acts first, bans Radiant, survives to next round
            }
        }