
#include <iostream>

using namespace std;

int main() {
    int M, N;
    cout << "Введите размер массива A: ";
    cin >> M;
    cout << "Введите размер массива B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A: ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B: ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    bool* existsInB = new bool[1000]; 
    for (int i = 0; i < 1000; i++) {
        existsInB[i] = false;
    }

    for (int i = 0; i < N; i++) {
        existsInB[B[i]] = true;
    }

    int count = 0;
    for (int i = 0; i < M; i++) {
        if (!existsInB[A[i]]) {
            count++;
        }
    }

    int* C = new int[count];
    int j = 0;
    for (int i = 0; i < M; i++) {
        if (!existsInB[A[i]]) {
            C[j++] = A[i];
        }
    }

    cout << "Массив C: ";
    for (int i = 0; i < count; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] existsInB;

    return 0;
}