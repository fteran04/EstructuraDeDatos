#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<char> keyboard(string &cad){
    deque<char> ans, tmp;
    int i, j, n = cad.size(), flag;
    for(i = 0; i <= n; i++){
        if(cad[i] == '[' || cad[i] == ']' || i == n){
            if(flag == 0){
                for(j = tmp.size()-1; j > -1; j--){
                    ans.push_front(tmp[j]);
                }
            }
            else {
                for(j = 0; j < tmp.size(); j++){
                    ans.push_back(tmp[j]);   
                } 
            }
            tmp.clear();
        }
        if(i < n){
            if(cad[i] == '['){
                flag = 0;
            }
            else if(cad[i] == ']'){
                flag = 1;
            }
            else{
                tmp.push_back(cad[i]);
            }
        }

    }
    return ans;
}

int main(){
    
    string in;
    deque<char> deq;
    int i;
    
    while(cin >> in){
        deq = keyboard(in);
        for(i = 0; i < deq.size(); i++){
            cout << deq[i];
        }
        cout << endl;
    }       
    return 0;
}