// ListaZamowien.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SingIn.h"
#include "Admin.h"
#include "User.h"

int main()
{
	int tmp1, x = 0;
	cout << "#########################################" << endl;
	cout << "##         C++ Lista zamowien          ##" << endl;
	cout << "#########################################" << endl << endl;



	cout << "1. Zaloguj sie\n2. Wyjdz\n";
	cin >> tmp1;
	SingIn log;
	while (1) 
	{
		switch (tmp1)
		{
		case 1:
			system("cls");
			if (x == -1)
				cout << "Bledna captcha" << endl;
			x = log.singInAccount();
			
			if (x == 1)
			{
				User user(log);
				user.startPage();
				break;
			}
			else if (x == 2)
			{
				Admin admin(log);
				admin.startPage();
				break;
			}
			break;
		case 2:
			exit(0);
			break;
		default:
			system("cls");

			break;
		}
	}

	return 0;
}

