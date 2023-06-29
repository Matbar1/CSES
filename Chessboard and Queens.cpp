#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board(8, vector<char>(8));
vector<int> row(8, 0), col(8, 0), diag1(15, 0), diag2(15, 0);

int totalSolutions = 0;

void search(int y) {
    if (y == 8) {
        totalSolutions++;
        return;
    }

    for (int x = 0; x < 8; x++) {
        if (board[y][x] == '*' || row[y] || col[x] || diag1[x + y] || diag2[x - y + 7])
            continue;

        row[y] = col[x] = diag1[x + y] = diag2[x - y + 7] = 1;
        search(y + 1);
        row[y] = col[x] = diag1[x + y] = diag2[x - y + 7] = 0;
    }
}

int main() {
    // Read the chessboard
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    search(0);

    cout << totalSolutions << endl;

    return 0;
}
