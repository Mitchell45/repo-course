#include<iostream>
#include <openssl/evp.h>
#include<time.h>

unsigned char key[16] = { 0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,0xfe,0xdc,0xba,0x98 ,0x76,0x54,0x32,0x10 };
uint32_t sub_key[32];//32轮子密钥
unsigned char in[1024000000] = { 0 };
int outlen = sizeof(in) / sizeof(in[0]);//必须是16的倍数



void print(const uint8_t* s, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s%02X%s", (i&15)== 0 ? "\n\t" : " ",
            s[i],
            i == len - 1 ? "\n" : "");
    }
}

int Ms4_openssl(const unsigned char* in, int inlen, unsigned char* _out)
{
    int ret = 0;
    int _updatelen;

    EVP_CIPHER_CTX *evp_cipher_ctx= EVP_CIPHER_CTX_new();
    if (!evp_cipher_ctx) {
        ret = -1;
        return ret;
    }
    //密钥
    ret = EVP_CipherInit(evp_cipher_ctx, EVP_sm4_ecb(), key, NULL, 1);
    if (1 != ret)
        return ret;

    //加密数据
    ret = EVP_CipherUpdate(evp_cipher_ctx, _out, &_updatelen, in, inlen);
    if (1 != ret)
        return 0;
	EVP_CIPHER_CTX_free(evp_cipher_ctx);
    return ret;
}
