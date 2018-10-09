//
//  main.cpp
//  question1
//
//  Created by Yiping Deng on 10/6/18.
//  Copyright © 2018 Yiping Deng. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
static const auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
int solve(int m, int n, int i, vector<vector<int>>& arr, vector<vector<int>>& mem){
    if(mem[i][n] == -1){
        if(i == m - 1){
            if(arr[i][0] <= n && arr[i][1] >= n){
                mem[i][n] = 1;
            } else {
                mem[i][n] = 0;
            }
        } else {
            if(n < arr[i][0]){
                mem[i][n] = 0;
            } else {
                int count = 0;
                for(int j = arr[i][0]; j <= arr[i][1] && j <= n; j++){
                    count += solve(m, n - j, i + 1, arr, mem);
                }
                mem[i][n] = count;
            }
        }
    }
    return mem[i][n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
  while(true){
  int m, n;
    cin >> m >> n;
    if(m == 0 && n == 0) break;
    vector<vector<int>> mem(m + 1, vector<int>(n  + 1, -1));
    vector<vector<int>> in(m, vector<int>(2, 0));

    for(int i = 0; i < m; i++){
        cin >> in[i][0] >> in[i][1];
    }
    int rst = solve(m, n, 0, in, mem);

    cout << rst << endl;
  }
    return 0;
}


