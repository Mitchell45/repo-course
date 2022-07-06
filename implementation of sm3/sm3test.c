#include "sm3.h"


int main(int argc, char *argv[])
{
	unsigned char Hash[32]={0};

	char* str="xyz";
	int len;
	len=strlen(str);
	if(!SM3(str, len, Hash))
		printf("str1 has false!");
	char *str2 = "qwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopas";
	len=strlen(str2);
	if(!SM3(str2, len, Hash)){
      printf("str2 has false!");
    }
	return 0;
}
