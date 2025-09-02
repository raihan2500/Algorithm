#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<vector<string>> ans;

bool ok(vector<string> &board, int row, int col, int n){
  for(int i = 0; i < n; i++){
    if(board[row][i] == 'Q')return false;
  }
  for(int i = 0; i < n; i++){
    if(board[i][col] == 'Q')return false;
  }
  for(int i = row, j = col; i >= 0 and j < n; i--, j++){
    if(board[i][j] == 'Q')return false;
  }

  for(int i = row, j = col; i >= 0 and j >= 0; i--, j--){
    if(board[i][j] == 'Q')return false;
  }
  return true;
}

void nQueens(vector<string> &board, int row, int n){
  if(row == n){
    ans.push_back(board);
    clog << db(board);
    return;
  }
  for(int j = 0; j < n; j++){
    if(ok(board, row, j, n)){
      board[row][j] = 'Q';
      nQueens(board, row + 1, n);
      board[row][j] = '.';
    }
  }
}

int32_t main(){
  int n;
  cin >> n;
  vector<string> board(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      board[i].push_back('.');
    }
  }
  nQueens(board, 0, n);
}