#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct bigint {
	vector<int> v;
	bigint(long long x) {
		while (x > 0) {
			v.push_back(x % 10);
			x /= 10;
		}
	}
	bigint() {
	}
	size_t size() {
		return v.size();
	}
};
ostream &operator<<(ostream &out, bigint &b) {
	for (int i = b.v.size() - 1; i >= 0; --i) {
		out << b.v[i];
	}
}
ostream &operator<<(ostream &out, bigint &&b) {
	for (int i = b.v.size() - 1; i >= 0; --i) {
		out << b.v[i];
	}
}
ostream &operator>>(ostream &out, bigint &b) {
	for (int i = b.v.size() - 1; i >= 0; --i) {
		out << b.v[i];
	}
}
ostream &operator>>(ostream &out, bigint &&b) {
	for (int i = 0; i <= b.v.size() - 1; --i) {
		out << b.v[i];
	}
}
bigint operator+(bigint &a, bigint &b) {
	bigint ans;
	int carry = 0;
	int i = 0;
	for (; i < a.size() && i < b.size(); ++i) {
		int tmp = a.v[i] + b.v[i] + carry;
		ans.v.push_back(tmp % 10);
		carry = tmp / 10;
	}
	for (; i < a.size(); ++i) {
		int tmp = a.v[i] + carry;
		ans.v.push_back(tmp % 10);
		carry = tmp / 10;
	}
	for (; i < b.size(); ++i) {
		int tmp = b.v[i] + carry;
		ans.v.push_back(tmp % 10);
		carry = tmp / 10;
	}
	if (carry != 0) {
		ans.v.push_back(carry);
	}
	return ans;
}
bigint operator-(bigint &a, bigint &b) {
	bigint ans;
	int f=0;
	int carry = 0;	
	int i = 0;
	for (; i < a.size() && i < b.size(); ++i) {
		int tmp = a.v[i] - b.v[i] - carry;
		if (tmp % 10<0) {
			ans.v.push_back(10-abs(tmp % 10));
			f=1;
		} else {
			ans.v.push_back(tmp % 10);
		}
		carry = tmp / 10;
	}
	for (; i < a.size(); ++i) {
		int tmp = a.v[i] - carry;
		if (i==a.size()-1 && f==1) {
			ans.v.push_back(tmp % 10-1);
		} else {
			ans.v.push_back(tmp % 10);
		}
		carry = tmp / 10;
	}
	for (; i < b.size(); ++i) {
		int tmp = b.v[i] - carry;
		ans.v.push_back(tmp % 10);
		carry = tmp / 10;
	}
	if (carry != 0) {
		ans.v.push_back(carry);
	}
	return ans;
}
bigint operator*(bigint &a, bigint &b) {
	bigint ans;
	int carry = 1;
	int i = 0;
	for (; i < a.size() && i < b.size(); ++i) {
		int tmp = a.v[i] * b.v[i] * carry;
		ans.v.push_back(tmp % 10);
		carry = tmp / 10;
	}
	for (; i < a.size(); ++i) {
		int tmp = a.v[i] * carry;
		ans.v.push_back(tmp % 10);
		carry = tmp / 10;
	}
	for (; i < b.size(); ++i) {
		int tmp = b.v[i] * carry;
		ans.v.push_back(tmp % 10);
		carry = tmp / 10;
	}
	if (carry != 0) {
		ans.v.push_back(carry);
	}
	return ans;
}
int main() {
	long long x, y;
	cin >> x >> y;
	bigint a(x), b(y);
	cout << a + b << "\n";
	cout << a - b << "\n";
	cout << a * b << "\n";
}
