#include<iostream>
#include<time.h>
#include<sm4.h>

int main() {
  int ret=0;
	unsigned char* out = new unsigned char[outlen];
	printf("key:");
	print(key, 16);
	printf("in:");
  print(in, outlen);
	int begin = clock();
	SM4(in, outlen, out);
	printf("DIY_time:\t%.3fs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
  printf("SM4_DIY_out:");
  print(out, outlen);
	return 0;
}
