#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


int file_size;
int main() {
	FILE* fptr;
	char buffer[500000];
	char search[100] = "UBOOTVER"; //set search string
	int sea_len = 0;
	int count = 0;
	int i, add_frist = 0;
	fptr = fopen("uboot.bin", "rb");
	fseek(fptr, 0, SEEK_END);
	file_size = ftell(fptr);
	fseek(fptr, SEEK_SET, 0);
	fread(&buffer, file_size, 1, fptr);
	printf("%s\n", buffer);
	while (search[sea_len] != '\0') {
		sea_len++;
	}
	sea_len--;

	for (i = 0; i < file_size; i++) {
		if (count == 7) {
			add_frist = i-7;
			break;
		}
		else {
			if (buffer[i] == search[count]) {
				count++;
				break;
			}
			else
				count = 0;
				
		}
	}
		
		
	
for (i = 0; i < count; i++) {
			printf("%c", buffer[add_frist + i]);
		}








		system("pause");

		return 0;

	}


