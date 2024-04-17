#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>


using namespace std;
struct date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Line_n {
	char name[20];
	char prud[15];
	unsigned short cou;
	float cost;
	struct date date;
};

void p_date(unsigned short day, unsigned short month, unsigned short year, int lien) {
	int w = 10;
	int spac = (lien - w) / 2 - 1;
	cout << left;
	cout.width(spac); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(spac); cout << " ";
}

void c_Tab(struct Line_n* line_n) {
	cout << endl;	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78 + 5);  cout << left << "|Офисные пакеты"; cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Наименование ";
	cout << left << "| Производитель ";
	cout << left << "| Количество сост. частей ";
	cout << left << "| Цена($) ";
	cout << left << " |  Дата релиза ";
	cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < 3; i++) {
		cout << left << "|"; cout.width(14); cout << left << line_n[i].name;
		cout << left << "|"; cout.width(14 + 1); cout << left << line_n[i].prud;
		cout << left << "|"; cout.width(24 + 1); cout << left << line_n[i].cou;
		std::cout.precision(2);
		cout << left << "|"; cout.width(9 + 1); cout << left << fixed << line_n[i].cost;
		cout << left << "|";
		p_date(line_n[i].date.day, line_n[i].date.month, line_n[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78 + 5);  cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
}

void reps(struct Line_n* line_n) {
	int mina = 0;
	int maxa = 0;
	for (int i = 1; i < 3; i++) {
		if (line_n[maxa].date.day + line_n[maxa].date.month * 30 + line_n[maxa].date.year * 365 < line_n[i].date.day + line_n[i].date.month * 30 + line_n[i].date.year * 365) {
			maxa = i;
		}
	}
	for (int i = 1; i < 3; i++) {
		if (line_n[mina].date.day + line_n[mina].date.month * 30 + line_n[mina].date.year * 365 > line_n[i].date.day + line_n[i].date.month * 30 + line_n[i].date.year * 365) {
			mina = i;
		}
	}

	line_n[4] = line_n[mina];
	line_n[mina] = line_n[maxa];
	line_n[maxa] = line_n[4];

}
void Draw(struct Line_n* line_n, int n) {
	cout << endl;	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78 + 5);  cout << left << "|Офисные пакеты"; cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "| Наименование ";
	cout << left << "| Производитель ";
	cout << left << "| Количество сост. частей ";
	cout << left << "| Цена($) ";
	cout << left << " |  Дата релиза ";
	cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < n; i++) {
		cout << left << "|"; cout.width(14); cout << left << line_n[i].name;
		cout << left << "|"; cout.width(14 + 1); cout << left << line_n[i].prud;
		cout << left << "|"; cout.width(24 + 1); cout << left << line_n[i].cou;
		std::cout.precision(2);
		cout << left << "|"; cout.width(9 + 1); cout << left << fixed << line_n[i].cost;
		cout << left << "|";
		p_date(line_n[i].date.day, line_n[i].date.month, line_n[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(78 + 5);  cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Interneta "; cout << "|" << endl;
	cout.width(79 + 5); cout.fill('-'); cout << "-" << endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct Line_n line_n[10];
	line_n[0] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
	line_n[1] = { "SmartSute", "Lotus", 5, 1020.99, {21,10,2012} };
	line_n[2] = { "StarOffice", "Sun", 4, 9.99, {21,10,2020} };

	c_Tab(line_n);

	reps(line_n);

	c_Tab(line_n);
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;


	int n = 3; //kol-vo yach
	Line_n* a;
	a = (Line_n*)calloc(n, sizeof(Line_n));
	for (int i = 0; i < n; i++) {
		strcpy_s(a[i].name, line_n[i].name);
		strcpy_s(a[i].prud, line_n[i].prud);
		a[i].cost = line_n[i].cost;

	}
	Line_n** b;
	b = (Line_n**) new Line_n * [10];
	for (int i = 0; i < 10; i++) {
		b[i] = (Line_n*) new Line_n;
		*(b[i]) = a[i];
	}
	a = (Line_n*)realloc(a, 10 * sizeof(Line_n));
	if (a) {
		for (int i = 0; i < 3; i++) {
			cout << endl << "адрес А[i]" << &a[i] << "A[i] -> name " << a[i].name;
			cout << ", " << "адрес B[i]" << &b[i] << "B[i] -> name " << b[i]->name;
		}
		for (int i = 0; i < 3; i++) {
			cout << endl << "адрес А[i]" << &a[i] << "A[i] -> prod " << a[i].prud;
			cout << ", " << "адрес B[i]" << &b[i] << "B[i] -> prod " << b[i]->prud;
		}
		for (int i = 0; i < 3; i++) {
			cout << endl << "адрес А[i]" << &a[i] << "A[i] -> cost " << a[i].cost;
			cout << ", " << "адрес B[i]" << &b[i] << "B[i] -> cost " << b[i]->cost;
		}
		for (int i = 0; i < 10; i++) {
			delete b[i];
		}
	}
	delete[]b;
	free(a);
	//
	FILE* tFile;
	fopen_s(&tFile, "tFile.txt", "w+");
	for (int i = 0; i < 3; i++) {
		fprintf(tFile, "%s %s %d %f %d %d %d \n", \
			line_n[i].name, \
			line_n[i].prud, \
			line_n[i].cou, \
			line_n[i].cost, \
			line_n[i].date.day, line_n[i].date.month, line_n[i].date.year);
	}
	fclose(tFile);

	fopen_s(&tFile, "tFile.txt", "r");
	struct Line_n readRecords[3];
	for (int i = 0; i < 3; i++) {
		fscanf_s(tFile, "%s", readRecords[i].name, _countof(readRecords[i].name));
		fscanf_s(tFile, "%s", readRecords[i].prud, _countof(readRecords[i].prud));
		fscanf_s(tFile, "%d", &readRecords[i].cou);
		fscanf_s(tFile, "%f", &readRecords[i].cost);
		fscanf_s(tFile, "%d", &readRecords[i].date.day);
		fscanf_s(tFile, "%d", &readRecords[i].date.month);
		fscanf_s(tFile, "%d", &readRecords[i].date.year);
	}
	fclose(tFile);
	Draw(readRecords, 3);

	FILE* bFile;
	fopen_s(&bFile, "bFile.txt", "wb");
	fwrite(line_n, sizeof(line_n), 1, bFile);
	fclose(bFile);

	// 2.	Записать 3 записи(три строки(records) из таблицы практики 0) в файл в бинарном формате.
	fopen_s(&bFile, "bFile.txt", "rb");
	struct Line_n radRecords[3];
	fread_s(radRecords, sizeof(radRecords), sizeof(radRecords), 1, bFile);
	fclose(bFile);
	Draw(radRecords, 3);


	// Этап 2
	// Добавить новую запись (четвертую) в указанный существующий файл, 
	// вводя данные с клавиатуры. Выполнить задание, согласно варианта 
	// в указанном файле, изменения сохраняются в файле. 

	Line_n inRecord;
	inRecord = { "Ofaice", "Micro soft", 8, 122.1, {11,01,2011} };
	char name[17];
	char prud[6];
	unsigned short cou;
	float cost;
	struct date date;
	cout << "Введите назваине:";
	cin >> inRecord.name;
	cout << "Введите кампанию:";
	cin >> inRecord.prud;
	cout << "Введите число:";
	cin >> inRecord.cou;
	cout << "Введите число:";
	cin >> inRecord.cost;
	cout << "Введите дату создания (день):";
	cin >> inRecord.date.day;
	cout << "Введите дату создания (месяц):";
	cin >> inRecord.date.month;
	cout << "Введите дату создания (год):";
	cin >> inRecord.date.year;


	// Записываю запись в файл
	fopen_s(&tFile, "tFile.txt", "a");
	fprintf(tFile, "%s %s %d %f %d %d %d \n", \
		inRecord.name, \
		inRecord.prud, \
		inRecord.cou, \
		inRecord.cost, \
		inRecord.date.day, inRecord.date.month, inRecord.date.year);
	fclose(tFile);

	//Проверка считаю данные из файла
	Line_n fileRecords[4];
	fopen_s(&tFile, "./tFile.txt", "r");
	for (int i = 0; i < 4; i++) {
		fscanf_s(tFile, "%s", fileRecords[i].name, _countof(fileRecords[i].name));
		fscanf_s(tFile, "%s", fileRecords[i].prud, _countof(fileRecords[i].prud));
		fscanf_s(tFile, "%d", &fileRecords[i].cou);
		fscanf_s(tFile, "%f", &fileRecords[i].cost);
		fscanf_s(tFile, "%d", &fileRecords[i].date.day);
		fscanf_s(tFile, "%d", &fileRecords[i].date.month);
		fscanf_s(tFile, "%d", &fileRecords[i].date.year);
	}
	fclose(tFile);
	Draw(fileRecords, 4);













}

