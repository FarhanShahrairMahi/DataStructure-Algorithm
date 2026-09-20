#include <bits/stdc++.h>
using namespace std;

void does_Pattern_Match (string Text, string Pattern) {
    int pattern_size = Pattern.size();
    int text_size = Text.size();

    int MAX = text_size - pattern_size + 1; //up to what point of text we need to search for the first char of the pattern
    int k = 1; //iterator for text, by position 1 upto MAX
    int Index = 0; //position of mathed pattern in text

    while (k <= MAX)
    {
        bool match = true;
        for (int L = 1; L <= pattern_size; L++) {
            if (Pattern[L-1] != Text[k+L-2]) {
                match = false;
                break;
            }
        }
        if (match) {
            Index = k;
            break;
        }
        k++;
    }

    if (Index != 0) {
        cout << "Pattern matched at " << Index << "th position of Text." << endl;
    } else {
        cout << "No Pattern match with Text." << endl;
    }
}

int main()
{
    string s1 = "Farhan Shahriar Mahi", s2 = "Shahriar";
    does_Pattern_Match(s1, s2);
}