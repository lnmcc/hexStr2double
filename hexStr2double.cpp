#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

double hexStr2double(const unsigned char* hex, const unsigned length) {

	double ret = 0;
	char hexstr[length * 2];
	memset(hexstr, 0, sizeof(hexstr));

	for(unsigned int i = 0; i < length; i++) {
		sprintf(hexstr + i * 2, "%02x", hex[i]);
	}

	sscanf(hexstr, "%llx", (unsigned long long*)&ret);

	return ret;
}

int main() {

	double ret = 0;
	//40 9e 00  00 00 00 00 00 
	unsigned char buffer[8] = {0x40, 0x9e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	ret = hexStr2double(buffer, 8);	
	printf("%f\n", ret);

    //40 89  00 00 00 00 00 00
	ret = 0;
	unsigned char buffer2[8] = {0x40, 0x89, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	ret = hexStr2double(buffer2, 8);	
	printf("%f\n", ret);
}


