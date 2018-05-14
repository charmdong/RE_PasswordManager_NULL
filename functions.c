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
				if (choice >= 'a' && choice <= 'z') // 소문자 입력하면 대문자로 바꾸고 진행
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
패스워드로 사용가능한지 확인하는 함수
*/
bool checkValid(char *pw) {
		return (strlen(pw) >= 8 && isHaveLetter(pw) && isHaveDigit(pw) && isHaveCharacter(pw));
}

// 패스워드가 문자를 갖고 있는지 확인
bool isHaveLetter(char *pw) {
		int i;
		for (i = 0; i < strlen(pw); i++) {
				if ((pw[i] >= 'a' && pw[i] <= 'z') || (pw[i] >= 'A' && pw[i] <= 'Z'))
						return TRUE;
		}
		return FALSE;
}
// 패스워드가 숫자를 갖고 있는지 확인
bool isHaveDigit(char *pw) {
		int i;
		for (i = 0; i < strlen(pw); i++) {
				if (pw[i] >= '0' && pw[i] <= '9')
						return TRUE;
		}
		return FALSE;
}
// 패스워드가 특정한 4개의 문자를 갖고 있는지 확인
bool isHaveCharacter(char *pw) {
		int i;
		for (i = 0; i < strlen(pw); i++) {
				if (pw[i] == '<' || pw[i] == '>' || pw[i] == '_' || pw[i] == '?' || pw[i] == '!')
						return TRUE;
		}
		return FALSE;
}
/*
제일 중요한 부분이므로 다같이 잔대가리를 굴려서 해봅시다. 그럼 이만.
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

// 텍스트 파일에서 패스워드 가져오는 함수
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
// 패스워드 파일 유뮤 확인하는 함수
bool isFileExist() {
		FILE *f = fopen(PATH, "r");
		if (f == NULL) {
				return FALSE;
		}
		fclose(f);
		return TRUE;
}

// 버퍼 비우는 함수
void myFlush() {
		while (getchar() != '\n');
}
// 콘솔 창 화면 clear 시켜주는 함수. 전달인자의 값만큼 화면 정지했다가 화면 비우기 (1000이면 1초임)
void consoleClear(int time) {
		Sleep(time);
		system("cls");
}