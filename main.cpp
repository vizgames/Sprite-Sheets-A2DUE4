////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// VIZ GAMES ////////////////////////////////////////////////////////
///////////////////////////////// 2016 ���. ////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>//std
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;



int intlength(int number) {//������� ������� ������ � ��������� � 1=1 � 13=2 � 777=3 ���(��� ����� 001 002 003...)
	int result = 0;

	while (number != 0) {
		number /= 10;
		result++;
	}
	return result;
}
//-------------
int WHsize(int count, int WSize, int columns ) {
	int result = 0;
	result = count % columns;
	result = WSize * result;
	return result;
}
int WHsize(int Ycount, int HSize) {
	int result = 0;
	result = HSize * Ycount;
	return result;
}
//-------------


void main(){

	setlocale(LC_ALL, "Russian");

	int elements, elementSizeW, elementSizeH, columns, width, ycount=-1, imgx=0, imgy=0;
	string imgname="";
	const char fill = '0';

//===========================
	cout << "������ ��������(X): ";
		cin >> imgx;
	cout << "������ ��������(Y): ";
		cin >> imgy;
	//system("cls");
//===========================
	cout << "����� ���������: ";
		cin >> elements;
	width = intlength(elements);//������ �������� � ���������� ������(������� ������� ������ � ����(elements) ������������ ��� ���� ��� �� ������� ���� 001 002 ���
	//system("cls");
//===========================
	cout << "������ ��������(������): ";
		cin >> elementSizeW;
	cout << "������ ��������(������): ";
		cin >> elementSizeH;
	cout << "�������: ";
		cin >> columns;
	//system("cls");
//===========================
	cout << "��� ��������: ";
		cin >> imgname;
	system("cls");
//===========================	

	ofstream intext(imgname +".paper2dsprites"); // ������� ���� ��� ������

	intext << "{\"frames\": {\n\n"; // ������ ������ � ����


	for (int i = 0; i < elements; i++)
	{
		if (i%columns == 0) { ycount++; }

		intext << "\"" + imgname + "_";
		intext << std::setw(width) << std::setfill(fill) << i;
		intext << "\":\n";
		
		intext << "{\n";

		intext << "\t\"frame\": {\"x\":" + to_string(WHsize(i, elementSizeW, columns)) + ",\"y\":" + to_string(WHsize(ycount, elementSizeH)) + ",\"w\":" + to_string(elementSizeW) + ",\"h\":" + to_string(elementSizeH) + "},\n";
		intext << "\t\"rotated\": false,\n";
		intext << "\t\"trimmed\": false,\n";
		intext << "\t\"spriteSourceSize\": {\"x\":0,\"y\":0,\"w\":" + to_string(elementSizeW) + ",\"h\":" + to_string(elementSizeH) + "},\n";
		intext << "\t\"sourceSize\": {\"w\":" + to_string(elementSizeW) + ",\"h\":" + to_string(elementSizeH) + "},\n";
		intext << "\t\"pivot\": {\"x\":0.5,\"y\":0.5}\n";

		if (i != elements - 1) 
			{intext << "},\n";}
		else 
			{intext << "}},\n";}
	}

	intext << "\"meta\": {\n\t\"app\": \"vizgames.ru\",\n\t\"version\": \"1.0\",\n\t\"target\": \"paper2d\",\n\t\"image\": \"" + imgname << ".png" << "\",\n\t\"format\": \"RGBA8888\",\n\t\"size\": {\"w\":" + to_string(imgx) << ",\"h\":" + to_string(imgy) << "},";
	intext << "\n\t\"scale\": \"1\",\n\t\"smartupdate\" : \"\"\n}\n}";

	intext.close(); // ��������� ����

system("pause");
}//void main()