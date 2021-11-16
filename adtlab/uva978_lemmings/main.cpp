#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// ofstream MyFile("output.txt");

int main() {
  int n;
  cin >> n;
  for (int count = 0; count < n; count++) {
    int b, sg, sb;
    cin >> b >> sg >> sb;
    multiset<int> gTeam;
    multiset<int> bTeam;
    for (int i = 0; i < sg; i++) {
      int ginput;
      cin >> ginput;
      gTeam.insert(ginput);
    }
    for (int i = 0; i < sb; i++) {
      int binput;
      cin >> binput;
      bTeam.insert(binput);
    }

    vector<int> gTeamVec;
    vector<int> bTeamVec;
    while (gTeam.size() != 0 && bTeam.size() != 0) {
      //   cout << "New Round" << endl;
      for (int i = 0; i < b; i++) {
        if (gTeam.size() == 0 || bTeam.size() == 0) {
          break;
        }
        // cout << "G Size:" << gTeam.size() << " B Size:" << bTeam.size() <<
        // endl;
        auto gTeamLem = gTeam.end();
        auto bTeamLem = bTeam.end();
        gTeamLem--;
        bTeamLem--;
        gTeam.erase(gTeamLem);
        bTeam.erase(bTeamLem);
        // cout << "G:" << *gTeamLem << " vs B:" << *bTeamLem << endl;
        if (*gTeamLem > *bTeamLem) {
          //   cout << "G win"
          //        << " | " << *gTeamLem - *bTeamLem << endl;
          gTeamVec.push_back(*gTeamLem - *bTeamLem);
        } else if (*bTeamLem > *gTeamLem) {
          //   cout << "B win"
          //        << " | " << *bTeamLem - *gTeamLem << endl;
          bTeamVec.push_back(*bTeamLem - *gTeamLem);
        } else {
          //   cout << "Draw" << endl;
        }

        // cout << "G Size:" << gTeam.size() << " B Size:" << bTeam.size() <<
        // endl;
      }

      for (int i = 0; i < gTeamVec.size(); i++) {
        gTeam.insert(gTeamVec[i]);
      }
      for (int i = 0; i < bTeamVec.size(); i++) {
        bTeam.insert(bTeamVec[i]);
      }
      gTeamVec.clear();
      bTeamVec.clear();
    }
    if (gTeam.size() == 0 && bTeam.size() == 0) {
      cout << "green and blue died" << endl;
    } else if (gTeam.size() == 0) {
      cout << "blue wins" << endl;
      for (auto i = bTeam.rbegin(); i != bTeam.rend(); i++) {
        cout << *i << endl;
      }
    } else if (bTeam.size() == 0) {
      cout << "green wins" << endl;
      for (auto i = gTeam.rbegin(); i != gTeam.rend(); i++) {
        cout << *i << endl;
      }
    }
    if (count != n - 1) {
      cout << endl;
    }
  }
  return 0;
}
