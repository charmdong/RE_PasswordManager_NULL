#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define WINVER _WIN32_WINNT_WINXP
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define NTDDI_VERSION NTDDI_WINXP
#define MAX_PW_LEN 30
//#define PATH "C:\\Documents and Settings\\Eastand\\πŸ≈¡ »≠∏È\\password.txt"
#define PATH "C:\\Users\\Chung Eastand\\Desktop\\password.txt"
#define DEFAULT_PW "sejong_security_2018!"

typedef enum {false, true} bool;

void menu(char *);
void myFlush();
void consoleClear(int);

void changePW(char *);
bool checkValid(char *);
bool isHaveLetter(char *);
bool isHaveDigit(char *);
bool isHaveCharacter(char *);

void validatePW(char *);

void quitMenu(char *);

void transferPW(char *);
bool isFileExist();