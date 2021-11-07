#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>
#include <ctype.h>


#define MAXSIZE 5




typedef struct Queue {
    int front;
    int rear;
    char array[MAXSIZE];

}Queue;

void initQueue(Queue* pq) {
    pq->front = pq->rear = 0;
    int i;
    for (i = 0; i < MAXSIZE; ++i)
    {
        pq->array[i] = 0;
    }
}
struct  member
{
    char title[50];
    int x;
    int y;
    char font[15];
    char content[15];
    int rotation;
    int x_mult;
    int y_mult;
    int alignment;
    char temp[10];

};


int checkQueue(Queue* pq) {
    if ((pq->rear + 1) % MAXSIZE == pq->front) {
        //printf("已滿\n");
        return 1;// full
    }
    else if (pq->rear == pq->front) {
        // printf("空的\n");
        return 0;//empty
    }
    return 2;//normal
}


char EnQueue(Queue* pq, char a) {

    pq->array[pq->rear] = a;
    pq->rear = (pq->rear + 1) % MAXSIZE;
    return a;

}
char GetByte(Queue* pq) {


    char a = pq->array[pq->front];
    pq->front = (pq->front + 1) % MAXSIZE;

    return a;
}

//void readQ(Queue* pq,char a ) {

//    EnQueue(pq, a);

//}


int main() {
    struct member List;
    struct member* list;
    list = &List;
    Queue q, q1;
    FILE* fpin;
    char buffer[500000];
    char buffer1[500000];
    char read;
    int i = 0, flag = 0, k = 0, flag1 = 0;
    int count = 0;
    int j = 0;
    unsigned int file_size;
    int num1 = 0, alig = 0;
 

    fpin = fopen("123.txt", "r");
    fseek(fpin, 0, SEEK_END);			//caculate size
    file_size = ftell(fpin);
    fseek(fpin, SEEK_SET, 0);			//return begining
    memset(buffer, 0, file_size);

    fread(buffer, file_size, 1, fpin);	//read file

    buffer[file_size - 1] = '\0';
    memset(buffer1, 0, file_size);

    initQueue(&q);
    initQueue(&q1);
    EnQueue(&q, buffer[i]);             //載入資料
    while (1) {
        flag = checkQueue(&q);          //check Queue 
        if (flag == 2) {
            buffer1[k] = GetByte(&q);   //取資料
              
            flag1 = 1;                  //資料處理中
        }
        while (flag1 == 1) {                        
            if (buffer1[k] == ' ' && count == 0) {  //檢查 是否到空白以及第一個title
                for (j; j < k; j++) {
                    list->title[j] = buffer1[j];    //輸入到title
                }list->title[j] = '\0';
                memset(buffer1, 0, k);
                k = 0;
                count++;
                break;                              //處裡完跳出
            }
            else if (buffer1[k] == ',') {           //檢查 是否到 ,
                if (count == 1) {                   // 第二個結構成員 
                    num1 = atoi(buffer1);
                    list->x = num1;
                }
                if (count == 2) {                   // 第三個結構成員
                    num1 = atoi(buffer1);
                    list->y = num1;
                }
                if (count == 3) {                   // 第四個結構成員
                    for (j = 0; j < k; j++) {
                        list->font[j] = buffer1[j];
                    }list->font[j] = '\0';
                }
                if (count == 4) {                   // 第五個結構成員
                    num1 = atoi(buffer1);
                    list->rotation = num1;
                } if (count == 5) {                 // 第六個結構成員
                    num1 = atoi(buffer1);
                    list->x_mult = num1;
                } if (count == 6) {                 // 第7個結構成員
                    num1 = atoi(buffer1);
                    list->y_mult = num1;
                } if (count == 7) {                 // 檢查是否有alignment
                    if (isdigit(buffer1[k - 1])) {		// non number=> content
                        num1 = atoi(buffer1);
                        list->alignment = num1;
                        alig = 1;
                        count--;
                    }

                }


            
           

                k = 0;
                count++;
                break;
            } else if (count == 7&&buffer1[k]=='\n') {  //檢查是否為最後字元
                for (j = 0; j < k; j++) {
                    list->content[j] = buffer1[j];      //放入content
                }list->content[j] = '\0';
                k = 0;
                count = 0;
                memset(buffer1, 0, k);
                if (alig == 1) {
                        printf("%s %d,%d,%s,%d,%d,%d,%d,%s\n", list->title, list->x, list->y, list->font, list->rotation, list->x_mult, list->y_mult, list->alignment, list->content);
                        alig = 0;
                }
                   
                else {
                    printf("%s %d,%d,%s,%d,%d,%d,%s\n", list->title, list->x, list->y, list->font, list->rotation, list->x_mult, list->y_mult, list->content);
                }
                    break;
            }

            k++;
            flag1 = 0;      //解完資料
        }

        if (i != file_size) {


           
            i++;
            EnQueue(&q, buffer[i]);         //再次載入資料
        }
        else if (flag ==0 && q.front==q.rear) { // 結束跳出
            break;
        }
        





        
    }





















    printf("\n");
    fclose(fpin);
    system("pause");
    return 0;

}




