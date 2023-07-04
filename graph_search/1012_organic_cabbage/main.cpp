/*
문제:
    - 밭 위에 풀어야하는 최소 벌레 수
조건:
    - 좌우상하로 연결되게 심어진 배추들은 벌레 한마리로 커버 가능

접근방법:
    - dfs 방법으로 접근
        - 배열 탐색, 1이면 큐에 삽입
        - 큐가 빌 때까지 반복...
            - 큐에 인자가 들어가면 큐에서 하나 씩 빼면서 탐색
            - 배열 값을 2로 바꾸고 해당 위치의 상하좌우를 큐에 삽입
        
회고록:
    - 그래프 관련된 문제들을 대부분 dfs bfs 관련이다. 그쪽으로 먼저 생각해보자
    - 항상 사용되는 변수들과 인자가 잘 들어가는지 확인하자. y+1 잘못 넣어서 1시간 고생했다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<pair<int, int>> qu;

    int t, i;

    cin >> t;
    int num[t] = {0};
    for(i=0; i<t; i++){
        int m, n, k, j;
        cin >> m >> n >> k;
        int field[n][m];
        memset(field, 0, sizeof(field));
        
        for(j=0; j<k; j++){
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int a, b;
        
        for(a=0; a<n; a++){
            for(b=0; b<m; b++){
                if(field[a][b]==1){
                    qu.push(pair<int, int>(b,a));
                    num[i]++;
                }
                while(!qu.empty()){
                    pair<int, int> cur = qu.front();
                    qu.pop();
                    int x = cur.first;
                    int y = cur.second;
                    
                    if(x >= m || y >=n || x < 0 || y < 0) continue;
                    if(field[y][x] == 1){
                        field[y][x] = 2;
                        qu.push(pair<int, int>(x, y+1));
                        qu.push(pair<int, int>(x, y-1));
                        qu.push(pair<int, int>(x+1, y));
                        qu.push(pair<int, int>(x-1, y));
                    }
                }
            }
        }
    }

    for(i=0; i<t; i++){
        cout << num[i] <<endl;
    }
}