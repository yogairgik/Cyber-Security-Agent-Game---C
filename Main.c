#include "ProgramUtils/FunctionsUtils.h"

// Fungsi utama
int main(){
    srand(time(0));
    Agent activeAgen;
    int menu;
    
    while (1){
        system(CLEAR);
        showHeaderGame();
        
        // Input validation agar tidak loop error jika input huruf
        if (scanf("%d", &menu) != 1){
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (menu == 1){
            if (loginSession(&activeAgen)){
                showIntroStory();
                while (1){
                    system(CLEAR);
                    printf("\033[32m=========================================\n");
                    printf("AGENT STATUS: ACTIVE\n");
                    printf("CODENAME    : %s\n", activeAgen.namaAgen);
                    printf("REPUTATION  : %d XP\n", activeAgen.skorReputasi);
                    printf("=========================================\033[0m\n");
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
            Sleep((1000));
            system(CLEAR);
            break;
        }
    }
    return 0;
}