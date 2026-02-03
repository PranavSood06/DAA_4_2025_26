#include <bits/stdc++.h>
using namespace std;

vector<bool> cols;
vector<int> Rdiagonal;
vector<int> Ldiagonal;

bool isSafe(int r, int c, vector<bool>& cols, vector<int>& Rdiagonal,
            vector<int>& Ldiagonal, int n) {
    if (cols[c] == true)
        return false;
    if (Rdiagonal[r + c] == true)
        return false;
    if (Ldiagonal[r - c + n - 1] == true)
        return false;
    return true;
}

void helper(vector<string>& grid, vector<vector<string>>& ans, int row,int n){
    if (row == n) {
        ans.push_back(grid);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(row, i, cols, Rdiagonal, Ldiagonal, n)) {
            grid[row][i] = 'Q';
            cols[i] = true;
            Rdiagonal[row + i] = true;
            Ldiagonal[row - i + n - 1] = true;
            helper(grid, ans, row + 1, n);
            cols[i] = false;
            Rdiagonal[row + i] = false;
            Ldiagonal[row - i + n - 1] = false;
            grid[row][i] = '.';
        }
    }
}

int main(){
    int n ;
    cin >> n;
    cols.assign(n, false);
    Rdiagonal.assign(2 * n - 1, false);
    Ldiagonal.assign(2 * n - 1, false);
    vector<string> grid(n, string(n, '.'));
    vector<vector<string>> ans;
    int row = 0;
    helper(grid, ans, row, n);
    for (auto board : ans) {
        for (auto str : board) {
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}
