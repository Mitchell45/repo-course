#include"transform.h"
#include"sm3.h"


int main() {
	//寻求碰撞的原字符串=我的学号
	string str1;
	str1 = "202000460079";
	cout << "string input :" + str1 << endl << endl;
	string paddingValue1 = padding(str1);
	cout << "after padding:" << endl;
	for (int i = 0; i < paddingValue1.size() / 64; i++) {
		for (int j = 0; j < 8; j++) {
			cout << paddingValue1.substr(i * 64 + j * 8, 8) << "  ";
		}
		cout << endl;
	}
	cout << endl;
	string result1 = iteration(paddingValue1);
	cout << "hash value:" << endl;
	cout << result1.substr(0, 8) << "  ";
	cout << result1.substr(8, 8) << "  ";
	cout << result1.substr(16, 8) << "  ";
	cout << result1.substr(24, 8) << "  ";
	cout << result1.substr(32, 8) << "  ";
	cout << result1.substr(40, 8) << "  ";
	cout << result1.substr(48, 8) << "  ";
	cout << result1.substr(56, 8) << "  ";
	string str2 = "202000460079";
	string result2;
	string paddingValue2;
	double try_num = pow(2,32);
	int rho = 2;
	//开始ρ攻击
	for (double i = 0; i < try_num; i++) {
		str2 = to_string(rho);
		rho = rho * rho + 1;//ρ值递推公式
		paddingValue2 = padding(str2);
		result2 = iteration(paddingValue2);
		if (result1.substr(0, 8) == result2.substr(0, 8) && result1.substr(8, 8) == result2.substr(8, 8)) {
			cout << endl << endl;
			cout << "collision string input :" + str2 << endl << endl;
			cout << "collision hash value:" << endl;
			cout << result2.substr(0, 8) << "  ";
			cout << result2.substr(8, 8) << "  ";
			cout << result2.substr(16, 8) << "  ";
			cout << result2.substr(24, 8) << "  ";
			cout << result2.substr(32, 8) << "  ";
			cout << result2.substr(40, 8) << "  ";
			cout << result2.substr(48, 8) << "  ";
			cout << result2.substr(56, 8) << "  ";
			cout << endl << "finding num in all:  " << i;
			return 0;
		}
	}
	cout << endl << "didn't find collision!";
	return 0;
}
