#include "../ProgramUtils/FunctionsUtils.h"

// --- FASE 3: DECRYPTION (LOGIC MASTERMIND) ---
int programPhase3(Agent *user, int totalPoin) {
    int sandi[4], tebakan[4];

    system(CLEAR);
    printf("\033[32m================ [ PHASE 3: DECRYPTION (LOGIC MASTERMIND) ] ================\033[0m\n");
    delayPrint("\n\033[31m[CORE] Encrypted Data Found: 'PROJECT_GENESIS.DAT'\033[0m\n", 30);
    delayPrint("Enkripsi: 4 Digit Numerik Unik.\n", 30);
    delayPrint("Memulai Brute Force Attack...\n", 50);

    // Generate Sandi Unik
    int idx = 0;
    while (idx < 4){
        int n = (rand() % 9) + 1;
        int unik = 1;
        for (int j = 0; j < idx; j++)
            if (sandi[j] == n)
                unik = 0;
        if (unik)
            sandi[idx++] = n;
    }

    int attempt = 8;
    int decrypted = 0;

    printf("Sandi Asli: %d %d %d %d\n", sandi[0], sandi[1], sandi[2], sandi[3]);

    while (attempt > 0){
        printf("\n[Sisa Packet: %d] Masukkan kombinasi (cth: 1 2 3 4): ", attempt);
        if (scanf("%d %d %d %d", &tebakan[0], &tebakan[1], &tebakan[2], &tebakan[3]) != 4){
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        int pas = 0, geser = 0;
        for (int i = 0; i < 4; i++){
            if (tebakan[i] == sandi[i])
                pas++;
            else{
                for (int j = 0; j < 4; j++)
                    if (tebakan[i] == sandi[j])
                        geser++;
            }
        }

        if (pas == 4){
            decrypted = 1;
            break;
        }
        printf("\033[1;33m>> FEEDBACK: %d Angka Tepat | %d Angka Salah Posisi\033[0m\n", pas, geser);
        attempt--;
    }

    if (decrypted){
        printf("\033[1;32m\n==========================================\n");
        delayPrint("   $$$ DECRYPTION SUCCESSFUL $$$          \n", 50);
        delayPrint("   DOWNLOADING ILLEGAL DATA... 100%       \n", 50);
        printf("==========================================\033[0m\n");
        totalPoin += (50 + (attempt * 5));
        user->skorReputasi += totalPoin;

        updateUserScore(user);
        saveLog(user, totalPoin);
        printf("\n--- MISI SELESAI ---\nReputasi Anda meningkat!\n");
        SLEEP(2000);

        system(CLEAR);
        printf("\033[31m[CLEANING TRACE FILES...]\n");
        delayPrint("Menghapus log akses.....\n", 60);
        delayPrint("Mengaburkan alamat IP.....\n", 60);
        delayPrint("Menghapus sidik digital.....\033[0m\n", 60);
        printf("Jejak berhasil dihancurkan.\n");

    }else{
        printf("\n>> DECRYPTION FAILED. Server Lockdown initiated.\n");
        printf("Sandi Asli: %d %d %d %d\n", sandi[0], sandi[1], sandi[2], sandi[3]);
    }

    printf("\nTekan Enter untuk kembali ke markas...");
    getchar();
}