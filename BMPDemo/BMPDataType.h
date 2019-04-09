#pragma once
#ifndef BMPDATATYPE
#define BMPDATATYPE
#pragma pack(1) //在定义结构体时声明按照一个字符对齐
//#define WORD unsigned short
//#define DWORD unsigned int
typedef  unsigned short WORD;//2个字节
typedef  unsigned int DWORD;//4个字节

typedef struct {//文件头 14个字节大小
	WORD    bfType;
	DWORD   bfSize;//文件大小(字节为单位)
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfoffBits;//图像数据相对于文件头的偏移量
}BITMAPFILEHEADER;

typedef struct {//信息头 总共占40个字节
	DWORD   biSize;//信息头所占字节数
	DWORD   biWidth;//像素宽度
	DWORD   biHeight;//像素高度
	/**
	24位真彩色三个字节为一个像素
	*/	
	WORD    biPlane;
	WORD    biBitCount;//位深
	DWORD   biCompression;//压缩类型，0为不压缩
	DWORD   biSizeImage;//图像数据字节数，
	DWORD   biXPelsPerMeter;//水平方向分辨率(像素/米)
	DWORD   biYPelsPerMeter;//垂直方向分辨率(像素/米)
	DWORD   biClrUsed;//
	DWORD   biClrImportant;
}BITMAPINFOHEADER;

struct RGB_Piont {//像素
	unsigned char R;
	unsigned char G;
	unsigned char B;
};


#pragma pack()//恢复缺省对齐



#endif