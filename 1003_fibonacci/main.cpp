/*
문제:
    - 어떤 수에 대한 피보나치 수열 값을 구한다.
    - 이때 0과 1에 도달한 횟수를 구한다.
조건:
    - n의 범위 :  (0 ≤ n ≤ 40)

접근방법:
    - 0과 1에 접근하는 횟수를 따로 관리한다.
    - T가 0일 때 0에 접근하는 횟수는 1, 1일 때 1에 접근하는 횟수를 1로 고정시킨다.
    - n의 범위가 작으므로 모든 수에 대한 접근 횟수를 미리 계산한다.
    - 이후 수를 입력받으면 그에 해당되는 0과 1접근 횟수를 출력한다.
회고록:
    - 주어진 범위가 작으면 모든 값을 미리 계산하는 경우도 고려해보자.
    - 원래 재귀로 풀어보려고 하였지만 잘 풀리지 않았다. 주어진 시간 안에 풀기 위해선 함수로 접근하는 방법은 통하지 않는 듯 하다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0, T = 0;
    int one_arr[41], zero_arr[41];
    std::fill_n(one_arr, 41, 0);
    std::fill_n(zero_arr, 41, 0);
    zero_arr[0] = 1;
    one_arr[1] = 1;
    one_arr[2] = 1;
    zero_arr[2] = 1;
    for(int j = 3; j < 41; j++) {
            one_arr[j] = one_arr[j - 1] + one_arr[j - 2];
            zero_arr[j] = zero_arr[j - 1] + zero_arr[j- 2];
        } 
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d %d\n", zero_arr[n], one_arr[n]);
    }
}

