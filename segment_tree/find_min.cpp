    
   /*ratan_03*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define one cout<<-1<<"\n"
#define M 1000000007
int n, q;
int arr[200200];
ll t[800800];

void build(int idx, int l, int r) {
    if (l == r) {
        t[idx] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    t[idx] = min(t[2 * idx] , t[2 * idx + 1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        arr[pos] = val;
        t[idx] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    update(2 * idx, l, mid, pos, val);
    update(2 * idx + 1, mid + 1, r, pos, val);
    t[idx] = min(t[2 * idx] , t[2 * idx + 1]);
}

ll query(int idx, int l, int r, int lq, int rq) {
    if (l > rq || lq > r) return  LLONG_MAX;
    if (lq <= l && rq >= r) {
        return t[idx];
    }
    int mid = l + (r - l) / 2;
    return min( query(2 * idx, l, mid, lq, rq) , query(2 * idx + 1, mid + 1, r, lq, rq));
}

int main(){
  ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n - 1);
    
    for (int k = 0; k < q; k++) {
        int a;
        cin >> a;
        if (a == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            update(1, 0, n - 1, i, x);
        } else {
            int lq, rq;
            cin >> lq >> rq;
            lq--; rq--; 
            cout << query(1, 0, n - 1, lq, rq) << '\n';
        }
    }
}
