/*
문제:
    - 그래프가 주어졌을 때, 노드 1과 연결되어있는 노드들의 개수 

접근방법:
    - 이차원 배열을 통해 각 노드 별 연결된 노드들의 리스트를 관리한다.
    - 이후 1부터 bfs를 통해 연결된 노드들의 개수를 세어나간다.
        
회고록:
    - 바로 성공!
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int com[101] = {0 ,};
    vector<int> graph[101];
    int n, pair;
    cin >> n >> pair;

    while((pair--) > 0){
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> qu;
    qu.push(1);
    
    while(!qu.empty()){
        int num = qu.front();
        qu.pop();

        if(com[num] > 0){
            continue;
        } else {
            //cout << "num : "<<num << endl;
            com[num]++;
            ans++;
            for(int i=0; i<graph[num].size(); i++){
                qu.push(graph[num].at(i));
            }                
        }
    }

    cout << ans-1 << endl;

}