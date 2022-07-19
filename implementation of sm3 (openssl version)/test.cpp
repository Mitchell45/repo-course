#include "openssl_sm3.h"

#include <iostream>
#include "openssl/evp.h"
using namespace std;

int main()
{
	unsigned char hash_value[64];
	unsigned int i, hash_len;
	char test[] = { 0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67,0x01,0x23,0x45,0x67, };
	unsigned int len = sizeof(test);
	sm3_hash(test, len, hash_value, &hash_len);
	printf("plain text:");
	for (i = 0; i < len; i++)
	{
		if (i % 8 == 0)
			printf("\n");
		printf("0x%x  ", test[i]);
	}
	printf("\nhash length: %d bytes.\n", hash_len);
	printf("hash value:\n");
	for (i = 0; i < hash_len; i++)
	{
		if (i % 8 == 0)
			printf("\n");
		printf("0x%x  ", hash_value[i]);
	}
}
