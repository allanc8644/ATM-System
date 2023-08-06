#include "Account.h"

bool Account::withdraw(double d) {
	if (d < 0)
		return false;
	else
	{
		balance -= d;
		transactions++;
		return true;
	}
};
