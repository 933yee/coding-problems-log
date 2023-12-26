#include <bits/stdc++.h>
using namespace std;

vector<int> board;
int n;
queue<vector<int>> q;
set<vector<int>> seen;

int steps = 0;
int red_len = 0;

void print(vector<int>& board) {
    cout << '\n';
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << board[i * 6 + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void push_next_moves(vector<int>& cur_board) {
    // 往右
    for (int i = 0; i < 36; i += 6) {
        pair<int, int> car_left = {-1, -1};
        int car_len = 0;
        for (int j = 0; j < 6; j++) {
            if (cur_board[i + j] != 0) {
                if (car_left.first != cur_board[i + j]) {
                    car_len = 1;
                    car_left.first = cur_board[i + j];
                    car_left.second = j;
                } else
                    car_len++;
            } else if (car_left.first != -1 && car_len >= 2) {
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                if (seen.count(cur_board) == 0) {
                    seen.insert(cur_board);
                    q.push(cur_board);
                }
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                car_left.first = -1;
            }
        }
    }
    // 往左
    for (int i = 0; i < 36; i += 6) {
        pair<int, int> car_left = {-1, -1};
        int car_len = 0;
        for (int j = 5; j >= 0; j--) {
            if (cur_board[i + j] != 0) {
                if (car_left.first != cur_board[i + j]) {
                    car_len = 1;
                    car_left.first = cur_board[i + j];
                    car_left.second = j;
                } else
                    car_len++;
            } else if (car_left.first != -1 && car_len >= 2) {
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                if (seen.count(cur_board) == 0) {
                    seen.insert(cur_board);
                    q.push(cur_board);
                }
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                car_left.first = -1;
            }
        }
    }

    // 往下
    for (int i = 0; i < 6; i++) {
        pair<int, int> car_left = {-1, -1};
        int car_len = 0;
        for (int j = 0; j < 36; j += 6) {
            if (cur_board[i + j] != 0) {
                if (car_left.first != cur_board[i + j]) {
                    car_len = 1;
                    car_left.first = cur_board[i + j];
                    car_left.second = j;
                } else
                    car_len++;
            } else if (car_left.first != -1 && car_len >= 2) {
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                if (seen.count(cur_board) == 0) {
                    seen.insert(cur_board);
                    q.push(cur_board);
                }
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                car_left.first = -1;
            }
        }
    }
    // 往上
    for (int i = 0; i < 6; i++) {
        pair<int, int> car_left = {-1, -1};
        int car_len = 0;
        for (int j = 30; j >= 0; j -= 6) {
            if (cur_board[i + j] != 0) {
                if (car_left.first != cur_board[i + j]) {
                    car_len = 1;
                    car_left.first = cur_board[i + j];
                    car_left.second = j;
                } else
                    car_len++;
            } else if (car_left.first != -1 && car_len >= 2) {
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                if (seen.count(cur_board) == 0) {
                    seen.insert(cur_board);
                    q.push(cur_board);
                }
                swap(cur_board[i + car_left.second], cur_board[i + j]);
                car_left.first = -1;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 36; i++) {
        cin >> n;
        board.push_back(n);
        if (n == 1) red_len++;
    }
    seen.insert(board);
    q.push(board);
    // push_next_moves(board, -1);
    while (!q.empty()) {
        if (steps > 10) {
            cout << -1;
            return 0;
        }
        for (int i = q.size(); i--;) {
            auto cur_board = q.front();
            q.pop();
            if (cur_board[17] == 1 && cur_board[16] == 1) {
                if (steps + red_len > 10)
                    cout << -1;
                else
                    cout << steps + red_len;
                // cout << '\n';
                // print(cur_board);
                return 0;
            }

            push_next_moves(cur_board);
        }
        steps++;
    }
    cout << -1;
}

// 2 2 4 4 4 1
// 3 0 0 5 0 1
// 3 0 0 5 0 0
// 3 0 0 5 0 0
// 4 0 0 0 8 8
// 4 0 6 6 6 0

// 2 2 0 0 0 7
// 3 0 0 0 5 7
// 3 1 1 0 5 7
// 3 0 0 0 5 0
// 4 0 0 0 8 8
// 4 0 6 6 6 0

// 0 0 9 2 2 2
// 0 0 9 0 0 7
// 0 0 1 1 1 7
// 4 0 0 0 0 0
// 4 10 10 10 8 8
// 4 0 6 6 6 0