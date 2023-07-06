#include <bits/stdc++.h>
using namespace std;

int main() {
    char buf [1001];
    int i;
    cin >> buf >> i;

    if(i>=1 && i<=strlen(buf))
        cout << buf[i-1] <<endl; 
}