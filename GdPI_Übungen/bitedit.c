# include <stdio.h>
# include <stdlib.h>

/*  Urspruengliche Quelle
 ** C/C++, Kaiser & Kecher, Galileo Computing, 2008
 */

#define OK 0

int main(void) {
    /* for char */
    int NUMBER_OF_HIGHEST_BIT = 7;
    unsigned char uzahl;
    char szahl;


    int ziffer, bitno, i;
    char cmd;

    uzahl = 0;

    printf("Editor fuer 8-Bit Zahlen\n");
    printf("\n");
    printf("Befehle:\n");
    printf("   +n  setzt      Bit mit Nummer n (0<=n<7)\n");
    printf("   -n  loescht    Bit mit Nummer n (0<=n<7)\n");
    printf("   ~n  invertiert Bit mit Nummer n (0<=n<7)\n");
    printf("    0  loescht alle Bits\n");
    printf("    1  1-Komplement aller Bits\n");
    printf("    2  2-Komplement aller Bits\n");
    printf("    q  Ende\n");
    printf("\n");

    printf("bin        oct  hex  signed unsigned\n");
    do {
        /* Binaer */
        for( i = 0; i <= NUMBER_OF_HIGHEST_BIT; i = i+1)
        {
            ziffer = (uzahl >> (NUMBER_OF_HIGHEST_BIT-i)) & 0x01;
            printf( "%d", ziffer);
            if (i % 4 == 3 && i != NUMBER_OF_HIGHEST_BIT) printf(".");
        }
        printf( "  ");
        /* Oktal */
        for( i = 0; i <= (NUMBER_OF_HIGHEST_BIT/3) ; i = i+1)
        {
            ziffer = (uzahl >> 3*((NUMBER_OF_HIGHEST_BIT/3)-i)) & 0x07;
            printf( "%d", ziffer);
        }
        /* Hexadezimal */
        printf( "   ");
        for( i = 0; i <= (NUMBER_OF_HIGHEST_BIT/4); i = i+1)
        {
            ziffer = (uzahl >> 4*((NUMBER_OF_HIGHEST_BIT/4)-i)) & 0x0f;
            if( ziffer < 10)
                printf( "%d", ziffer);
            else
                printf( "%c", 'a' - 10 + ziffer);
        }
        
        szahl = uzahl;

        /* Signed */
        printf( "  %6d", szahl);
        /* Unsigned */
        printf( "  %7d", uzahl);

        /* Eingabe Befehl */
        printf( "  Befehl: ");
        fflush(stdout);
        scanf( "%c", &cmd);
        /* Muss zweites Zeichen gelesen werden ? */
        if (cmd != 'q' && cmd != '0' && cmd != '1' && cmd != '2') {
            scanf( "%d", &bitno);
        }

        /* Befehl ausfuehren */
        if( cmd == '0')
            uzahl = 0;
        if( cmd == '1')
            uzahl = uzahl ^  (0xff);
        if( cmd == '2') {
            uzahl = uzahl ^  (0xff);
            uzahl++;
        }
        if( cmd == '+')
            uzahl = uzahl |  (1 << bitno);
        if( cmd == '-')
            uzahl = uzahl & ~(1 << bitno);
        if( cmd == '~')
            uzahl = uzahl ^  (1 << bitno);

        /* Newline-Zeichen aus Eingabepuffer lesen */
        while(getchar() != '\n'); // Puffer leeren

    } while (cmd != 'q');

    return OK;
}

