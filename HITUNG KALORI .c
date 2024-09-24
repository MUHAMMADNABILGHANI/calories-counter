/*
 NAMA FILE        :HITUNG KALORI.c
 PROGRAMMER       :MUHAMMAD NABIL GHANI(24343063)
 TANGGAL PEMBUATAN:KAMIS/05-09-2024
 DESKRIPSI        :PROGRAM INI MENGHITUNG KEBUTUHAN KALORI
 */
 #include <stdio.h>
    
// Fungsi untuk menghitung BMR berdasarkan rumus Mifflin-St Jeor
float hitungBMR(char jenis_kelamin, float berat, float tinggi, int umur) {
    float bmr;
    if (jenis_kelamin == 'P' || jenis_kelamin == 'p') {
        // Rumus BMR untuk pria
        bmr = 10 * berat + 6.25 * tinggi - 5 * umur + 5;
    } else if (jenis_kelamin == 'W' || jenis_kelamin == 'w') {
        // Rumus BMR untuk wanita
        bmr = 10 * berat + 6.25 * tinggi - 5 * umur - 161;
    } else {
        printf("Jenis kelamin tidak valid. Harus 'W' atau 'P'.\n");
        return -1;
    }
    return bmr;
}

// Fungsi untuk menghitung TDEE berdasarkan faktor aktivitas
float hitungTDEE(float bmr, int faktor_aktivitas) {
    float tdee;
    switch (faktor_aktivitas) {
        case 1: tdee = bmr * 1.375; // Aktivitas ringan
                break;
        case 2: tdee = bmr * 1.55;  // Aktivitas sedang
                break;
        case 3: tdee = bmr * 1.725; // Aktivitas berat
                break;
        default:
            printf("Faktor aktivitas tidak valid. Pilih antara 1 hingga 3.\n");
            return -1;
    }
    return tdee;
}

int main() {
    char jenis_kelamin;
    float berat, tinggi;
    int umur, faktor_aktivitas;
    
    // Input data pengguna
    printf("|=============================================|\n");
 	printf("|PROJECT      : JOBSHEET 2, Tugas 2 C         |\n");
 	printf("|PROGRAMMER   : MUHAMMAD NABIL GHANI          |\n");
 	printf("|NIM          : 24343063                      |\n");
 	printf("|                                             |\n");
 	printf("|     Program Menghitung Kebutuhan Kalori     |\n");
 	printf("|=============================================|\n");
    printf("Masukkan jenis kelamin (P/W): ");
    scanf(" %c", &jenis_kelamin);
    printf("Masukkan berat badan (kg): ");
    scanf("%f", &berat);
    printf("Masukkan tinggi badan (cm): ");
    scanf("%f", &tinggi);
    printf("Masukkan umur (tahun): ");
    scanf("%d", &umur);
    printf("Masukkan faktor aktivitas (1-3):\n");
    printf("1. Aktivitas ringan (olahraga ringan/satu hingga tiga hari per minggu)\n");
    printf("2. Aktivitas sedang (olahraga sedang/empat hingga lima hari per minggu)\n");
    printf("3. Aktivitas berat (olahraga berat/enam hingga tujuh hari per minggu)\n");
    scanf("%d", &faktor_aktivitas);
    
    // Hitung BMR
    float bmr = hitungBMR(jenis_kelamin, berat, tinggi, umur);
    if (bmr < 0) {
        return 1; // Keluar dari program jika input tidak valid
    }
    
    // Hitung TDEE
    float tdee = hitungTDEE(bmr, faktor_aktivitas);
    if (tdee < 0) {
        return 1; // Keluar dari program jika input tidak valid
    }
    
    // Output hasil
    printf("Kebutuhan kalori harian Anda adalah: %.2f kalori\n", tdee);
    
    return 0;
}

