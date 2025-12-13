#include "ProgramUtils/FunctionsUtils.h"

// Fungsi utama
int main(){
    srand(time(0));
    setupDatabase();
    
    Agent activeAgen;
    int menu;
    while (1){
        system(CLEAR);
        showHeaderGame();
        
        // Input validation agar tidak loop error jika input huruf
        if (scanf("%d", &menu) != 1){
            while (getchar() != '\n'); // Bersihkan buffer
            continue;
        }
        while (getchar() != '\n'); // Bersihkan sisa newline

        if (menu == 1){
            if (loginSession(&activeAgen)){
                showIntroStory();
                while (1){
                    system(CLEAR);
                    printf("=========================================\n");
                    printf("AGENT STATUS: ACTIVE\n");
                    printf("CODENAME    : %s\n", activeAgen.namaAgen);
                    printf("REPUTATION  : %d XP\n", activeAgen.skorReputasi);
                    printf("=========================================\n");
                    showMenuOptions("[1] START MISSION: OP. BLACKOUT", "[2] ACCESS LOGS", "[3] LOGOUT");
                    
                    if (scanf("%d", &menu) != 1){
                        while (getchar() != '\n');
                        continue;
                    }
                    while (getchar() != '\n');

                    if (menu == 1)
                        programGame(&activeAgen);
                    else if (menu == 2)
                        viewLogs();
                    else if (menu == 3)
                        break;
                }
            }
        }else if (menu == 2){
            registerNew();
        }else if (menu == 3){
            delayPrint("Terminating connection...", 30);
            break;
        }
    }
    return 0;
}