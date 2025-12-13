#include "FunctionsUtils.h"

// Bagian header
void showMenuOptions(char menu1[255], char menu2[255], char menu3[255]){
    printf("%s\n%s\n%s\n>> COMMAND: ", menu1, menu2, menu3);
}

void showHeaderGame(){
    printf("\033[31m");
    printf("===============================================\n");
    printf("   _____  __     __  ____    ______   _____  \n");
    printf("  / ____| \\ \\   / / |  _ \\  |  ____| |  __ \\ \n");
    printf(" | |       \\ \\_/ /  | |_) | | |__    | |__) |\n");
    printf(" | |        \\   /   |  _ <  |  __|   |  _  / \n");
    printf(" | |____     | |    | |_) | | |____  | | \\ \\ \n");
    printf("  \\_____|    |_|    |____/  |______| |_|  \\_\\\n"); // FIXED: Double backslash
    printf("                                              \n");
    printf("        GARUDA CYBER DEFENSE TERMINAL         \n");
    printf("================================================\n");
    printf("\033[0m");
    showMenuOptions("[1] LOGIN AGENT", "[2] REGISTRATION AGENT", "[3] DISCONNECT");
}

// Bagian story game
void showIntroStory(){
    system(CLEAR);
    delayPrint("ESTABLISHING SECURE CONNECTION...", 30);
    SLEEP(500);
    printf(" OK.\n");
    delayPrint("ENCRYPTING DATA STREAM...", 30);
    SLEEP(500);
    printf(" OK.\n\n");

    printf("\033[32m");
    printf("================ [ INCOMING TRANSMISSION ] ================\n");
    SLEEP(1000);
    delayPrint("FROM: COMMANDER X\n", 50);
    delayPrint("TO  : FIELD AGENT\n\n", 50);

    delayPrint("Selamat datang, Agen. Kami mendeteksi aktivitas ilegal\n", 30);
    delayPrint("dari korporasi 'SYNTHESIS CORP'. Mereka diduga mencuri\n", 30);
    delayPrint("data biometrik jutaan warga sipil.\n\n", 30);

    delayPrint("Misi Anda adalah membobol Mainframe Server mereka,\n", 30);
    delayPrint("mengambil bukti data, dan menghancurkan jejak.\n", 30);
    delayPrint("Hati-hati. Keamanan mereka berlapis.\n", 30);
    printf("===========================================================\n");

    printf("\nTekan Enter untuk menerima misi...");
    printf("\033[0m");
    getchar();
}


// Bagian menampilkan data-data agen yang telah bermain
void viewLogs()
{
    f = fopen(FILE_LOG, "r");
    char line[256], agent[100], id[50], status[100];
    int score, no = 1;
    system(CLEAR);
    printf("\033[32m================ [ ENCRYPTED MISSION LOGS ] ================\033[0m\n");
    if (f){
        printf("==================================================\n");
        printf("|NO|      AGENT      |     STATUS      |  SCORE  |\n");
        printf("==================================================\n");

        while (fgets(line, sizeof(line), f)){
            if (sscanf(line, "AGENT %[^[] [%[^]]] | %[^|] | SCORE: %d",agent, id, status, &score) == 4){
                printf("|%2d| %-15s | %-14s | %6d |\n", no++, agent, status, score);
            }
        }

        printf("==================================================\n");
        fclose(f);
    }else{
        printf("[!] No mission data found.\n");
    }
    printf("\n[Enter] to return...");
    getchar();
}

// Bagian program game
void programGame(Agent *user){
    system(CLEAR);
    printf("TARGET: SYNTHESIS CORP MAIN SERVER (IP: 192.168.X.X)\n");
    loadingBar("Scanning Ports");
    SLEEP(1000);

    programPhase1(user);
}