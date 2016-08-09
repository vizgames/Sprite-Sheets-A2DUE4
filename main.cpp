////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// VIZ GAMES ////////////////////////////////////////////////////////
///////////////////////////////// 2016 год. ////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>//std
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;



int intlength(int number) {//считаем сколько знаков у интеджера у 1=1 у 13=2 у 777=3 итд(для нулей 001 002 003...)
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
	cout << "Размер картинки(X): ";
		cin >> imgx;
	cout << "Размер картинки(Y): ";
		cin >> imgy;
	//system("cls");
//===========================
	cout << "число элементов: ";
		cin >> elements;
	width = intlength(elements);//вносим поправки в количество знаков(считаем сколько знаков у инта(elements) используется для того что бы ставить нули 001 002 итд
	//system("cls");
//===========================
	cout << "размер элемента(Ширина): ";
		cin >> elementSizeW;
	cout << "размер элемента(Высота): ";
		cin >> elementSizeH;
	cout << "колонок: ";
		cin >> columns;
	//system("cls");
//===========================
	cout << "имя картинки: ";
		cin >> imgname;
	system("cls");
//===========================	

	ofstream intext(imgname +".paper2dsprites"); // создаем файл для записи

	intext << "{\"frames\": {\n\n"; // запись строки в файл


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

	intext.close(); // закрываем файл

system("pause");
}//void main()