#include "Functions.h"

int main()
{
	char realPw[MAX_PW_LEN+1]="";
	transferPW(realPw);
	menu(realPw);
	return 0;
}