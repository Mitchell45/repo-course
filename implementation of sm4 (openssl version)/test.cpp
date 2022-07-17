#include"sm4.h"

int main() {
  int ret=0;
	unsigned char* out = new unsigned char[outlen];
	printf("key:");
	print(key, 16);
	printf("in:");
	print(in, outlen);
	int begin = clock();
    ret = Ms4_openssl(in, outlen, out);
	printf("openssl_time:\t%.3fs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
	if (1 != ret)
		printf("err!");
	printf("openssl_out:");
	print(out, outlen);
	return 0;
}
