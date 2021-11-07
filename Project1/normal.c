#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>


int file_size;
int main() {
	FILE* fptr;
	char buffer[500000];
	int i, add_frist=0, add_end =0;

	fptr = fopen("uboot.bin", "rb");
	fseek(fptr, 0, SEEK_END);
	file_size = ftell(fptr);
	fseek(fptr, SEEK_SET, 0);
	fread(&buffer, file_size, 1, fptr);
	printf("%s\n", buffer);
	for (i = 0; i <= file_size; i++) {
		if (buffer[i] == 'U') {			//UBOOTVER
			add_frist = i;
			i++;
			if (buffer[i] == 'B') {
				i++;
				if (buffer[i] == 'O') {
					i++;
					if (buffer[i] == 'O') {
						i++;
						if (buffer[i] == 'T') {
							i++;
							if (buffer[i] == 'V') {
								i++;
								if (buffer[i] == 'E') {
									i++;
									if (buffer[i] == 'R') {
										i++; 
										for(i = i; i < file_size; i++)
										if (buffer[i] == ',') {
											add_end = i;
										}
									}
								}
							}
						}
					}
				}

			}

		}
		else
		{

		}
	}
	for (i = 0; i <= add_end - add_frist; i++) {
		printf("%c", buffer[add_frist+i]);
	}

	


	system("pause");
	return 0;

}

