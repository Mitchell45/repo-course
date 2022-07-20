#include"transform.h"
#include"sm3_optimize.h"


int main() {
	//测试数据
	string str;
	str = "202000460079mitchell于海涛";
	cout << "string input :" + str << endl << endl;
	string paddingValue = padding(str);
	cout << "after padding:" << endl;
	for (int i = 0; i < paddingValue.size() / 64; i++) {
		for (int j = 0; j < 8; j++) {
			cout << paddingValue.substr(i * 64 + j * 8, 8) << "  ";
		}
		cout << endl;
	}
	cout << endl;
	string result = iteration(paddingValue);
	cout << "hash value:" << endl;
	cout << result.substr(0, 8) << "  ";
	cout << result.substr(1, 8) << "  ";
	cout << result.substr(2, 8) << "  ";
	cout << result.substr(3, 8) << "  ";
	cout << result.substr(4, 8) << "  ";
	cout << result.substr(5, 8) << "  ";
	cout << result.substr(6, 8) << "  ";
	cout << result.substr(7, 8) << "  ";
	/*for (int i = 0; i < 8; i++) {
		cout << result.substr(i * 8, 8) << "  ";
	}*/
	cout << endl << endl;
}
