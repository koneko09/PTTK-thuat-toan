/* Đề bài 1: Xét bài toán đổi tiền xu cho một số tiền có giá trị bằng n xu 
( n nhập từ bàn phím) sao cho số đồng xu đổi ra là nhỏ nhất. Thiết kế một giải thuật tham lam để đổi tiền 
có dùng các đồng xu sau: 5000, 2000, 1000, 500.*/
#include <iostream>
using namespace std;

void nhap(int n, int c[])
{
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap menh gia " << i << ": ";
		cin >> c[i];
	}
}
void sapxep(int n, int c[])
{
	nhap(n, c);
	int tg;
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (c[i] < c[j])
			{
				// Hoan vi 2 so a[i] va a[j]
				tg = c[i];
				c[i] = c[j];
				c[j] = tg;
			}
		}
	}
	cout << "\nMenh gia da sap xep la: \n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << c[i] << "\n";
	}
}
int main()
{
	int c[10];
	int a[10];
	int n;
	int s;
	cout << "Tong so tien N =";
	cin >> s;
	cout << "Nhap so menh gia: ";
	cin >> n;
	sapxep(n, c);
	cout << "Phuong an tra tien la: \n";
	for (int i = 0; i <= n; i++)
	{
		a[i] = s / c[i];
		cout << "\nSo xu " << c[i] << ": " << a[i] << endl;
		s = s % c[i];
		cout << "s = " << s << endl;
	}
}
