#include <iostream>
#include <vector>

using namespace std;

// Hàm quay lui để tìm tất cả các dãy con có tổng bằng targetSum
void backtrack(const vector<int> &nums, int targetSum, int start, vector<int> &path, int currentSum, vector<vector<int>> &result)
{
    // Nếu tổng hiện tại bằng targetSum, thêm dãy con hiện tại vào kết quả
    if (currentSum == targetSum)
    {
        result.push_back(path);
    }

    // Duyệt qua tất cả các phần tử còn lại trong dãy số
    for (int i = start; i < nums.size(); i++)
    {
        // Thêm phần tử hiện tại vào dãy con
        path.push_back(nums[i]);

        // Gọi đệ quy với tổng mới và chỉ số bắt đầu mới
        backtrack(nums, targetSum, i + 1, path, currentSum + nums[i], result);

        // Loại bỏ phần tử cuối cùng khỏi dãy con (bước "quay lui")
        path.pop_back();
    }
}

// Hàm khởi tạo và gọi hàm quay lui
vector<vector<int>> findSubsequences(const vector<int> &nums, int targetSum)
{
    vector<vector<int>> result;                     // Vector để lưu trữ tất cả các dãy con thỏa mãn
    vector<int> path;                               // Vector để lưu trữ dãy con hiện tại
    backtrack(nums, targetSum, 0, path, 0, result); // Gọi hàm quay lui với các tham số ban đầu
    return result;
}

int main()
{
    cout << "Nhập số lượng phần tử của dãy số: ";
    int n;
    cin >> n;

    vector<int> sequence(n);

    cout << "Nhập dãy số:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    cout << "Nhập số nguyên M: ";
    int targetSum;
    cin >> targetSum;

    // Tìm tất cả các dãy con có tổng bằng M
    vector<vector<int>> subsequences = findSubsequences(sequence, targetSum);

    cout << "Các dãy con có tổng bằng " << targetSum << " là:" << endl;
    for (const vector<int> &subseq : subsequences)
    {
        for (int num : subseq)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
