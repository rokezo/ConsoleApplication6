#include <iostream>

using namespace std;

int main() {
    int M, N;
    cout << "entter elements A: ";
    cin >> M;
    cout << "enter elenments B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "elements massiv  A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "elememnti massi vva B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    bool* existsInA = new bool[1000];
    bool* existsInB = new bool[1000]; 
    for (int i = 0; i < 1000; i++) {
        existsInA[i] = false;
        existsInB[i] = false;
    }

    for (int i = 0; i < M; i++) {
        existsInA[A[i]] = true;
    }

    for (int i = 0; i < N; i++) {
        existsInB[B[i]] = true;
    }

    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if ((existsInA[i] && !existsInB[i]) || (!existsInA[i] && existsInB[i])) {
            count++;
        }
    }

    int* C = new int[count];
    int j = 0;
    for (int i = 0; i < 1000; i++) {
        if ((existsInA[i] && !existsInB[i]) || (!existsInA[i] && existsInB[i])) {
            C[j++] = i;
        }
    }

    cout << "masiv  C: ";
    for (int i = 0; i < count; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;