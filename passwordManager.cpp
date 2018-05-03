#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#define WINVER _WIN32_WINNT_WINXP
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define NTDDI_VERSION NTDDI_WINXP
#define MAX_PW_LEN 20

char *menuList[] = {"Sejong Password Manager\n\n", "A. Change Password\n", "B. Validate Password\n", "C. Quit\n\n", "Enter your choice : "};
char *criteriaList[] = {"- it is at least 8 characters long\n","- it contains at least one letter\n","- it contains at least one digit\n","- it contains at least one of these four characters: <, >, _, ?, !\n"};

void menu();
void myFlush();
void consoleClear(int);
void changePassword();
bool isHaveLetter(char *);
bool isHaveDigit(char *);
bool isHaveCharacter(char *);
bool checkValid(char *);
bool validatePW(char *real, char *input);

int main()
{
	//char *realPW;
	//���Ͽ��� �н����� ��������. ���� �������� ������ pw default = "sejong_security_2018!"
	menu();
	return 0;
}

void menu(){
	char choice;
	int i;

	while(1){
		for(int i=0; i<sizeof(menuList)/sizeof(menuList[0]); i++){
			printf("%s",menuList[i]);
		}
		scanf(" %c", &choice);
		if(choice >= 'a' && choice <= 'z') // �ҹ��� �Է��ϸ� �빮�ڷ� �ٲٰ� ����
			choice -=32;
		myFlush();
		consoleClear(500);

		switch(choice) {
		case 'A': changePassword();break;
		case 'B': break;
		case 'C': printf("\n# Exit the Password Manager ! #\n\n"); Sleep(1500);
		}
		if(choice == 'C')
			break;
	}
}

void changePassword(){
	int i;
	char change[MAX_PW_LEN+1];

	printf("#You should check following criterias to change your PW#\n\n");
	for(i=0; i<sizeof(criteriaList)/sizeof(criteriaList[0]); i++){
		printf("%s", criteriaList[i]);
	}
	while(1){
		printf("\nEnter your new Password to change : ");
		scanf("%s", change);
		myFlush();

		if(checkValid(change)){
			printf("\n# Changing PW is Completed !#\n\n");
			consoleClear(1500);
			return;
		}
		printf("\n# Changing PW is not Completed !#\n\n");
		consoleClear(1000);
	}
}
/*
�н������ ��밡������ Ȯ���ϴ� �Լ�
*/
bool checkValid(char *pw){
	return (strlen(pw)>=8 && isHaveLetter(pw) && isHaveDigit(pw) && isHaveCharacter(pw));
}

// �н����尡 ���ڸ� ���� �ִ��� Ȯ��
bool isHaveLetter(char *pw){
	int i;
	for(int i=0; i<strlen(pw); i++){
		if((pw[i] >= 'a' && pw[i] <= 'z') || (pw[i] >= 'A' && pw[i] <= 'Z'))
			return true;
	}
	return false;
}
// �н����尡 ���ڸ� ���� �ִ��� Ȯ��
bool isHaveDigit(char *pw){
	int i;
	for(int i=0; i<strlen(pw); i++){
		if(pw[i] >= '0' && pw[i] <='9')
			return true;
	}
	return false;
}
// �н����尡 Ư���� 4���� ���ڸ� ���� �ִ��� Ȯ��
bool isHaveCharacter(char *pw){
	int i;
	for(int i=0; i<strlen(pw); i++){
		if(pw[i] == '<' ||pw[i] == '>' ||pw[i] == '_' ||pw[i] == '?')
			return true;
	}
	return false;
}
/*
���� �߿��� �κ��̹Ƿ� �ٰ��� �ܴ밡���� ������ �غ��ô�. �׷� �̸�.
*/
bool validatePW(char *real, char *input){
	
	return false;
}

// ���� ���� �Լ�
void myFlush(){
	while(getchar() != '\n') ;
}
// �ܼ� â ȭ�� clear �����ִ� �Լ�. ���������� ����ŭ ȭ�� �����ߴٰ� ȭ�� ���� (1000�̸� 1����)
void consoleClear(int time){
	Sleep(time);
	system("cls");
}