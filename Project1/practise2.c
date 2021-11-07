#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>
#include <ctype.h>
char check(char, char);

struct  member
{
	char title[50];
	int x;
	int y;
	char font[15];
	char content[10];
	int rotation;
	int x_mult;
	int y_mult;
	int alignment;
	char temp[10];

};
int char_to_int(char);


int main() {
	struct member list;
	FILE* fpin;
	char buffer[500000];
	char buffer1[500000];
	int file_size;
	int count = 0, i = 0, k = 0;
	int j = 0;
	int num1 = 0,alig=0;
	fpin = fopen("123.txt", "r");
	fseek(fpin, 0, SEEK_END);			//caculate size
	file_size = ftell(fpin);
	fseek(fpin, SEEK_SET, 0);			//return begining
	fread(buffer, file_size, 1, fpin);	//read file
	buffer[file_size - 1] = '\0';
	//printf("%s", buffer);
	while (buffer[i] != '\0') {
		if (buffer[i] == ' ' && count < 6) {// title
			for (j = 0; j < i; j++) {
				list.title[j] = buffer1[j];
			}
			list.title[i] = '\0';
			k = 0;
			i++;
			continue;
		}
		if (buffer[i] == ',') {

			if (count == 0) {			//X
				num1 = atoi(buffer1);
				list.x = num1;

			}
			else if (count == 1) {		//Y
				num1 = atoi(buffer1);
				list.y = num1;
			}
			else if (count == 2) {		//font
				
				for (j = 0; j < k; j++) {
					list.font[j] = buffer1[j];
				}list.font[j] = '\0';
				memset(buffer1,0, k+1);

			}
			else if (count == 3) {		//rotation
				num1 = atoi(buffer1);
				list.rotation = num1;
			}
			else if (count == 4) {		// x_mult
				num1 = atoi(buffer1);
				list.x_mult = num1;
			}
			else if (count == 5) {		//y_mult
				num1 = atoi(buffer1);
				list.y_mult = num1;
			}
			else if (count == 6) {					// if number => aligment
				if (isdigit(buffer1[k - 1])) {		// non number=> content
					num1 = atoi(buffer1);
					list.alignment = num1;
					alig = 1;
					count--;
					
				}
				else {
					
				}
			}
			

			count++;
			k = 0;
			i++;
			continue;
		}
		if (buffer[i] == '\n' && count == 6) {
			for (j = 0; j < k; j++) {
				list.content[j] = buffer1[j];
			}list.content[j] = '\0';
		}

		buffer1[k] = buffer[i];
		i++;
		k++;
	}
	if (alig == 0) {
		printf("%s %d,%d,%s,%d,%d,%d,%s", list.title, list.x, list.y, list.font, list.rotation, list.x_mult, list.y_mult, list.content);

	}else
		printf("%s %d,%d,%s,%d,%d,%d,%d,%s", list.title,list.x,list.y,list.font,list.rotation,list.x_mult,list.y_mult,list.alignment,list.content);

	fclose(fpin);
	return 0;

}



