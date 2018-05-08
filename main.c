#include "Functions.h"

int main()
{
		char pw[MAX_PW_LEN + 1] = "";
		transferPW(pw);
		menu(pw);
		return 0;
}