   #include <iostream>
   #include <cstdlib>
   #include <time.h>
   #include <fstream>

using namespace std;

//static int labirynt[15][15];
//static int y = 15, x = 15;


static int labirynt[24][35];
static int y = 24, x = 35;

void tworzenie_mapy(int miara_x, int miara_y, int licznik, int *wejscia);
int pola_specjalne(int miara_x, int miara_y, int *wejscia);



int main()
{
        int wejscia[100][3], *poczatek_tablicy_wyjscia = &wejscia[0][0];
        for (int i = 0 ; i < 300 ; i++) *poczatek_tablicy_wyjscia++ = 0;    // czyszczenie tablicy wyjsc

        tworzenie_mapy(x, y, x * y - pola_specjalne(x, y, &wejscia[0][0]), &wejscia[0][0]);
    //	tworzenie_mapy(x, y, x * y - 1, &wejscia[0][0]);
}


int pola_specjalne(int miara_x, int miara_y, int *wejscia)
{
    int mniej_pol_o = 1;
    srand(time(NULL)) ;
    int pozycja_x, pozycja_y, *pole, licznik_wejsc = 0, suma_pol;


    /****************  KAPLICA ********************/
    do {
        pozycja_x = rand() % (miara_x - 4);     // losowanie polozenia
        pozycja_y = rand() % (miara_y - 6);
        suma_pol = labirynt[pozycja_y][pozycja_x + 1] + labirynt[pozycja_y][pozycja_x + 2] + labirynt[pozycja_y][pozycja_x + 3] +
        labirynt[pozycja_y + 1][pozycja_x] + labirynt[pozycja_y + 1][pozycja_x + 1] + labirynt[pozycja_y + 1][pozycja_x + 2] +
        labirynt[pozycja_y + 1][pozycja_x + 3] + labirynt[pozycja_y + 1][pozycja_x + 4] + labirynt[pozycja_y + 2][pozycja_x] +
        labirynt[pozycja_y + 2][pozycja_x + 1] + labirynt[pozycja_y + 2][pozycja_x + 2] + labirynt[pozycja_y + 2][pozycja_x + 3] +
        labirynt[pozycja_y + 2][pozycja_x + 4] + labirynt[pozycja_y + 3][pozycja_x + 1] + labirynt[pozycja_y + 3][pozycja_x + 2] +
        labirynt[pozycja_y + 3][pozycja_x + 3] + labirynt[pozycja_y + 4][pozycja_x + 1] + labirynt[pozycja_y + 4][pozycja_x + 2] +
        labirynt[pozycja_y + 4][pozycja_x + 3] + labirynt[pozycja_y + 5][pozycja_x + 1] + labirynt[pozycja_y + 5][pozycja_x + 2] +
        labirynt[pozycja_y + 5][pozycja_x + 3] + labirynt[pozycja_y + 6][pozycja_x + 2];
    } while (!(pozycja_x + pozycja_y)          // czy nie zaczyna sie od wejscia
    || suma_pol);                               // czy nie ma nic w miejscu wyjscia

    pole = &labirynt[pozycja_y    ][pozycja_x + 1];               *pole++ = 45; *pole++ = 95; *pole = 46; // rysunek
    pole = &labirynt[pozycja_y + 1][pozycja_x    ]; *pole++ = 45; *pole++ = 64; *pole++ = 62; *pole++ = 63; *pole = 46;
    pole = &labirynt[pozycja_y + 2][pozycja_x    ]; *pole++ = 47; *pole++ = 66; *pole++ = 61; *pole++ = 65; *pole = 48;
    pole = &labirynt[pozycja_y + 3][pozycja_x + 1];               *pole++ = 54; *pole++ = 61; *pole = 53;
    pole = &labirynt[pozycja_y + 4][pozycja_x + 1];               *pole++ = 54; *pole++ = 61; *pole = 53;
    pole = &labirynt[pozycja_y + 5][pozycja_x + 1];               *pole++ = 58; *pole++ = 94; *pole = 60;
    labirynt[pozycja_y + 6][pozycja_x + 2] = 256; // tymczasowe zaznaczenie wyjscia
    *wejscia++ = pozycja_y + 6; *wejscia++ = pozycja_x + 2; *wejscia++ = 1; // otawrcie komnaty po budowie labiryntu
    mniej_pol_o += 22;   // skrocenie labiryntu o dana ilosc pol

    /**************** PANTEON ********************/
        do {
            pozycja_x = rand() % (miara_x - 4);     // losowanie polozenia
            pozycja_y = (rand() % (miara_y - 5)) + 1;
            suma_pol = labirynt[pozycja_y][pozycja_x + 1] + labirynt[pozycja_y][pozycja_x + 2] + labirynt[pozycja_y][pozycja_x + 3] +
            labirynt[pozycja_y + 1][pozycja_x] + labirynt[pozycja_y + 1][pozycja_x + 1] + labirynt[pozycja_y + 1][pozycja_x + 2] + labirynt[pozycja_y + 1][pozycja_x + 3] + labirynt[pozycja_y + 1][pozycja_x + 4] +
            labirynt[pozycja_y + 2][pozycja_x] + labirynt[pozycja_y + 2][pozycja_x + 1] + labirynt[pozycja_y + 2][pozycja_x + 2] + labirynt[pozycja_y + 2][pozycja_x + 3] + labirynt[pozycja_y + 2][pozycja_x + 4] +
            labirynt[pozycja_y + 3][pozycja_x] + labirynt[pozycja_y + 3][pozycja_x + 1] + labirynt[pozycja_y + 3][pozycja_x + 2] + labirynt[pozycja_y + 3][pozycja_x + 3] + labirynt[pozycja_y + 3][pozycja_x + 4] +
            labirynt[pozycja_y + 4][pozycja_x + 1] + labirynt[pozycja_y + 4][pozycja_x + 2] + labirynt[pozycja_y + 4][pozycja_x + 3] +
            labirynt[pozycja_y - 1][pozycja_x + 2];
        } while (!(pozycja_x + pozycja_y)          // czy nie zaczyna sie od wejscia
        || suma_pol);                               // czy nie ma nic w miejscu wyjscia

        pole = &labirynt[pozycja_y    ][pozycja_x + 1];           *pole++ = 45; *pole++ = 96;   *pole = 46;           // rysunek
        pole = &labirynt[pozycja_y + 1][pozycja_x]; *pole++ = 45; *pole++ = 59; *pole++ = 96; *pole++ = 57; *pole = 46;
        pole = &labirynt[pozycja_y + 2][pozycja_x]; *pole++ = 84; *pole++ = 92; *pole++ = 62; *pole++ = 98; *pole = 83;
        pole = &labirynt[pozycja_y + 3][pozycja_x]; *pole++ = 47; *pole++ = 58; *pole++ = 94; *pole++ = 60; *pole = 48;
        pole = &labirynt[pozycja_y + 4][pozycja_x + 1];           *pole++ = 47; *pole++ = 86;   *pole = 48;
        labirynt[pozycja_y - 1][pozycja_x + 2] = 256; // tymczasowe zaznaczenie wyjscia
        *wejscia++ = pozycja_y - 1; *wejscia++ = pozycja_x + 2; *wejscia++ = 4; // otawrcie komnaty po budowie labiryntu
        mniej_pol_o += 21;   // skrocenie labiryntu o dana ilosc pol

    /**************** KWADRATOWA SALA ********************/
    for (int k = 0 ; k < 4 ; k++)//4
    {
        do {
            pozycja_x = rand() % (miara_x - 3);     // losowanie polozenia
            pozycja_y = rand() % (miara_y - 2);
            suma_pol = labirynt[pozycja_y][pozycja_x] + labirynt[pozycja_y][pozycja_x + 1] + labirynt[pozycja_y][pozycja_x + 2] +
            labirynt[pozycja_y + 1][pozycja_x] + labirynt[pozycja_y + 1][pozycja_x + 1] + labirynt[pozycja_y + 1][pozycja_x + 2] +
            labirynt[pozycja_y + 2][pozycja_x] + labirynt[pozycja_y + 2][pozycja_x + 1] + labirynt[pozycja_y + 2][pozycja_x + 2] +
            labirynt[pozycja_y + 1][pozycja_x + 3];
        } while (!(pozycja_x + pozycja_y)          // czy nie zaczyna sie od wejscia
        || suma_pol);                               // czy nie ma nic w miejscu wyjscia

        pole = &labirynt[pozycja_y    ][pozycja_x]; *pole++ = 89; *pole++ = 85; *pole = 90; // rysunek
        pole = &labirynt[pozycja_y + 1][pozycja_x]; *pole++ = 84; *pole++ = 62; *pole = 98;
        pole = &labirynt[pozycja_y + 2][pozycja_x]; *pole++ = 87; *pole++ = 86; *pole = 88;
        labirynt[pozycja_y + 1][pozycja_x + 3] = 256; // tymczasowe zaznaczenie wyjscia
        *wejscia++ = pozycja_y + 1; *wejscia++ = pozycja_x + 3; *wejscia++ = 8; // otawrcie komnaty po budowie labiryntu
        mniej_pol_o += 9;   // skrocenie labiryntu o dana ilosc pol
    }

    /**************** PROSTOKATNA SALA ********************/
    for (int k = 0 ; k < 3 ; k++)//3
    {
        do {
            pozycja_x = rand() % (miara_x - 2);     // losowanie polozenia
            pozycja_y = rand() % (miara_y - 4);
            suma_pol = labirynt[pozycja_y][pozycja_x] + labirynt[pozycja_y][pozycja_x + 1] +
            labirynt[pozycja_y + 1][pozycja_x] + labirynt[pozycja_y + 1][pozycja_x + 1] +
            labirynt[pozycja_y + 2][pozycja_x] + labirynt[pozycja_y + 2][pozycja_x + 1] +
            labirynt[pozycja_y + 3][pozycja_x] + labirynt[pozycja_y + 3][pozycja_x + 1] +
            labirynt[pozycja_y + 4][pozycja_x] + labirynt[pozycja_y + 4][pozycja_x + 1] +
            labirynt[pozycja_y + 4][pozycja_x + 2];
        } while (!(pozycja_x + pozycja_y)          // czy nie zaczyna sie od wejscia
        || suma_pol);                               // czy nie ma nic w miejscu wyjscia

        pole = &labirynt[pozycja_y    ][pozycja_x]; *pole++ = 89; *pole = 90; // rysunek
        pole = &labirynt[pozycja_y + 1][pozycja_x]; *pole++ = 84; *pole = 83;
        pole = &labirynt[pozycja_y + 2][pozycja_x]; *pole++ = 84; *pole = 83;
        pole = &labirynt[pozycja_y + 3][pozycja_x]; *pole++ = 84; *pole = 83;
        pole = &labirynt[pozycja_y + 4][pozycja_x]; *pole++ = 87; *pole = 80;
        labirynt[pozycja_y + 4][pozycja_x + 2] = 256; // tymczasowe zaznaczenie wyjscia
        *wejscia++ = pozycja_y + 4; *wejscia++ = pozycja_x + 2; *wejscia++ = 8; // otawrcie komnaty po budowie labiryntu
        mniej_pol_o += 10;   // skrocenie labiryntu o dana ilosc pol
    }

    /****************  WIEKSZA ROTUNDA ********************/
    for (int k = 0 ; k < 7 ; k++)//7
    {
        do {
            pozycja_x = (rand() % (miara_x - 3)) + 1;     // losowanie polozenia
            pozycja_y = rand() % (miara_y - 2);
            suma_pol = labirynt[pozycja_y][pozycja_x] + labirynt[pozycja_y][pozycja_x + 1] +
            labirynt[pozycja_y + 1][pozycja_x] + labirynt[pozycja_y + 1][pozycja_x + 1] +
            labirynt[pozycja_y + 2][pozycja_x] + labirynt[pozycja_y + 2][pozycja_x + 1] +
            labirynt[pozycja_y + 1][pozycja_x - 1];
        } while (!(pozycja_x + pozycja_y)          // czy nie zaczyna sie od wejscia
        || suma_pol);                               // czy nie ma nic w miejscu wyjscia

        pole = &labirynt[pozycja_y][pozycja_x];     *pole++ = 45; *pole = 46; // rysunek
        pole = &labirynt[pozycja_y + 1][pozycja_x]; *pole++ = 92; *pole = 53;
        pole = &labirynt[pozycja_y + 2][pozycja_x]; *pole++ = 58; *pole = 48;
        labirynt[pozycja_y + 1][pozycja_x - 1] = 256; // tymczasowe zaznaczenie wyjscia
        *wejscia++ = pozycja_y + 1; *wejscia++ = pozycja_x - 1; *wejscia++ = 2; // otawrcie komnaty po budowie labiryntu
        mniej_pol_o += 6;   // skrocenie labiryntu o dana ilosc pol
    }

    /****************  ROTUNDA ********************/
    for (int k = 0 ; k < 13 ; k++)//13
    {
        do {
            pozycja_x = rand() % (miara_x - 1);     // losowanie polozenia
            pozycja_y = rand() % (miara_y - 2);
        } while (!(pozycja_x + pozycja_y)           // czy nie zaczyna sie od wejscia
        || (labirynt[pozycja_y][pozycja_x] + labirynt[pozycja_y + 1][pozycja_x] + labirynt[pozycja_y][pozycja_x + 1] + labirynt[pozycja_y + 1][pozycja_x + 1]  // czy nie ma nic w tym miejscu
             + labirynt[pozycja_y + 2][pozycja_x + 1])); // czy nie ma nic w miejscu wyjscia

        pole = &labirynt[pozycja_y][pozycja_x]; *pole++ = 45; *pole = 46; // rysunek
        pole = &labirynt[pozycja_y + 1][pozycja_x]; *pole++ = 47; *pole = 81;
        labirynt[pozycja_y + 2][pozycja_x + 1] = 256; // tymczasowe zaznaczenie wyjscia
        *wejscia++ = pozycja_y + 2; *wejscia++ = pozycja_x + 1; *wejscia++ = 1; // otawrcie komnaty po budowie labiryntu
        mniej_pol_o += 4;   // skrocenie labiryntu o dana ilosc pol
    }

    pole = &labirynt[0][0];  // kasowanie zaznaczonych wyjsc
    for (int i = 0 ; i < miara_y * miara_x ; i++)
        if (*pole++ == 256) *(pole - 1) = 0;

    return mniej_pol_o;
}



