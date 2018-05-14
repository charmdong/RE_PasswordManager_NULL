#include "Functions.h"
char *menuList[] = { "Sejong Password Manager\n\n", "A. Change Password\n", "B. Validate Password\n", "C. Quit\n\n", "Enter your choice : " };
char *criteriaList[] = { "- it is at least 8 characters long\n","- it contains at least one letter\n","- it contains at least one digit\n","- it contains at least one of these four characters: <, >, _, ?, !\n" };

void menu(char *pw) {
		char choice;
		int i;

		while (1) {
				for (i = 0; i < sizeof(menuList) / sizeof(menuList[0]); i++) {
						printf("%s", menuList[i]);
				}
				scanf(" %c", &choice);
				if (choice >= 'a' && choice <= 'z') // �ҹ��� �Է��ϸ� �빮�ڷ� �ٲٰ� ����
						choice -= 32;
				myFlush();
				consoleClear(500);

				switch (choice) {
				case 'A': changePW(pw); break;
				case 'B': validatePW(pw); break;
				case 'C': quitMenu(pw);
				}
				if (choice == 'C')
						break;
		}
}

void changePW(char *pw) {
		int i;
		char change[MAX_PW_LEN + 1];

		printf("#You should check following criterias to change your PW#\n\n");
		for (i = 0; i < sizeof(criteriaList) / sizeof(criteriaList[0]); i++) {
				printf("%s", criteriaList[i]);
		}
		while (1) {
				printf("\nEnter your new Password to change : ");
				scanf("%s", change);
				myFlush();

				if (checkValid(change)) {
						strcpy(pw, change);
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
bool checkValid(char *pw) {
		return (strlen(pw) >= 8 && isHaveLetter(pw) && isHaveDigit(pw) && isHaveCharacter(pw));
}

// �н����尡 ���ڸ� ���� �ִ��� Ȯ��
bool isHaveLetter(char *pw) {
		int i;
		for (i = 0; i < strlen(pw); i++) {
				if ((pw[i] >= 'a' && pw[i] <= 'z') || (pw[i] >= 'A' && pw[i] <= 'Z'))
						return TRUE;
		}
		return FALSE;
}
// �н����尡 ���ڸ� ���� �ִ��� Ȯ��
bool isHaveDigit(char *pw) {
		int i;
		for (i = 0; i < strlen(pw); i++) {
				if (pw[i] >= '0' && pw[i] <= '9')
						return TRUE;
		}
		return FALSE;
}
// �н����尡 Ư���� 4���� ���ڸ� ���� �ִ��� Ȯ��
bool isHaveCharacter(char *pw) {
		int i;
		for (i = 0; i < strlen(pw); i++) {
				if (pw[i] == '<' || pw[i] == '>' || pw[i] == '_' || pw[i] == '?' || pw[i] == '!')
						return TRUE;
		}
		return FALSE;
}
/*
���� �߿��� �κ��̹Ƿ� �ٰ��� �ܴ밡���� ������ �غ��ô�. �׷� �̸�.
*/
void validatePW(char *pw) {
		char input[MAX_PW_LEN + 1];
		printf("Input your PW to validate : ");
		scanf("%s", input);
		!strcmp(pw, input) ? printf("\n# Validation is completed successfully !#\n") : printf("\n# Validation is failed !#\n");
		consoleClear(3000);
}

void quitMenu(char *pw) {
		FILE *f = fopen(PATH, "w+");
		fprintf(f, "%s", pw);
		fclose(f);
		printf("\n# Exit the Password Manager ! #\n\n");
		Sleep(1500);
}

// �ؽ�Ʈ ���Ͽ��� �н����� �������� �Լ�
void transferPW(char *pw) {
		if (isFileExist()) {
				FILE *f = fopen(PATH, "r");
				fscanf(f, "%s", pw);
				fclose(f);
		}
		else {
				strcpy(pw, DEFAULT_PW);
		}
}
// �н����� ���� ���� Ȯ���ϴ� �Լ�
bool isFileExist() {
		FILE *f = fopen(PATH, "r");
		if (f == NULL) {
				return FALSE;
		}
		fclose(f);
		return TRUE;
}

// ���� ���� �Լ�
void myFlush() {
		while (getchar() != '\n');
}
// �ܼ� â ȭ�� clear �����ִ� �Լ�. ���������� ����ŭ ȭ�� �����ߴٰ� ȭ�� ���� (1000�̸� 1����)
void consoleClear(int time) {
		Sleep(time);
		system("cls");
}