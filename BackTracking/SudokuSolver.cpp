#include<bits/stdc++.h>
using namespace std;


#define vvc vector<vector<char>>

int n;

bool ok(vvc &board, int row, int col, int d){
  char c = '0' + d;
  for(int i = 0; i < n; i++){
    if(board[row][i] == c)return false;
  }
  for(int i = 0; i < n; i++){
    if(board[i][col] == c)return false;
  }

  int si = (row / 3) * 3;
  int sj = (col / 3) * 3;

  for(int i = si; i <= (si + 2); i++){
    for(int j = sj; j <= (sj + 2); j++){
      if(board[i][j] == c)return false;
    }
  }
  
  return true;
}

vvc ans;

void sudokuSolver(vvc &board, int row, int col){
  if(row >= n){
    ans = board;
    return;
  }

  if(col >= n){
    sudokuSolver(board, row + 1, 0);
    return;
  }
  if(board[row][col] != '.'){
    sudokuSolver(board, row, col + 1);
    return;
  }

  for(int i = 1; i <= 9; i++){
    if(ok(board, row, col, i)){
      board[row][col] = i + '0';
      sudokuSolver(board, row, col + 1);
      board[row][col] = '.';
    }
  }
}

int32_t main(){
  cin >> n;
  vector<vector<char>> board(n, vector<char> (n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }
}