// BMPDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS


#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BMPDataType.h"

typedef unsigned char  BYTE;
int main() 
{
	//
	printf("第一次同步提交\n");
	
	FILE *fp;
	if ((fp = fopen("C:\\Users\\Lenovo\\Desktop\\图片2.bmp", "rb")) == NULL)
	{
		printf("Cann't open the file!\n");
		return 1;
	}

	char* buf = NULL;//储存图片
	fseek(fp, 0, SEEK_END);
	int file_size = ftell(fp);
	printf("文件大小：%d", file_size);
	fseek(fp, 0,SEEK_SET);

	buf = (char*)malloc(file_size);
	int ret = fread(buf, sizeof(char), file_size, fp);
	if (ret != file_size) {
		return 2;
	}
	
	BITMAPFILEHEADER* bmpFileHeader_ptr = (BITMAPFILEHEADER *)buf;//指向文件头
	BITMAPINFOHEADER* bmpInfoHeader_ptr = (BITMAPINFOHEADER *)(buf+ sizeof(BITMAPFILEHEADER));//指向信息头
	printf("\n高度：%d 像素", bmpInfoHeader_ptr->biHeight);
	printf("\n宽度：%d 像素", bmpInfoHeader_ptr->biWidth);
	printf("\n位深：%d", bmpInfoHeader_ptr->biBitCount);
	
	int byteNumPrePoint = (bmpInfoHeader_ptr->biBitCount)/8;

	int width = bmpInfoHeader_ptr->biWidth;
	int height = bmpInfoHeader_ptr->biHeight;
	int ZFflag;//标记变量此为图为正图或者是倒图
	if (height > 0) {
		ZFflag = 1;
	}
	else
	{
		ZFflag = 2;
	}
	height = abs(height);
	printf("\n图像头大小：%d", bmpFileHeader_ptr->bfoffBits);

	printf("\n图像数据大小：%d", width*height*byteNumPrePoint);
	printf("\n",(bmpFileHeader_ptr->bfSize - 54) / (width*height * byteNumPrePoint));
	int x, y,t,a = width/2,b = height/2;
	int nw = height * byteNumPrePoint + (4 - (height*byteNumPrePoint) % 4)%4;//旋转后每行的字节数
	int size = nw *width + 54;//
	BYTE* data_body = (BYTE *)malloc(size);//新建保存图像数据的地址空间
	for (int i = 0; i < size; i++) {
		data_body[i] = 0xff;
	}
	BYTE* buf1 = (BYTE*)buf + bmpFileHeader_ptr->bfoffBits;//buf1 指向数据体初始地址处

	
	for (y = 0; y < width; y++) {
		for (x = 0; x < abs(height); x++) {
			for (t = 0; t < byteNumPrePoint; t++)
			{
				*(data_body + (y*nw + x * byteNumPrePoint ) + t) = *(buf1 + (abs(height) - x)*(width * byteNumPrePoint +(4 - (width * byteNumPrePoint)%4)%4) + y * byteNumPrePoint + t);
 			}
		}
	}
	BITMAPFILEHEADER bitmapFileHeader = *(bmpFileHeader_ptr);
	BITMAPINFOHEADER bitmapInfoHeader = *(bmpInfoHeader_ptr);
	FILE *file_buf;
	

	file_buf = fopen("C:\\Users\\Lenovo\\Desktop\\BitMap.bmp", "wb");
	bitmapFileHeader.bfSize = size;
	bitmapInfoHeader.biHeight = width;
	bitmapInfoHeader.biWidth = height;
	
	fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, file_buf);
	fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, file_buf);
	fwrite(data_body,sizeof(BYTE),size, file_buf);
	
	fclose(file_buf);
	free(data_body);
	fclose(fp);
	
	

	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
