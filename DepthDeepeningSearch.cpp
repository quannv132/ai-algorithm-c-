/*
*
* DDS / Thuat toan tim kiem sau dan
* creator: Van Quan, Nguyen
* ::2019
*
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#define MAX 1000
using namespace std;
struct Queue
{
    int font = -1;
    int rear = -1;
    int queue[1000];

    bool isEmpty() {
        return font == rear;
    }

    void enqueue(int element) {
        queue[++rear] = element;
    }

    int dequeue() {
        return queue[++font];
    }

};

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
void Dds(int incidenceMatrix[MAX][MAX], int start, int end, int n, int h) {
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
    inFile.open("input-dds.txt");

    if (!inFile) {
        cout << "Unable to open file"<< endl;
        exit(1); // terminate with error
    }
    int n, h; // number of node in graph
    inFile >> n;
    inFile >> h;
    int a[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> a[i][j];
        }
    }
    Dds(a, 0, 7, n, h); // fill the node: start, end 
    return 0;
}