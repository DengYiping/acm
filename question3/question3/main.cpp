//
//  main.cpp
//  question3
//
//  Created by Yiping Deng on 10/6/18.
//  Copyright © 2018 Yiping Deng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

static const auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

vector<int> precompute(){
    vector<int> primes(3000, 0);
    for(int i = 2; i*i < primes.size(); i++){
        if(primes[i] == 0){
            for(int j = i*2; j*j < primes.size(); j += i){
                primes[j]++;
            }
        }
    }
    vector<int> res;
    for(int i = 2; i < primes.size(); i++){
        if(primes[i] >= 3){
            res.push_back(i);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    vector<int> res;
    res = precompute();
    
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        cout << res[n-1] << endl;
    }
    
    return 0;
}
