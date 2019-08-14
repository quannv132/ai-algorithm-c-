/*
*
* DFS / Thuat toan tim kiem sau
* creator: Van Quan, Nguyen
* ::2019
*
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#define MAX 1000
using namespace std;
struct Stack
{
    int top = -1;
    int stack[1000];

    bool isEmpty() {
        return top == -1;
    }

    void push(int element) {
        stack[++top] = element;
    }

    int pop() {
        return stack[top--];
    }
    int peek() {
        return stack[top];
    }

};
void Dfs(int incidenceMatrix[MAX][MAX], int start, int end, int n) {
    Stack mo;
    bool dong[n];
    for (int i = 0; i < n; i++) {
        dong[i] = false;
    }
    mo.push(start);
    dong[start] = true;
    while (!mo.isEmpty()) {
        int s = mo.pop();
        cout << s << " -> ";
        if (s == end) {
            cout << "Has a path" << endl;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (incidenceMatrix[s][j] == 1 && dong[j] == false)
            {
                mo.push(j);
                dong[j] = true;
            }
                
        }
        
    }
    cout << "Not found path" << endl;
    
}
int main() {
    //. A.  B.  C.  D.  E.  F.  G.  H.
    //. 0   1   2   3   4   5   6   7

    ifstream inFile;
    inFile.open("input.txt");

    if (!inFile) {
        cout << "Unable to open file"<< endl;
        exit(1); // terminate with error
    }
    int n; // number of node in graph
    inFile >> n;
    int a[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> a[i][j];
        }
    }
    Dfs(a, 0, 7, n);
    return 0;
}