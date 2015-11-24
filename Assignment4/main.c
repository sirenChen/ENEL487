#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "crc.h"

bool crcSlowCorrectness (char message[], int nBytes) {
	if (crcSlow(message,nBytes) == CHECK_VALUE)
	{
		printf("%s\n", "the result of crcSlow is ture");
		return true;
	}

	printf("%s\n", "the result of crcSlow is false");
		return false;
}

bool crcFastCorrectness (char message[], int nBytes) {
	crcInit();
	if (crcFast(message,nBytes) == CHECK_VALUE)
	{
		printf("%s\n", "the result of crcFast() is ture");
		return true;
	}

	printf("%s\n", "the result of crcFast() is false");
		return false;
}

int main(void)
{
	float timeSlow, timeFast;
	float temp1, temp2;
	
	/*
	 * Read a file "War and Peace"
	 */
    FILE *fp;
    fp = fopen("test.txt","r");
    
    fseek(fp, 0, SEEK_END);
    long fileLen = ftell(fp);
    
    char *tmp = (char *) malloc(sizeof(char)*fileLen);
    fseek(fp, 0, SEEK_SET);
    fread(tmp, fileLen, sizeof(char), fp);
    fclose(fp);
    

	/*
	 * Measure the performance -- slow
	 */
	
	temp1 = (float)(clock())/CLOCKS_PER_SEC;
	crcSlow(tmp, strlen(tmp));
	temp2 = (float)(clock())/CLOCKS_PER_SEC;
	timeSlow = temp2 - temp1;
	
	printf("timeSlow: %f\n", timeSlow);
	printf("The result of crcSlow() is 0x%X\n", crcSlow(tmp, strlen(tmp)));

	/*
	 * Measure the performance -- fast
	 */
	crcInit();
	temp1 = (float)(clock())/CLOCKS_PER_SEC;
	crcSlow(tmp, strlen(tmp));
	temp2 = (float)(clock())/CLOCKS_PER_SEC;
	timeFast = temp2 - temp1;
	
	printf("timeFast: %f\n", timeFast);
	printf("The result of crcFast() is 0x%X\n", crcFast(tmp, strlen(tmp)));

	/*
	 * Test the corretness
	 */
	crcSlowCorrectness(tmp,strlen(tmp));
	crcSlowCorrectness(tmp,strlen(tmp));
}   /* main() */
