#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Konstanta FILE
#define FILE_AKUN "FileData/FileAgentData.txt"
#define FILE_SOAL "FileData/FileQuestionsPhase1.txt"
#define FILE_SOAL_S2 "FileData/FileQuestionsPhase2.txt"
#define FILE_LOG "FileData/FileHackLog.txt"
#define MAX_STR 100
FILE *f;

// Konstanta macro
#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#define CLEAR "cls"
#define STR_CMP _stricmp
#else
#include <unistd.h>
#include <strings.h>
#define SLEEP(ms) usleep(ms * 1000)
#define CLEAR "clear"
#define STR_CMP strcasecmp
#endif

// Struct agent
typedef struct
{
    char id[20];
    char namaAgen[50];
    char pass[20];
    int skorReputasi;
} Agent;

/* -------------------- [START - BAGIAN-BAGIAN FUNGSI] ---------------------------------*/
// Fungsi Untuk Tampilan Header
void showMenuOptions(char menu1[255], char menu2[255], char menu3[255]);
void showHeaderGame();
void showIntroStory();

// Fungsi Untuk Visualisasi
void delayPrint(char *str, int speed);
void loadingBar(char *text);

// Fungsi Untuk Autentikasi
void setupDatabase();
int loginSession(Agent *user);
void registerNew();
void saveLog(Agent *user, int skor);
void updateUserScore(Agent *user);
void viewLogs();

// Fungsi Untuk Program Game
void programPhase1(Agent *user);
int programPhase2(Agent *agent, int *keyCode, int totalPoin);
int programPhase3(Agent *agent, int totalPoin);
void programGame(Agent *user);
/* -------------------- [END - BAGIAN-BAGIAN FUNGSI] ---------------------------------*/
#endif
