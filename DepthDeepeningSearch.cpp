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
void Dds(int incidenceMatrix[MAX][MAX], int start, int end, int n, int DS) {
    int h = DS;
    Stack sMo;
    Queue qMo;
    int l = 0; // level node
    int level[n];
    for (int i = 0; i < n; i++) {
        level[i] = -1; //init all level node equal -1
    }

    bool dong[n];
    for (int i = 0; i < n; i++) {
        dong[i] = false;
    }

    sMo.push(start);
    level[start] = l;
    dong[start] = true;
    while (!sMo.isEmpty() || !qMo.isEmpty()) {
        int s = sMo.pop();
        if (sMo.isEmpty()) {
            s = qMo.dequeue();
        }

        l = level[s] + 1; //init s level child node 
        
        cout << s << " -> ";
        if (s == end) {
            cout << "Has a path" << endl;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (incidenceMatrix[s][j] == 1 && dong[j] == false)
            {
                if(level[s] >= 0 || level[s] <= DS - 1) {
                    sMo.push(j);
                } else if (level[s] == DS) {
                    qMo.enqueue(j);
                } else if (level[s] == DS + 1) {
                    DS = DS + h;
                    if (h == 1) {
                        qMo.enqueue(j);
                    } else {
                        sMo.push(j);
                    }
                }
                level[j] = l;
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
    int n, DS; // number of node in graph, level of node
    inFile >> n;
    inFile >> DS;
    int a[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inFile >> a[i][j];
        }
    }
    Dds(a, 3, 7, n, DS); // fill the node: start, end 
    return 0;
}