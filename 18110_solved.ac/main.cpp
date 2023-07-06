/*
문제:
    - 주어진 수 n만큼 입력을 받는다
    - 정렬을 시킨다.
    - 하위 15%, 상위 15%를 제외한 값들의 평균을 구한다.

조건:
    - n의 범위 :  (0 ≤ n ≤ 3 × 10^5)

접근방법:
    - 입력을 받고 sort와 round를 통해 정렬과 반올림을 적절히 적용하여 값을 구할 수 있는 문제
    - 간과했던 사항으론 n이 0이 되면 "div by zero" 에러가 나는 것
    - 또한 하위 자료형에 대한 사칙연산의 결과는 하위 자료형으로 저장된다는 것
        - 즉, int형을 나눈 결과가 나누어떨어지지 않더라도 소수점이 생기지 않고 내림이 됨.

회고록:
    - 주어진 조건(입력 범위, 실행 시간, 메모리 제한 등...)을 자세히 들여다보는 습관을 들이자.
    - 자료형을 잘 확인하자.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    int i, n, t, s = 1;
    vector<int> v;
    cin >> n;

    for(i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int avg=0;
    int r = round(n * 0.15);
    for(i=r; i<n-r; i++){
        avg += v.at(i);
    } 
    int div = (n == 0)?1: (n-2*r);
    cout << round((float)avg/div) << endl;
}