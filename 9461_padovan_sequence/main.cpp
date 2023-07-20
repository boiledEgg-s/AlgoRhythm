/*
문제:
    - 파도반 수열에서 n번째 항 구하기

접근방법:
    - 파도반 수열의 패턴이 존재한다.
        - p(n) = p(n-2) + p(n-3) : 인터넷에서 찾음
        - p(n) = p(n-1) + p(n-5) : 내가 찾음
         
회고록:
    - n이 커지면서 int 자료형을 쓰면 오버플로우가 발생한다!
    - unsigned 혹은 long을 쓰자
    - 이 문제 해결하니까 바로 끝!
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    uint64_t arr[101] = {0,};
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    for(int i =4; i<=100; i++){
        arr[i] = arr[i-2] + arr[i-3];
    }
  
    int t, n;
    cin >> t;
    uint64_t ans[t];
    for(int i=0; i<t; i++){
        cin >> n;
        ans[i] = arr[n];
    }
    
    for(int i=0; i<t; i++){
        cout << ans[i]<<endl;
    }
}