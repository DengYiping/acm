//
//  main.cpp
//  question7
//
//  Created by Yiping Deng on 10/6/18.
//  Copyright © 2018 Yiping Deng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define MAXX 200005

int L, R, RES, freq[MAXX], arr[MAXX];
vector<int> elems;

struct query{
    int l, r, idx;
};
vector<query> a;

bool cmp(const query& a, const query& b){
    if(a.r == b.r){
        if(a.l == b.l){
            return a.idx < b.idx;
        }
        return a.l < b.l;
    }
    return a.r < b.r;
}

void remove(int idx){
    arr[freq[elems[idx]]]--;
    freq[elems[idx]]--;
    arr[freq[elems[idx]]]++;
    if(RES > 0 && !arr[RES]) RES--;
}

void add(int idx){
    arr[freq[elems[idx]]]--;
    freq[elems[idx]]++;
    arr[freq[elems[idx]]]++;
    if(arr[RES+1]) RES++;
}

int solveQuery(query q){
    if(L < q.l){
        remove(L);
        L++;
    } else if(L > q.l){
        L--;
        add(L);
    }
    if(R < q.r){
        R++;
        add(R);
    } else if(R > q.r){
        remove(R);
        R--;
    }
    return RES;
}

int main(int argc, const char * argv[]) {
   
    while(true){
        int n, q;
        cin >> n;
        if(n == 0) break;
        cin >> q;
        elems.clear();
        elems.resize(n);
        for(int i = 0; i < n; i++){
            cin >> elems[i];
            elems[i] += 100000;
        }
        a.clear();
        a.resize(q);
        for(int i = 0; i < q; i++){
            cin >> a[i].l >> a[i].r;
            a[i].l--;
            a[i].r--;
            a[i].idx = i;
        }
        vector<int> res(q);
        sort(a.begin(), a.end(), cmp);
        for(int i = 0; i < q; i++){
            res[a[i].idx] = solveQuery(a[i]);
        }
        for(int i = 0; i < q; i++){
            cout << res[i] << endl;
        }
    }
    
    return 0;
}
