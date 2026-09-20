#include <bits/stdc++.h>
using namespace std;

vector<int> LPS_position(string pattern, int pattern_size) 
{
    vector<int> LPS(pattern_size);

    int i = 1, lps = 0;
    LPS[0] = 0;
    while (i < pattern_size) {
        if (pattern[i] == pattern[lps]) {
            lps++;
            LPS[i] = lps;
            i++;
        } else {
            if (lps != 0) 
                lps = LPS[lps - 1];
            else {
                LPS[lps] = 0;
                i++;
            }
        }
    }
    return LPS;
}

queue<int> is_pattern_found (string text, string pattern)
{
    int text_i = 0;
    int pattern_i = 0;
    queue<int> qu_for_return;

    vector<int> LPS = LPS_position(pattern, pattern.size());

    while (text_i < text.size()) {  // If we set this condition like this: text_i will iterate untill 
                                    //text_size-pattern_size+1 th position which is better
        if (text[text_i] == pattern[pattern_i]) {
            text_i++;
            pattern_i++;
        } else {
            if (pattern_i != 0)
                pattern_i = LPS[pattern_i-1];
            else{
                text_i++;
            }
        }
        if (pattern_i == pattern.size()) {
            qu_for_return.push(text_i-pattern_i);//it gives the index of the pattern matching begin in text
            if (pattern_i > 0)
                pattern_i = LPS[pattern_i-1];
        }
    }
    return qu_for_return;
    
}


int main()
{
    string s = "ABABABACDABA";
    string s_sub = "BAC";

    queue<int> qu = is_pattern_found(s, s_sub);

    while (!qu.empty()) {
        cout << qu.front() << endl;
        qu.pop();
    }
}