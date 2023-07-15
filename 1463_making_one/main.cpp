/*
문제:
    - 3 또는 2로 나누거나 1을 빼는 3가지 연산 만을 사용하여 주어진 수를 1로 만들기 위한 최소 연산 횟수
조건:
    - 주어진 수는 10의 6승 보다 작거나 같음

접근방법:
    - 주어진 수를 분할해가면서 탐색
    - 재귀 함수를 통해 특정 단계에서의 수가 조건에 만족하면 연산을 진행하고 연산 횟수를 배열에 기록한다.
    - 재귀 함수가 다 돌면 배열의 n번째 인덱스를 출력한다.
        
회고록:
    - 처음에 너무 단순하게 3으로 나눠보고, 안되면 2로 나누고, 안되면 1을 빼는 방법을 사용하여 당연하게도 틀렸다.
    - 모든 순간에서 3으로 나눈 것, 2로 나눈 것, 1을 뺀 것 세 가지를 비교하여 최솟값을 기록한다.
    - 재귀를 통해 분할하다 보면 제일 작은 값 4부터 기록하게 되는 것을 알 수 있다. 이를 통해 4부터 차근 차근 기록하여
      n번째 위치에도 값이 기록되게 되는 것이다. 
*/

#include <bits/stdc++.h>
using namespace std;

int num[1000001] = {0,};

int loops(int index){

    if(index <= 3 || num[index] != 0) return num[index];

    int ret = 0;
    if(index % 6 == 0) ret = min(loops(index-1), min(loops(index/3), loops(index/2)));
    else if(index % 3 == 0) ret = min(loops(index/3), loops(index - 1));
    else if(index % 2 == 0) ret = min(loops(index-1), loops(index/2));
    else ret = loops(index-1);

    num[index] = ret + 1;
    return num[index];

}


int main() {
    int n;
    cin >> n;
    num[1] = 0;
    num[2] = 1;
    num[3] = 1;

    loops(n);

    cout << num[n] << endl;

}

