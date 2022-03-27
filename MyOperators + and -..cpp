#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct bigint {
	vector<int> v;
	bigint(long long x) {
		while (x > 0) {  // забиваем в массив цифры чисел
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
	for (int i = 0; i <= b.v.size() - 1; ++i) {
		out << b.v[i];
	}
}
ostream &operator>>(ostream &out, bigint &&b) {
	for (int i = 0; i <= b.v.size() - 1; ++i) {
		out << b.v[i];
	}
}
bigint operator+(bigint &a, bigint &b) {  //оператор + (работает только при положительных числах)
	bigint ans;
	int carry = 0;
	int i = 0;
	for (; i < a.size() && i < b.size(); ++i) {  // само сложение
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
	return ans;  // результат сложения
}
bigint operator-(bigint &a, bigint &b) {  //оператор - (работает только при положительных числах)
	bigint ans;
	int f=0;
	int carry = 0;
	int g=0;
	int z=0;
	int i = 0;
	for (; i < a.size() && i < b.size(); ++i) {  // само вычитание
		int tmp = a.v[i] - b.v[i] - carry;
		if (tmp % 10<0) {
			ans.v.push_back(10-abs(tmp % 10));
			f=1;
		} else {
		}
		carry = tmp / 10;
	}
	for (; i < a.size(); ++i) {
		int tmp = a.v[i] - carry;
		if (i==a.size()-1 && f==1) {  //занимание у первого числа
			if (tmp%10-1!=0){ // проверка на ноль
				ans.v.push_back(tmp % 10-1);
				z=1;
				g=1;
			}
			if (g==1){
				ans.v.push_back(0);
			}
		} else {
			if (tmp%10!=0){ // проверка на ноль
				ans.v.push_back(tmp % 10);
				z=1;
				g=1;
			}
			if (g==1){
				ans.v.push_back(0);
			}
		}
		carry = tmp / 10;
	}
	for (; i < b.size(); ++i) {
		int tmp = b.v[i] - carry;
		carry = tmp / 10;
	}
	if (carry != 0) {
		ans.v.push_back(carry);
	}
	if (z==0){ // Для того чтобы было: ввод 123 123 , вывод 246 0 , а не 000.
		ans.v.push_back(0);
	}
	return ans;  // результат вычитания
}
int main() {
	long long x, y;
	cout << "Введите первое число: ";
	cin >> x;
	cout << "Введите второе число: ";
	cin >> y;
	bigint a(x), b(y);
	cout << a << " " << "+" << " " << b << " " << "=" << " " << a + b << "\n";
	cout << a << " " << "-" << " " << b << " " << "=" << " " << a - b ;
}
