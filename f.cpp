#include <iostream>

using namespace std;

int main(){
    long long n;
    int sum = 0, checkSum = 0;
    const int ostat = 1000000;

    cin >> n;
    long long mas[n];
    for (long long i = 0; i < n; i++){
        cin >> mas[i];
        sum += mas[i]%ostat;
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
        checkSum += mas[i]%ostat; 
    }
    if (checkSum != sum){
        cout << "NO";
        return 0;
    }
    //inorder
    for (long long i = 1; i < n; i++){
        if (mas[i] < mas[i-1]){
            cout << "NO";
            return 0;
        }
    }

    checkSum = 0;
    for (long long i = 0; i < n; i++){
        cin >> mas[i];
        checkSum+=mas[i]%ostat;
    }
    if (checkSum != sum){
        cout << "NO";
        return 0;
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