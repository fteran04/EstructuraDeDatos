#include <iostream>
#include <deque>

using namespace std;

void rails(int n, deque<int> &d){
    int i;
    deque<int> st;
    deque<int> train;

    for(i = 1; i <= n; i++){
        train.push_back(i);
    }

    for(i = 0; i < d.size(); i++){
        if(st.empty() || st.back() != d[i]){
          if(st.empty()){
            st.push_back(train.front());
            train.pop_front();
          }
            while(st.back() != d[i] && !train.empty() && !st.empty()){
                st.push_back(train.front());
                train.pop_front();
            }
            if(st.back() == d[i]){
                st.pop_back();
            }
        }
        else{
            st.pop_back();
        }
    }
    if(st.empty()){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

int main(){

   int n, i, num;
   bool flag;
   deque<int> d;
   cin >> n;
   while(n != 0){
    cin >> num;
    while(num != 0){
        d.push_back(num);
        for(i = 0; i < n-1; i++){
            cin >> num;
            d.push_back(num);
        }
        rails(n,d);
        d.clear();
        cin >> num;
    }   
    cout << endl; 
    cin >> n;
   }
    return 0;
}