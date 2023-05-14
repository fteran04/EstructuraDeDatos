#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int word(string &cad, map<char,int> &m){
    int ans;
    int i = 0;
    bool flag = true;
    while(i < cad.size() && flag){
        map<char,int>::iterator it = m.find(cad[i]);        
        if(it == m.end()){
            flag = false;
            //cout << 1 << endl;
        }
        else if(it->second > 0){
            it->second -= 1;
            //cout << 2 << endl;
        }
        else{
            flag = false;
            //cout << 3 << endl;
        }
        i++;
    }
    if(flag == true){
        ans = 1;
    }
    else{
        ans = 0;
    }
    return ans;


}
int main(){
    vector<string> vec;
    char c;
    string in;
    map<char,int> m,m2;
    cin >> in;
    while(in != "#"){
        vec.push_back(in);
        cin >> in;
        
    }
    cin.ignore();
    getline(cin,in);
    int i, out;
    while(in != "#"){
        out = 0;
        for(i = 0; i < in.size(); i++){
            if(in[i] != ' '){
                m.insert(pair<char,int>(in[i],0));
                m[in[i]] += 1;
            }
        }
        for(i = 0; i < vec.size(); i++){
            m2.clear();
            m2 = m;
            out += word(vec[i], m2);
            //cout << "*" << endl;
        }
        cout << out << endl;
        m.clear();
        getline(cin,in);
    }


    return 0;
}