#pragma once
#ifndef BMPDATATYPE
#define BMPDATATYPE
#pragma pack(1) //�ڶ���ṹ��ʱ��������һ���ַ�����
//#define WORD unsigned short
//#define DWORD unsigned int
typedef  unsigned short WORD;//2���ֽ�
typedef  unsigned int DWORD;//4���ֽ�

typedef struct {//�ļ�ͷ 14���ֽڴ�С
	WORD    bfType;
	DWORD   bfSize;//�ļ���С(�ֽ�Ϊ��λ)
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfoffBits;//ͼ������������ļ�ͷ��ƫ����
}BITMAPFILEHEADER;

typedef struct {//��Ϣͷ �ܹ�ռ40���ֽ�
	DWORD   biSize;//��Ϣͷ��ռ�ֽ���
	DWORD   biWidth;//���ؿ��
	DWORD   biHeight;//���ظ߶�
	/**
	24λ���ɫ�����ֽ�Ϊһ������
	*/	
	WORD    biPlane;
	WORD    biBitCount;//λ��
	DWORD   biCompression;//ѹ�����ͣ�0Ϊ��ѹ��
	DWORD   biSizeImage;//ͼ�������ֽ�����
	DWORD   biXPelsPerMeter;//ˮƽ����ֱ���(����/��)
	DWORD   biYPelsPerMeter;//��ֱ����ֱ���(����/��)
	DWORD   biClrUsed;//
	DWORD   biClrImportant;
}BITMAPINFOHEADER;

struct RGB_Piont {//����
	unsigned char R;
	unsigned char G;
	unsigned char B;
};


#pragma pack()//�ָ�ȱʡ����



#endif