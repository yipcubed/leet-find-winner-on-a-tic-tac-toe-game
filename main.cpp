#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:

  bool wins(vector<vector<char>> &mat, char m) {
    // rows
    for (int row = 0; row < 3; ++row) {
      bool all = true;
      for (int col = 0; col < 3 && all; ++col) {
        all = mat[row][col] == m;
      }
      if (all)
        return true;
    }
    // cols
    for (int c2 = 0; c2 < 3; ++c2) {
      bool all = true;
      for (int r2 = 0; r2 < 3 && all; ++r2) {
        all = mat[r2][c2] == m;
      }
      if (all)
        return true;
    }
    return (mat[0][0] == m && mat[1][1] == m && mat[2][2] == m) ||
        (mat[0][2] == m && mat[1][1] == m && mat[2][0] == m);
  }
  string tictactoe(vector<vector<int>> &moves) {
    vector<vector<char>> v{vector<char>{' ', ' ', ' '}, vector<char>{' ', ' ', ' '}, vector<char>{' ', ' ', ' '}};
    for (int i = 0; i < moves.size(); i += 2) {
      v[moves[i][0]][moves[i][1]] = 'X';
    }
    if (wins(v, 'X'))
      return "A";
    for (int i = 1; i < moves.size(); i += 2) {
      v[moves[i][0]][moves[i][1]] = 'O';
    }
    if (wins(v, 'O'))
      return "B";
    if (moves.size() < 9)
      return "Pending";
    return "Draw";
  }
};

void test1() {
  vector<vector<int>> v{vector<int>{0, 0}, vector<int>{2, 0}, vector<int>{1, 1}, vector<int>{2, 1}, vector<int>{2, 2}};

  cout << "A ? " << Solution().tictactoe(v) << endl;
}

void test2() {

}

void test3() {

}