#include <iostream>
#include <vector>
using namespace std;

// Hàm giải bài toán cái túi bằng phương pháp tham lam
int knapsackGreedy(int n, int w, vector<int>& weights, vector<int>& values) {
    vector<int> optimalValues(w + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = w; j >= weights[i]; j--) {
            if (optimalValues[j - weights[i]] + values[i] > optimalValues[j]) {
                optimalValues[j] = optimalValues[j - weights[i]] + values[i];
            }
        }
    }

    return optimalValues[w];
}

int main() {
    int n, w;
    cout << "Nhap so luong do vat n: ";
    cin >> n;

    vector<int> weights(n), values(n);

    cout << "Nhap khoi luong tung do vat:\n";
    for (int i = 0; i < n; i++) {
        cout << "Do vat thu " << i + 1 << ": ";
        cin >> weights[i];
    }
    
    cout << "Nhap gia tri tuong ung cua tung do vat:\n";
    for (int i = 0; i < n; i++) {
        cout << "Do vat thu " << i + 1 << ": ";
        cin >> values[i];
    }

    cout << "Nhap khoi luong toi da cua tui w: ";
    cin >> w;

    int result = knapsackGreedy(n, w, weights, values);

    cout << "Gia tri lon nhat ma tui co the chua duoc la: " << result << endl;

    return 0;
}
