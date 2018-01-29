#include "stdafx.h"
#include "User.h"


User::User(SingIn log)
{
	login = log.login;
	name = log.name;
	surname = log.surname;
	accountType = log.accountType;
	group = log.group;
}

void User::startPage()
{
	cout << "Witaj " << SingIn::name << " " <<  SingIn::surname << endl;
	cout << "1. Lista twoich zamowien\n2. Wyloguj\n3. Wyjdz" << endl;
	string x;
	cin >> x;
	if (x == "1")
	{
		system("cls");
		startPage(SingIn::login);
		startPage();
	}
	else if (x == "2")
	{
		
	}
	else if (x == "3")
	{
		exit(0);
	}
	else
	{
		system("cls");
		startPage();
	}
}

void User::startPage(string id)
{
	printOrder(id);
}

User::User()
{
}


User::~User()
{
}
