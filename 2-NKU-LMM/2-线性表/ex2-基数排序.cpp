#include<iostream>
#include<cstring>
using namespace std;

int b[10][100];
int Digit(int num) {
    int k = 0;
    while (num != 0) {
        num = num / 10;
        k++;
    }
    return k;
}

void print(int a[], int len) {
    for (int i = 0; i < len - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[len - 1];
}

int main() {
    int maxNum = 0;
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > maxNum)
            maxNum = a[i];
    }

    int k = Digit(maxNum);
    int num;
    int y = 1;
    for (int i = 0; i < k; i++) {
        memset(b, 0, sizeof(b));
        for (int j = 0; j < n; j++) {
            num = a[j] / y % 10;
            b[num][++b[num][0]] = a[j];
        }

        int a_len = 0;
        for (int u = 0; u <= 9; u++) {
            for (int p = 1; p <= b[u][0]; p++) {
                a[a_len++] = b[u][p];
            }
        }

        print(a, n);
        if (i != k - 1)cout << endl;
        y *= 10;
    }
    delete a;
}