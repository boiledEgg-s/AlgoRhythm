#include <bits/stdc++.h>
using namespace std;

int main(void){

    int n, m, ans = 0;
    std::cin >> n >> m;
    int broken[m];
    for(int i=0; i<m; i++){
        std::cin >> broken[i]; 
    } 

    int diff = abs(n - 100); //+, -만 눌렀을 때 차이
    int len = std::to_string(n).size();


    if(diff < len){
        ans = diff;
    } else {
        bool isEven = true;
        
        int index = 0;
        int num = n;
        while(true){
            num += (isEven)?index:-index; 
            std::string str = std::to_string(num);
            bool isBreak;
            for(int i=0; i<str.size(); i++){
                for(int j=0; j<m; j++){
                    char btn = '0' + broken[j];
                    //cout << btn << " == "<< str.at(i)<<endl;
                    if(btn == str.at(i)){
                        cout<<"enter " << str <<endl;
                        isBreak = true;
                        break;
                    }
                }
                if(isBreak){
                    break;
                } 
            }
            if(isBreak){
                cout<<"enter"<<endl;
                index++;
            } else {
                ans = abs(n - num) + str.size();
                break;
            }
        }
    }
    std::cout << ans << std::endl;
}