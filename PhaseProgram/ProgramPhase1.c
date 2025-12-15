#include "../ProgramUtils/FunctionsUtils.h"

 // --- FASE 1: SECURITY QUESTION (QUIZ) ---
void programPhase1(Agent *user) {
    f = fopen(FILE_SOAL, "r");
    if (!f)
        return;

    // Variabel Game
    char buff[256], soal[200], kunci[50], jawaban[50];
    int stage2_keyCode[3] = {0};
    int sandi[3], tebakan[3];
    int totalPoin = 0;

    int totalBaris = 0;
    while (fgets(buff, sizeof(buff), f))
        totalBaris++;
    rewind(f);

    int target = rand() % totalBaris;

    // Untuk menampilkan soal dari data txt
    int indexSoal = 0;
    while (fgets(buff, sizeof(buff), f)){
        if (indexSoal == target){
            buff[strcspn(buff, "\n")] = 0;
            char *tok = strtok(buff, "|");
            if (tok) strcpy(soal, tok);
            tok = strtok(NULL, "|");
            if (tok) strcpy(kunci, tok);
            break;
        }
        indexSoal++;
    }
    fclose(f);

    system(CLEAR);
    printf("\033[32m================ [ PHASE 1: SECURITY QUESTION (QUIZ) ] ================\033[0m\n");
    printf("\n\033[1;31m[ALERT] FIREWALL DETECTED: 'CERBERUS v1.0'\033[0m\n");
    printf("Security Protocol Required:\n");
    printf("\033[1;32m");
    delayPrint(soal, 30);
    printf("\033[0m");
    printf("\n");
    printf(">> INPUT BYPASS KEY: ");
    
    // FIXED: Mengganti gets dengan fgets
    fgets(jawaban, sizeof(jawaban), stdin);
    jawaban[strcspn(jawaban, "\n")] = 0;

    if (STR_CMP(jawaban, kunci) != 0){
        delayPrint("\n>> ACCESS DENIED! Intruder Alert Triggered.\n", 30);
        delayPrint("Connection terminated by server.\n", 30);
        SLEEP(2000);
        return;
    }

    printf(">> ACCESS GRANTED. Firewall disabled.\n");
    totalPoin += 50;
    SLEEP(1000);
    
    delayPrint("\n\033[32m[COMMAND] Misi Tahap 1 Selesai. Data berhasil diamankan.\n", 30);
    delayPrint("Tunggu... sepertinya ada lapisan keamanan sekunder!\n", 30);
    delayPrint("Bersiap untuk fase kedua...\033[0m\n\n", 30);
    SLEEP(2000);

    // --- MEMANGGIL STAGE 2 ---
    if (!programPhase2(user, stage2_keyCode, totalPoin)){
        printf("\n>> MISSION FAILED. Koneksi terputus.\n");
        SLEEP(2000);
        return;
    }
    
    SLEEP(1000);
}