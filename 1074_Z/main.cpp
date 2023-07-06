/*
문제:
    - Z 루트대로 탐색을 진행했을 때 특정 위치가 몇 번째로 탐색되는지 알아보기

접근방법:
    - 주어진 조건대로 진행이 될 때 공식을 정의하여 계산
    - 각 구역의 한 면의 길이가 0이 될때까지 반복한다...
        - 2차원 배열을 4분할
        - 주어진 행과 열이 n/2보다 큰지 작은지에 따라 4개 구역 중 하나를 선택
        - 이 때 최종 결과에 각 구역별 첫번째 값을 더하여 저장해놓는다.
회고록:
    - 범위 설정과 범위가 줄어들 때의 각종 변수 값들을 잘 계산하도록 하자.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    int num = 0;
    int range = pow(2, n*2);
    int div = pow(2, n);
    
    range /= 4;
    div /= 2;
    do{
        //cout<<"range: "<<range <<" / div: "<<div  <<" / num: "<< num <<" / r: "<< r <<" / c: "<< c <<endl;

        if(r >= div){
            num += range * 2;
            r %= div;
        }
        if(c >= div){
            num += range;
            c %= div;
        }
        range /= 4;
        div /= 2;
    }while(range > 0);
    
    cout << num << endl;
}