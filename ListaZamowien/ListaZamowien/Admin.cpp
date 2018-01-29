#include "stdafx.h"
#include "Admin.h"


Admin::Admin(SingIn log1)
{
	login = log1.login;
	name = log1.name;
	surname = log1.surname;
	group = log1.group;
	accountType = log1.accountType;
}

void Admin::startPage()
{
	cout << "Witaj " << SingIn::login << endl;
	cout << "1. Zarzadzanie uzytkownikami\n2. Dodaj zamowienie\n3. Lista wszystkich zamowien\n4. Lista zamowien uzytkownika\n5. Wyjdz" << endl;
	string x;
	cin >> x;
	if (x == "1")
	{
		system("cls");
		startPage(1);
	}
	else if (x == "2")
	{

	}
	else if (x == "3")
	{

	}
	else if (x == "4")
	{

	}
	else if (x == "5")
	{
		exit(0);
	}
	else
	{
		system("cls");
		startPage();
	}
}

void Admin::startPage(int x)
{
	if (x == 1)
	{
		cout << "1. Lista uzytkownikow\n2. Dodaj uzytkownika\n3. Usun uzytkownika\n4. Wroc" << endl;
		string x2;
		cin >> x2;
		if (x2 == "1")
		{

		}
		else if (x2 == "2")
		{

		}
		else if (x2 == "3")
		{

		}
		else if (x2 == "4")
		{
			system("cls");
			startPage();
		}
		else
		{
			system("cls");
			startPage(1);
		}
	}
}

void Admin::deleteRow(string path, size_t row)
{
	vector < string > vec;
	ifstream in(path.c_str());
	string tmp;
	while (getline(in, tmp)) vec.push_back(tmp);

	in.close();
	ofstream out(path.c_str());
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i + 1 != row) out << vec[i] << endl;

	}
	out.close();
}

Admin::Admin()
{
}


Admin::~Admin()
{
}
