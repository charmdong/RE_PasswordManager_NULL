#pragma once
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#define WINVER _WIN32_WINNT_WINXP
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define NTDDI_VERSION NTDDI_WINXP
#define MAX_PW_LEN 30
#define PATH "C:\\Documents and Settings\\Eastand\\���� ȭ��\\password.txt"
#define DEFAULT_PW "sejong_security_2018!"
#define TRUE 1
#define FALSE 0

void menu(char *);
void myFlush();
void consoleClear(int);

void changePassword();
bool checkValid(char *);
bool isHaveLetter(char *);
bool isHaveDigit(char *);
bool isHaveCharacter(char *);

void validatePW(char *real);

void transferPW(char *);
bool isFileExist();