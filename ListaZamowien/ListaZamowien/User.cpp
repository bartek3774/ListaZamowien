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
}

User::User()
{
}


User::~User()
{
}
