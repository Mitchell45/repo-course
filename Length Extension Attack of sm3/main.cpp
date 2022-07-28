#include"transform.h"
#include"sm3_Length_Extension_Attack.h"

void Length_Extension_Attack(string str1,string str2) {
	cout << "The original message: " << str1 << endl << endl;
	cout << "Extended message: " << str2 << endl << endl;
	string paddingValue1 = padding(str1);//原始消息填充
	string IV = iteration(paddingValue1);//求解出原始消息hash值作为新的IV替代原来的IV
	string paddingValue2 = padding(str2);//扩展消息填充
	string str3 = DecToHex(HexToDec(paddingValue2)+int(paddingValue1.length()));//组装
	string hash1 = Length_Extension_Attack_iteration(str3, IV);
	cout << "Hash Value 1 = " << hash1 << endl << endl;
	string add = "";//填充消息
	for (int i = 0; i < str2.length(); i++) {
		add += "0000";
	}
	string str4 = paddingValue1 + add;//组装
	cout << "password  = " << str4 << endl << endl;
	string hash2 = iteration(str4);
	cout << "Hash Value 2 = " << hash2 << endl << endl;
	if (hash1 == hash2) {
		cout << "Congratulations! You've successfully forged a hash certificate!" << endl << endl;
	}
	else {
		cout << "failed!" << endl << endl;
	}
}

int main() {
	Length_Extension_Attack("The bank password is 888888", "Length Extension Attack");
}
