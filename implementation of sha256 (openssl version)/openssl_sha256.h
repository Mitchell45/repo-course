#pragma once
#include <iostream>
#include "openssl/evp.h"
using namespace std;

int sha256(char* plain, size_t len, unsigned char* hash, unsigned int* hash_len)
{
	EVP_MD_CTX* md_ctx;
	const EVP_MD* md;
	md = EVP_sha256();//创建sha256对象
	md_ctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(md_ctx, md, NULL);
	EVP_DigestUpdate(md_ctx, plain, len);
	EVP_DigestFinal_ex(md_ctx, hash, hash_len);
	EVP_MD_CTX_free(md_ctx);
	return 0;
}
