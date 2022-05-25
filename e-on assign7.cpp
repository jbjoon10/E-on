#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class book
{
private:
	char name[20];
	char title[100];
	char year[10];
	int page;
	char publisher[30];
	char genre[20];

public:
	book()
	{
		int i;
		for (i = 0; i < 20; i++)name[i] = 0;
		for (i = 0; i < 100; i++)title[i] = 0;
		for (i = 0; i < 10; i++)year[i] = 0;
		for (i = 0; i < 30; i++)publisher[i] = 0;
		for (i = 0; i < 20; i++)genre[i] = 0;
		page = 0;
	}

	int check()
	{
		if (page == 0)return 0;
		else return -1;
	}

	void insert()
	{
		if (page == 0)
		{
			cout << "책 제목을 입력해 주세요 : ";
			cin >> title;

			cout << "저자를 입력해 주세요 : ";
			cin >> name;

			cout << "출판연도를 입력해 주세요 : ";
			cin >> year;

			cout << "출판사명을 입력해 주세요 : ";
			cin >> publisher;

			cout << "장르를 입력해 주세요 : ";
			cin >> genre;
		}
		else
		{
			cout << "이미 저장된 책이 있습니다." << endl;
		}

		page = 1;
	}

	void del()
	{
		if (page != 0)
		{
			int i;
			for (i = 0; i < 20; i++)name[i] = 0;
			for (i = 0; i < 100; i++)title[i] = 0;
			for (i = 0; i < 10; i++)year[i] = 0;
			for (i = 0; i < 30; i++)publisher[i] = 0;
			for (i = 0; i < 20; i++)genre[i] = 0;

			page = 0;
		}
		else cout << "저장된 책이 없습니다." << endl;
	}

	void modify()
	{
		if (page != 0)
		{
			cout << "책 제목을 입력해 주세요 : ";
			cin >> title;

			cout << "저자를 입력해 주세요 : ";
			cin >> name;

			cout << "출판연도를 입력해 주세요 : ";
			cin >> page;

			cout << "출판사명을 입력해 주세요 : ";
			cin >> publisher;

			cout << "장르를 입력해 주세요 : ";
			cin >> genre;
		}
		else cout << "저장된 책이 없습니다." << endl;
	}

	void print()
	{
		if (page != 0)
		{

			cout << "책 제목 : " << title << endl;
			cout << "저자 : " << name << endl;
			cout << "출판연도 : " << year << endl;
			cout << "출판사명 : " << publisher << endl;
			cout << "장르 : " << genre << endl;
		}
	}

	int Search(int user_input, char* user_search)
	{
		int isRight;	//true = 0, false != 0

		switch (user_input)
		{
		case 1:
			isRight = strcmp(title, user_search);
			break;
		case 2:
			isRight = strcmp(name, user_search);
			break;
		case 3:
			isRight = strcmp(year, user_search);
			break;
		case 4:
			isRight = strcmp(publisher, user_search);
			break;
		case 5:
			isRight = strcmp(genre, user_search);
			break;
		default:
			printf("검색하신 책이 없습니다.\n");
			break;
		}

		return isRight;
	}

	void Save(FILE* file)
	{
		fputs(title, file);
		fputs(" ", file);
		fputs(name, file);
		fputs(" ", file);
		fputs(year, file);
		fputs(" ", file);
		fputs(publisher, file);
		fputs(" ", file);
		fputs(genre, file);
		fputs("\n", file);
	}

	void SavePage(int a)
	{
		page = a;
	}
	void Saveontitle(const char* str)
	{
		strcpy(title, str);
	}
	void Saveonname(const char* str)
	{
		strcpy(name, str);
	}
	void Saveonyear(const char* str)
	{
		strcpy(year, str);
	}
	void Saveonpublisher(const char* str)
	{
		strcpy(publisher, str);
	}
	void Saveongenre(const char* str)
	{
		strcpy(genre, str);
	}

};


void Savelibrary(book* bk)
{
	FILE* file = fopen("input.txt", "w");
	for (int i = 0; i < 10; i++)
	{
		bk[i].Save(file);
	}
}

void LoadOnList(book* arr, int* bookNum)
{
	ifstream inputfile("input.txt");
	if (!inputfile)
	{
		cout << "파일 찾지 못함" << endl;
		return;
	}

	int i = 0;
	string line;
	while (getline(inputfile, line))
	{
		string name, author, pubname, genre;
		string pubyear;


		int index = 0;
		int leng = line.length();


		//name 할당 
		while (line[index] != ' ')
		{
			name.push_back(line[index]);
			index++;
		}
		index++;

		//author 할당 
		while (line[index] != ' ')
		{
			author.push_back(line[index]);
			index++;
		}
		index++;

		//pubyear 할당 
		while (line[index] != ' ')
		{
			pubyear.push_back(line[index]);
			index++;
		}
		index++;

		//pubname 할당 
		while (line[index] != ' ')
		{
			pubname.push_back(line[index]);
			index++;
		}
		index++;

		//genre 할당 
		while (index < (int)line.length())
		{
			genre.push_back(line[index]);
			index++;
		}

		arr[i].Saveontitle(name.c_str());
		arr[i].Saveonname(author.c_str());
		arr[i].Saveonyear(pubyear.c_str());
		arr[i].Saveonpublisher(pubname.c_str());
		arr[i].Saveongenre(genre.c_str());

		arr[i].SavePage(1);
		i++;
	}

	

	*bookNum = i+1;
	inputfile.close();
}


int search_book(book* book_list, int num_total)
{ //먼저 어떤 기능으로 찾을지 확인 후 문자열 비교 함수를 이용해서 검색
	int user_input;
	char user_search[30];

	printf("어떤 기능으로 검색하시겠습니까 : \n");
	printf("1. 책제목 검색 \n");
	printf("2. 저자명 검색 \n");
	printf("3. 출판년도 검색 \n");
	printf("4. 출판사명 검색 \n");
	printf("5. 장르 검색 \n");
	scanf("%d", &user_input);

	printf("검색어를 입력해주세요 : ");
	scanf("%s", user_search);

	for (int i = 0; i < 10; i++)
	{
		if (book_list[i].check() == 0)
			break;

		int isRight = book_list[i].Search(user_input, user_search);		////true = 0, false != 0
		if (isRight == 0)
			book_list[i].print();
	}

	printf("검색 결과 \n");


	return 0;
}


void main()
{
	book bk[10];
	int cmd;
	int index = 0;
	int book_num_total = 0;

	LoadOnList(bk, &book_num_total);

	while (1)
	{
		cout << "입력[0] 삭제[1] 수정[2] 출력[3] 검색[4] 종료[-1] : ";
		cin >> cmd;
		if (cmd == 0)
		{
			int insert_index;
			for (insert_index = 0; insert_index < index; insert_index++)
			{
				if (bk[insert_index].check() == 0)
				{
					bk[insert_index].insert();
					break;
				}
			}
			if (insert_index == index)bk[index++].insert();

			book_num_total++;
		}
		else if (cmd == 1)
		{
			int del_index;
			cout << "삭제할 책의 index를 입력해 주세요 : ";
			cin >> del_index;
			bk[del_index].del();
		}
		else if (cmd == 2)
		{
			int modi_index;
			cout << "수정할 책의 index를 입력해 주세요 : ";
			cin >> modi_index;
			bk[modi_index].modify();
		}
		else if (cmd == 3)
		{
			int i;
			for (i = 0; i < book_num_total; i++)bk[i].print();
		}

		else if (cmd == 4)
		{
			search_book(bk, book_num_total);
		}

		else if (cmd == -1)
		{
			break;
		}
	}
}
