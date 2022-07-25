#include"sm4_optimize.h"
#include<iostream>
#include<thread>
#include<intrin.h>
#include<time.h>
using namespace std;

int main() {
	int ret = 0;
	unsigned char* out = new unsigned char[outlen];
	printf("key:");
	print(key, 16);
	//printf("in:");
	//print(in, outlen);
	int begin = clock();
	uint32_t* key_32;
	byte_swap(key, 16);
	key_32 = (uint32_t*)key;
	make_key(key_32);
	//多线程
	thread thread_list[thread_max];
	int perlen = outlen / thread_max;
	for (int i = 0; i < thread_max; i++)
	{
		int j = i * perlen;
		thread_list[i] = thread(SM4, in + j,perlen , out + j);
	}
	for (int i = 0; i < thread_max; i++)
	{
		thread_list[i].join();
	}
	printf("DIY(优化)_time:\t%.3fs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
	//printf("SM4_DIY_out:");
	//print(out, outlen);
	return 0;
}