void tworzenie_mapy(int miara_x, int miara_y, int licznik, int *wejscia)
{

  /******************************    labirynt     ********/

    srand(time(NULL)) ;
    int pozycja_x, pozycja_y, kierunek = 0, wolne[4] = {0,0,0,0};

    do {
    pozycja_x = rand() % (miara_x - 1);
    pozycja_y = rand() % (miara_y - 1);
    } while (labirynt[pozycja_y][pozycja_x]);

    int duzy_holl[4][2];

    do
        {
        int *poczatek_hallu = &duzy_holl[0][0];
        for (int i = 0 ; i < 8 ; i++) *poczatek_hallu++ = 0;

        do
        {
            kierunek = 0;

            if (pozycja_x              && !labirynt[pozycja_y][pozycja_x - 1]) wolne[kierunek++] = 8;   //lewo
            if (pozycja_x != miara_x-1 && !labirynt[pozycja_y][pozycja_x + 1]) wolne[kierunek++] = 2;   //prawo
            if (pozycja_y              && !labirynt[pozycja_y - 1][pozycja_x]) wolne[kierunek++] = 1;   //gora
            if (pozycja_y != miara_y-1 && !labirynt[pozycja_y + 1][pozycja_x]) wolne[kierunek++] = 4;   //dol


            if (kierunek)
            {
                int wybor_kierunku = rand() % (kierunek);
                int przesuniecie = wolne[wybor_kierunku];
                labirynt[pozycja_y][pozycja_x] += przesuniecie;

                if (przesuniecie & 8) {pozycja_x--; labirynt[pozycja_y][pozycja_x] |= 2; }; // przejscie do nastepnego pomieszczenia
                if (przesuniecie & 2) {pozycja_x++; labirynt[pozycja_y][pozycja_x] |= 8; };
                if (przesuniecie & 1) {pozycja_y--; labirynt[pozycja_y][pozycja_x] |= 4; };
                if (przesuniecie & 4) {pozycja_y++; labirynt[pozycja_y][pozycja_x] |= 1; };

                licznik--;
            }
/*****************/
            poczatek_hallu = &duzy_holl[2][1];
            for (int i = 0 ; i < 6 ; i++) *(poczatek_hallu + 2) = *poczatek_hallu--;
            duzy_holl[0][0] = pozycja_y;
            duzy_holl[0][1] = pozycja_x;

            if (duzy_holl[3][0])
            {
                int a = (duzy_holl[0][0] - duzy_holl[1][0] + duzy_holl[2][0] - duzy_holl[3][0]) || (duzy_holl[0][1] - duzy_holl[1][1] + duzy_holl[2][1] - duzy_holl[3][1]);
                if (!a)
                {
                    int rog_halu_y = (duzy_holl[0][0] + duzy_holl[1][0] + duzy_holl[2][0] + duzy_holl[3][0] - 2) / 4;
                    int rog_halu_x = (duzy_holl[0][1] + duzy_holl[1][1] + duzy_holl[2][1] + duzy_holl[3][1] - 2) / 4;
      //              cout << duzy_holl[0][0] << ", " << duzy_holl[1][0] << ", " << duzy_holl[2][0] << ", " << duzy_holl[3][0] << "\n"
      //               << duzy_holl[0][1]  << ", " << duzy_holl[1][1]  << ", " << duzy_holl[2][1]  << ", " << duzy_holl[3][1]  << "\n------------\n" ;

                    labirynt[rog_halu_y    ][rog_halu_x    ] |= 6;
                    labirynt[rog_halu_y + 1][rog_halu_x    ] |= 3;
                    labirynt[rog_halu_y    ][rog_halu_x + 1] |= 12;
                    labirynt[rog_halu_y + 1][rog_halu_x + 1] |= 9;
     //           int *poczatek_hallu = &duzy_holl[0][0];                   //nie sasiadujace
     //           for (int i = 0 ; i < 8 ; i++) *poczatek_hallu++ = 0;
                }
            }
  /*********************/
        }
        while (kierunek);


        do
        {
            pozycja_x++; if (pozycja_x == miara_x)
            {
                pozycja_x = 0; pozycja_y++;
                if (pozycja_y == miara_y) pozycja_y = 0;
            }
        } while (!labirynt[pozycja_y][pozycja_x] || (labirynt[pozycja_y][pozycja_x] > 15));
    } while (licznik > 0);

/******************* trawka na wejsciach i wyjsciach **************/

    labirynt[0][0] += 1; labirynt[y-1][x-1] += 4; //dorysowanie wejcia i wyjscia

    if (labirynt[0][0] ==  3) labirynt[0][0] = 16;  //trawa na wejsciu
    if (labirynt[0][0] ==  5) labirynt[0][0] = 17;
    if (labirynt[0][0] ==  7) labirynt[0][0] = 18;

    if (labirynt[y-1][x-1] ==  5) labirynt[y-1][x-1] = 19;  //trawa na wyjsciu
    if (labirynt[y-1][x-1] == 12) labirynt[y-1][x-1] = 20;
    if (labirynt[y-1][x-1] == 13) labirynt[y-1][x-1] = 21;

 /*********************  dorysowywanie wejsc do komnat specjalnych **************/

    while (*wejscia + *(wejscia + 1))
    {
        labirynt[*wejscia++][*wejscia++] |= *wejscia; wejscia++;
    }

 /*********************  usuwanie slupow w duzym hollu **************/

    for (int i = 0 ; i < miara_y - 1 ; i++)
    {
        for (int q = 0 ; q< miara_x - 1 ; q++)
        {
            int a = labirynt[i][q], b = labirynt[i][q + 1], c = labirynt[i + 1][q], d = labirynt[i + 1][q + 1];
            int a1 = a;
            if (a == 71) a1 = 12;
            if (a == 72) a1 = 14;
            if (a == 73) a1 = 13;
            if (a == 74) a1 = 15;
            if (a == 77) a1 = 7;
            if (a == 78) a1 = 15;
            if (a == 82) a1 = 15;

            int b1 = b;
            if (b == 75) b1 = 3;
            if (b == 76) b1 = 11;
            if (b == 77) b1 = 7;
            if (b == 78) b1 = 15;
            if (b == 81) b1 = 13;
            if (b == 82) b1 = 15;

            int c1 = c;
            if (c == 75) c1 = 3;
            if (c == 76) c1 = 11;
            if (c == 77) c1 = 7;
            if (c == 78) c1 = 15;
            if (c == 80) c1 = 11;
            if (c == 82) c1 = 15;

            if ((a1 & 6) + (b1 & 12) + (c1 & 3) + (d & 9) == 30)
            {
                if (a == 6) labirynt[i][q] = 67;
                if (a == 7) labirynt[i][q] = 69;
                if (a == 14) labirynt[i][q] = 68;
                if (a == 72) labirynt[i][q] = 95;
                if (a == 15) labirynt[i][q] = 70;
                if (a == 74) labirynt[i][q] = 96;
                if (a == 77) labirynt[i][q] = 91;
                if (a == 78) labirynt[i][q] = 92;
                if (a == 82) labirynt[i][q] = 100;

                if (b == 12) labirynt[i][q + 1] = 71;
                if (b == 14) labirynt[i][q + 1] = 72;
                if (b == 13) labirynt[i][q + 1] = 73;
                if (b == 15) labirynt[i][q + 1] = 74;
                if (b == 78) labirynt[i][q + 1] = 99;
                if (b == 81) labirynt[i][q + 1] = 97;
                if (b == 82) labirynt[i][q + 1] = 98;

                if (c == 3) labirynt[i + 1][q] = 75;
                if (c == 11) labirynt[i + 1][q] = 76;
                if (c == 7) labirynt[i + 1][q] = 77;
                if (c == 15) labirynt[i + 1][q] = 78;
                if (c == 80) labirynt[i + 1][q] = 93;
                if (c == 82) labirynt[i + 1][q] = 94;

                if (d == 9) labirynt[i + 1][q + 1] = 79;
                if (d == 11) labirynt[i + 1][q + 1] = 80;
                if (d == 13) labirynt[i + 1][q + 1] = 81;
                if (d == 15) labirynt[i + 1][q + 1] = 82;
            }
        }
    }

 /*********************  tworzenie piku mapy **************/

		string opis_mapy_1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
			"<map version=\"1.0\" tiledversion=\"1.0.3\" orientation=\"orthogonal\""
			" renderorder=\"left-down\" width=\"";
		string opis_mapy_2 = "\" height=\"";
		string opis_mapy_3 = "\" tilewidth=\"30\" tileheight=\"30\" nextobjectid=\"1\">\n <tileset firstgid=\"1\" "
			"source=\"kafelki.tsx\"/>\n <layer name=\"Warstwa Kafelkow 1\" width=\"";
		string opis_mapy_4 = "\" height=\"";
		string opis_mapy_5 = "\">\n  <data encoding=\"csv\">\n31,31,22,23,24,25,";
            for (int i = 0 ; i < miara_x - 4 ; i++) opis_mapy_5 += "31,";
            opis_mapy_5 += "31,31,\n31,41,32,33,34,35,";
            for (int i = 0 ; i < miara_x - 4 ; i++) opis_mapy_5 += "29,";
            opis_mapy_5 += "42,31,\n31,39,";
		string opis_mapy_6 = "40,31,\n31,43,";
            for (int i = 0 ; i < miara_x - 3 ; i++) opis_mapy_6 += "30,";
            opis_mapy_6 += "26,27,28,44,31,\n31,31,";
            for (int i = 0 ; i < miara_x - 3 ; i++) opis_mapy_6 += "31,";
            opis_mapy_6 += "36,37,38,31,31\n</data>\n </layer>\n</map>";


		int dla_mapy_x = miara_x + 4, dla_mapy_y = miara_y + 4;
		fstream plik;											//zapisanie mapy
		plik.open("mapa.tmx", ios::out);

		plik << opis_mapy_1 << dla_mapy_x << opis_mapy_2 << dla_mapy_y ;
		plik << opis_mapy_3 << dla_mapy_x << opis_mapy_4 << dla_mapy_y << opis_mapy_5;

        cout << opis_mapy_1 << dla_mapy_x << opis_mapy_2 << dla_mapy_y ;
		cout << opis_mapy_3 << dla_mapy_x << opis_mapy_4 << dla_mapy_y << opis_mapy_5;

		int *pole = &labirynt[0][0];

		for (int i = 0; i < miara_y ; i++)
        {
            for (int q = 0; q < miara_x; q++)
            {
                plik << *pole << ",";
                cout << *pole++ << ",";
            }
           if (i < miara_y - 1) {plik << "40,31,\n31,39,"; cout << "40,31,\n31,39,";}
        }

		plik << opis_mapy_6;
		plik.close();

		cout << opis_mapy_6;
		cout << "\n\n\n";
}

















