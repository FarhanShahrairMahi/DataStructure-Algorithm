//Farhan Shahriar Mahi
//Longest Common Subsequence
#include <iostream>
#include<stack>
using namespace std;

typedef struct node Node;

struct node {
    int item;
    int j_index;
    Node *next;
};

void solve (string s1, string s2)
{
    int row_m = s1.size();
    int col_n = s2.size();

    Node arr[row_m + 1][col_n + 1];

    int row_i = 0;
    int col_j = 0;

    for (col_j = 0; col_j <= col_n; col_j++) {
        arr[row_i][col_j].item = 0;
        arr[row_i][col_j].j_index = col_j;
        arr[row_i][col_j].next = nullptr;
    }
    col_j = 0;
    for (row_i = 0; row_i <= row_m; row_i++) {
        arr[row_i][col_j].item = 0;
        arr[row_i][col_j].j_index = col_j;
        arr[row_i][col_j].next = nullptr;
    }

    for (row_i = 1; row_i <= row_m; row_i++) {
        for (col_j = 1; col_j <= col_n; col_j++) {
            if (s2[col_j-1] == s1[row_i-1]) {
                arr[row_i][col_j].item = arr[row_i-1][col_j-1].item + 1;
                arr[row_i][col_j].j_index = col_j;
                arr[row_i][col_j].next = &arr[row_i-1][col_j-1];
            } else {
                if (arr[row_i-1][col_j].item >= arr[row_i][col_j-1].item) {
                    arr[row_i][col_j].item = arr[row_i-1][col_j].item;
                    arr[row_i][col_j].j_index = col_j;
                    arr[row_i][col_j].next = &arr[row_i-1][col_j];
                } else {
                    arr[row_i][col_j].item = arr[row_i][col_j-1].item;
                    arr[row_i][col_j].j_index = col_j;
                    arr[row_i][col_j].next = &arr[row_i][col_j-1];
                }
            }
        }
    }

    stack<int> st;

    row_i = row_m;
    col_j = col_n;
    int i = 1;
    Node n1, n2, *n3;

    n1 = arr[row_i][col_j];

    if (n1.next != nullptr) {
    n2 = *(n1.next);
    }

    n3 = n2.next;

    while (n3 != nullptr) {
        if (n2.item < n1.item) {
            st.push(n1.j_index);
        }
        n1 = n2;
        i++;
        if (n1.next != nullptr) {
            n2 = *(n1.next);
        }
        n3 = n2.next;
    }

    if (n2.item < n1.item) {
        st.push(n1.j_index);
    }

    while (!st.empty()) {
        cout << s2[st.top()-1] << endl;
        st.pop();
    }

    // We may find other Longest Common Subsequence by first finding the Largest value from array in other places
    // then we can go with the direction and find the subsequences
}

int main()
{
    string s1, s2;
    s1 = "CGATAATTGAGA";
    s2 = "GTTCCTAATA";

    solve(s2, s1);
}