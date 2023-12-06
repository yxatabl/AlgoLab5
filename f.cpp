#include <iostream>

using namespace std;

int main(){
    long long n;

    cin >> n;
    long long mas[n];
    for (long long i = 0; i < n; i++){
        cin >> mas[i];
    }

    //preorder
    for (long long i = 0; i < n-1; i++){
        long long j = i+1;
        while (mas[j] < mas[i] && j < n) j++;
        while (mas[j] >= mas[i] && j < n) j++;
        if (j != n){
            cout << "NO";
            return 0;
        }
    }

    for (long long i = 0; i < n; i++){
        cin >> mas[i];
    }
    //inorder
    for (long long i = 1; i < n; i++){
        if (mas[i] < mas[i-1]){
            cout << "NO";
            return 0;
        }
    }

    for (long long i = 0; i < n; i++){
        cin >> mas[i];
    }
    //postorder
    for (long long i = n-1; i >= 1; i--){
        long long j = i-1;
        while (mas[j] >= mas[i] && j >= 0) j--;
        while (mas[j] < mas[i] && j >= 0) j--;
        if (j != -1){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}