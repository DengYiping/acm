//
//  main.cpp
//  question4
//
//  Created by Yiping Deng on 10/6/18.
//  Copyright © 2018 Yiping Deng. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string solve(string a, string b){
    int i = 0;
    for(; i < a.length(); i++){
        if(a[i] > b[0]){
            break;
        }
    }
    string res;
    res = a.substr(0, i) + b + a.substr(i);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string a;
    string b;
    while((cin >> a)){
        cin >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
