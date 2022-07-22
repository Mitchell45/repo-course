#include"transform.h"
#include"sm3.h"


int main() {
	//记录寻找碰撞的次数
	int num = 0;
	//字典
	string dict = "0123456789";
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
	//开始生日攻击
	for (int i0 = 0; i0 < 10; i0++) {
		str2[0] = dict[i0];
		for (int i1 = 0; i1 < 10; i1++) {
			str2[1] = dict[i1];
			for (int i2 = 0; i2 < 10; i2++) {
				str2[2] = dict[i2];
				for (int i3 = 0; i3 < 10; i3++) {
					str2[3] = dict[i3];
					for (int i4 = 0; i4 < 10; i4++) {
						str2[4] = dict[i4];
						for (int i5 = 0; i5 < 10; i5++) {
							str2[5] = dict[i5];
							for (int i6 = 0; i6 < 10; i6++) {
								str2[6] = dict[i6];
								for (int i7 = 0; i7 < 10; i7++) {
									str2[7] = dict[i7];
									for (int i8 = 0; i8 < 10; i8++) {
										str2[8] = dict[i8];
										for (int i9 = 0; i9 < 10; i9++) {
											str2[9] = dict[i9];
											for (int i10 = 0; i10 < 10; i10++) {
												str2[10] = dict[i10];
												for (int i11 = 0; i11 < 10; i11++) {
													str2[11] = dict[i11];
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
														cout << endl << "finding num in all:  " << num;
														return 0;
													}
													
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
