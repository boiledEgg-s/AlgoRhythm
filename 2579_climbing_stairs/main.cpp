/*
문제:
    - 점수가 쓰인 계단을 특정 패턴으로 이동하여 올랐을 때 얻을 수 있는 최대 점수 
조건:
    - 시작점은 계단에 포함되지 않음
    - 연속된 세 계단을 오를 수 없음
    - 마지막 계단은 반드시 밟아야 함

접근방법:
    - 다이나믹 프로그래밍을 사용해야 한다.
    - 특정 계단을 밟은 경우와 그렇지 않은 경우로 세분화하여 탐색
        - 안밟으면 이전 계단을 무조건 밟아야 함
        - 밟아야 한다면 "전전 계단을 밟지 않고 전 계단 밟기" 혹은  "전전 계단을 밟고 이전 계단을 밟지 않기" 중
          중 하나를 만족해야 한다. 
        
회고록:
    - 계단을 밟았을 때 따져야 하는 조건을 제대로 생각해내지 못하였다...
    - 문제 풀 땐 집중해서 하자!
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n+1][2] = {0,};
    int num[n+1] = {0,};

    for(int i=1; i<=n; i++){
        cin >> num[i];
    }
    arr[1][1] = num[1];
    arr[2][0] = num[1];
    arr[2][1] = num[1] + num[2];

    for(int i=3; i<=n; i++){
        int a = arr[i-1][0] + num[i];
        int b = arr[i-2][0] + num[i-1] + num[i];
        arr[i][1] = max(a, b);
        arr[i][0] = arr[i-1][1];
        //cout << "when " << num[i] << " is included : "<<arr[i][1]<<endl;
    }

    cout << arr[n][1] << endl;
}