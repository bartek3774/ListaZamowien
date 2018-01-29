#include "stdafx.h"
#include "SingIn.h"


int SingIn::singInAccount()
{
	cout << "Zaloguj sie\nLogin:" << endl;
	cin >> login;
	cout << "Haslo" << endl;
	cin >> password;
	int a = 3;
	int b = 5;
	auto r = [](int a)
	{
		time_t czas;
		srand(time(&czas));
		int x = (rand() % a + 1);
		return x;
	};
	auto y = [](int a, int b) 
	{ 
		int x;
		cout << "Podaj sume " << a << " + " << b << endl;
		cin >> x;
		if (x != (a + b))
			return 0;
		else
			return 1;
	};
	if (!y(r(5), r(10)))
	{
		return -1;
	}
	
	ifstream usersFile;
	usersFile.open("users.txt");
	int status = 0;
	string loginTmp, nameTmp, surnameTmp, passwordTmp, accountTypeTmp;
	while (!usersFile.eof())
	{

		usersFile >> loginTmp >> nameTmp >> surnameTmp >> passwordTmp >> accountTypeTmp;
		if ((loginTmp == login && passwordTmp == password))
		{
			name = nameTmp;
			surname = surnameTmp;
			accountType = accountTypeTmp;

			if (accountTypeTmp == "Uzytkownik")
			{
				system("cls");
				cout << "Zalogowano" << endl;
				status = 1;
				usersFile.close();
				return 1;
			}
			else if (accountTypeTmp == "Administrator")
			{
				system("cls");
				cout << "Zalogowano" << endl;
				status = 1;
				usersFile.close();
				return 2;
			}
		}


	}
	if (status != 1)
	{
		system("cls");
	}
	return 0;
}

SingIn::SingIn()
{
}


SingIn::~SingIn()
{
}
