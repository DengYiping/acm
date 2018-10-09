//
//  main.cpp
//  question5
//
//  Created by Yiping Deng on 10/6/18.
//  Copyright © 2018 Yiping Deng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool check(const int& mid, int c, vector<int>& stalls){
    c--;
    int last_stall_idx = 0;
//    cout << "Stall: " << stalls[0] << endl;
    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i]-stalls[last_stall_idx] >= mid){
//            cout << "Stall: " << stalls[i] << endl;
            c--;
            last_stall_idx = i;
        }
    }
    return (c <= 0);
}

int solve(const int& n, const int& c, vector<int>& stalls){
    sort(stalls.begin(), stalls.end());
    int l = 0, h = (stalls[stalls.size()-1]-stalls[0]);
    int res = -1;
    while(l <= h){
        int mid = (l+h)/2;
//        cout << "High: " << h << endl;
//        cout << "Low: " << l << endl;
//        cout << "Mid: " << mid << endl;
        if(check(mid, c, stalls)){
//            cout << "Good" << endl;
            res = mid;
            l = mid + 1;
        } else {
//            cout << "Not good" << endl;
            h = mid - 1;
        }
    }
    return res;
}

int main() {
    
    
    
    int n, c;
    int cases;
    cin >> cases;
    while(cases--){
        cin >> n >> c;
        vector<int> stalls(n);
        for(int i = 0; i < n; i++){
            cin >> stalls[i];
        }
//        cout << n << " " << c << endl;
//        for(int el : stalls){
//            cout << el << " ";
//        }
//        cout << endl;
        cout << solve(n, c, stalls) << endl;
    }
    
    return 0;
}
