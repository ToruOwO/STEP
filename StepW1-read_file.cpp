//STEP-W1

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#define MAXN 200000
using namespace std;


int main(){


    string c; //the given 16 characters(lowercase alphabets)
    cin >> c;

    if(c.length() != 16) cout << "Please enter excatly 16 characters." << endl;

    else{

        sort(c.begin(), c.end());
    
    pair<string, string> word[MAXN]; //read in the words from dictionary &sort
    string ws, w;
    
    //open file and read in
    
    ifstream dict;
    dict.open("/usr/share/dict/words");
    if(! dict.is_open()) {cout << "Error loading dictionary." << endl;exit(1);}

    int k = 0;
    while(!dict.eof()){
        dict >> w;
        //getline(dict,w);
        ws = w;
        sort(ws.begin(),ws.end());
        word[k].first = ws;
        word[k].second = w;
        k++; //word[MAXN].first = sorted words; word[MAXN].second = originals
    }

    dict.close();
    
    int max = 0; //max. length
    
    vector<string> longest;
    
    for(int i = 0; i < MAXN; i++){ // compare word[i] with string c
        
        if(word[i].first.length() > 16) continue;
        
        int a = 0, b = 0; //position of current alphabets being compared
        bool match = true;
        while(b < word[i].first.length()){
            if(c[a] == word[i].first[b]) {a++;b++;continue;}
            else a++;
            if(a == 16) {match = false; break;}
        }
        if(match) {

            if(word[i].first.length() == max) {
                longest.push_back(word[i].second);
            }

            if(word[i].first.length() > max) {
                max = word[i].first.length();
                longest.clear();
                longest.push_back(word[i].second);
            }
            
        }
        
    }
    
    if (longest.empty()) {
        cout << "impossible" << endl;
    }
    else {
        sort(longest.begin(), longest.end());
        for(int i = 0; i < longest.size(); i++) cout << longest[i] << endl;
    }


    }
    
    return 0;
        
}