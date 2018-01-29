#pragma once

class SingIn
{
private:
	string password;

public:
	int singInAccount();
	string login;
	string name;
	string surname;
	string accountType;
	string group;

	SingIn();
	~SingIn();
};

