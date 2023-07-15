/*
문제:
    - 사람 수와 각 인원 별 atm 사용 시간이 주여졌을 때, 
      줄 세우기를 통해 각 인원이 atm 사용을 끝마치기까지 걸린 시간의 총합의 최솟값 구하기

접근방법:
    - 제일 빨리 atm을 사용하는 사람을 맨 앞에 배치
    - 총합은 첫번째*n + 두번째*(n-1) + ... 가 된다. 여기서 n은 사람 수
        
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, sum = 0;
    cin >> t;

    vector<int> num;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        num.push_back(n);
    }

    sort(num.begin(), num.end());

    for(int i=0; i<t; i++){
        sum += num.at(i) * (t-i); 
    }

    cout << sum << endl;
    
}