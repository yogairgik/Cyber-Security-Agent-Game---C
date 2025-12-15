#include "../ProgramUtils/FunctionsUtils.h"

 // --- FASE 2: SECONDARY BREACH PROTOCOL ---
int programPhase2(Agent *agent, int *keyCode, int totalPoin){
    char jawaban_str[100];
    int jawaban_int;

    system(CLEAR);
    printf("\033[32m================ [ PHASE 2: SECONDARY BREACH PROTOCOL ] ================\033[0m\n");
    delayPrint("\n\033[32m[COMMAND] Lapisan keamanan kedua terdeteksi. Anda harus melewatinya untuk mendapatkan kode akses.\033[0m\n\n", 30);
    SLEEP(1000);

    printf("[PHASE 2.1] Bypassing 'PANDA' Obfuscation...\n");

    char *kata_asli[] = {"SERVER", "HACKER", "FIREWALL", "DATABASE", "ENCRYPTION", "SPYWARE", "CYBERSPACE", "INJECTION", "BOTNET", "PHISHING"};
    char *kata_panda[] = {"SORVOR", "HOCKOR", "FOROWOLL", "DOTOBOSO", "ONCRYPTOON", "SPYWORO", "CYBORSPOCO", "ONJOCTOON", "BOTNOT", "PHOSHONG"};

    int jumlah_kata = sizeof(kata_asli) / sizeof(kata_asli[0]);
    int randomIndex = rand() % jumlah_kata;

    delayPrint("Sistem menggunakan enkripsi vokal sederhana (semua vokal menjadi 'O').\n", 30);
    printf("Terjemahkan kata berikut: \033[1;33m%s\033[0m\n", kata_panda[randomIndex]);
    printf(">> JAWABAN: ");

    fgets(jawaban_str, sizeof(jawaban_str), stdin);
    jawaban_str[strcspn(jawaban_str, "\n")] = 0;

    if (STR_CMP(jawaban_str, kata_asli[randomIndex]) == 0){
        keyCode[0] = rand() % 10;
        printf(">> Enkripsi ditembus. \033[1;32mKode Fragmen #1: %d\033[0m\n\n", keyCode[0]);
    }else{
        printf(">> JAWABAN SALAH. Aktivitas dicatat.\n");
        return 0;
    }

    SLEEP(800);

    printf("[PHASE 2.2] Cracking 'EULER' Math Lock...\n");
    int a = rand() % 20 + 1;
    int b = rand() % 10 + 1;
    int hasil = a * b;

    delayPrint("Selesaikan persamaan berikut.\n", 30);
    printf("Berapa hasil dari \033[1;33m%d x %d\033[0m?\n", a, b);
    printf(">> JAWABAN: ");
    scanf("%d", &jawaban_int);
    while (getchar() != '\n');

    if (jawaban_int == hasil){
        keyCode[1] = rand() % 10;
        printf(">> Kunci terbuka. \033[1;32mKode Fragmen #2: %d\033[0m\n\n", keyCode[1]);
    }else{
        printf(">> SALAH. Jawaban benar: %d\n", hasil);
        return 0;
    }

    SLEEP(800);

    printf("[PHASE 2.3] Answering 'ORACLE' Security Question...\n");
    delayPrint("Jawab pertanyaan terakhir untuk kode final.\n", 30);

    f = fopen(FILE_SOAL_S2, "r");
    if (!f){
        printf("[ERROR] File soal stage 2 (%s) tidak ditemukan!\n", FILE_SOAL_S2);
        return 0;
    }

    char buff[256], soal_umum[200], jawaban_umum[100];
    int totalBaris = 0;

    while (fgets(buff, sizeof(buff), f))
        totalBaris++;
    rewind(f);

    int target = rand() % totalBaris;
    int index = 0;

    while (fgets(buff, sizeof(buff), f)){
        if (index == target){
            buff[strcspn(buff, "\n")] = 0;
            char *tok = strtok(buff, "|");
            strcpy(soal_umum, tok);
            tok = strtok(NULL, "|");
            strcpy(jawaban_umum, tok);
            break;
        }
        index++;
    }
    fclose(f);

    printf("\033[1;33m%s\033[0m\n", soal_umum);
    printf(">> JAWABAN: ");

    fgets(jawaban_str, sizeof(jawaban_str), stdin);
    jawaban_str[strcspn(jawaban_str, "\n")] = 0;

    if (STR_CMP(jawaban_str, jawaban_umum) == 0){
        keyCode[2] = rand() % 10;
        printf(">> BENAR. \033[1;32mKode Fragmen #3: %d\033[0m\n", keyCode[2]);
    }else{
        printf(">> SALAH. Akses ditolak.\n");
        return 0;
    }

    SLEEP(1200);

    system(CLEAR);
    printf("Enkripsi: 3 Digit Numerik.\n");
    delayPrint("\033[1;32m[COMMAND] Gunakan fragmen kode yang Anda dapatkan untuk masuk misi Tahap terakhir!\033[1;0m\n", 30);

    int input1, input2, input3;

    printf(">> INPUT TOKEN: ");
    printf("\033[1;33m");
    scanf("%d %d %d", &input1, &input2, &input3);
    printf("\033[0m");

    while (getchar() != '\n'); // Clear buffer

    printf("\nMenganalisis kode...\n");
    SLEEP(1000);

    if (input1 == keyCode[0] && input2 == keyCode[1] && input3 == keyCode[2]){
        totalPoin += 100;
        if(!programPhase3(agent, totalPoin)){
        printf("\n>> MISSION FAILED. Koneksi terputus.\n");
        SLEEP(2000);
        return 1;
    }
    }else{
        printf("\n\033[1;31mKode salah! Sistem mengembalikan Anda ke beranda...\033[0m\n");
        return -1; // Kembali ke beranda
    }
}
