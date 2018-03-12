#include<iostream>

using namespace std;

int PowerMod(long long a, long long b, long long c)
{
	long long ans = 1;
	a = a % c;
	while (b>0)
	{

		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans%c;
}

int main()
{
	long long n, m, k, x;
	cin >> n >> m >> k >> x;
	long long ans = PowerMod(10, k, n);
	ans = ((ans*m) % n + x) % n;
	cout << ans;
	return 0;
}