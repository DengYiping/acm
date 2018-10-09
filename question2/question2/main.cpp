//
//  main.cpp
//  question2
//
//  Created by Yiping Deng on 10/6/18.
//  Copyright © 2018 Yiping Deng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
set<int> digit(long long i){
    set<int> set;
    while(1){
        set.insert(i % 10);
        i = i / 10;
        if(i == 0)
            break;
    }
    return set;
}

inline long long calc(long long i){
    if(i <= 1){
        return 0;
    } else {
        return i * (i - 1) / 2;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<long long> mem(10, 0);
    
    int n;
    cin >> n;
    long long tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        for(auto d : digit(tmp)){
            mem[d]++;
        }
    }
    long long count = 0;
    for(int i = 0; i < 10; i++){
        count += calc(mem[i]);
    }
    cout << count << endl;
    return 0;
}
