
/* ---------------------------------------------------- */

caractere_non_signfctf()
    {
    return (Car >=' ' && Car != '<' && Car != '>' && Car !='|' && Car !='[' && Car !=']'&& Car !='{' && Car !='}' && Car !='\n' && C_caractere()) ;
    }

car(c)
char c ;
    {
    int l ;

    if (c > 0 && c != Car)
        return 0 ;

    l = strlen(CarLigne) ;
    if (Car >= ' ')
        {
        CarLigne[l] = Car ;
        CarLigne[l +1] = 0 ;
        }
    else *CarLigne = 0 ;

do {
    Car = getchar() ;
    if (Car == EOF)
        return 0 ;
} while (*CarLigne == 0 && Car == ' ') ;

    /* if (debug) putchar(Car) ; */

    return Car ;
    }


/* ---------------------------------------------------- */

int main(argc)
int argc ;
    {
    if (argc > 1) debug = 1 ;

    Car= CarLigne[0]= Ligne[0] = 0 ;

    if (car('\0'))
    printf("#include %chead.h%c\n", '"', '"') ;
    if (!Start() || !ok)
        {
        puts("/* text is not OK! */") ;
        puts(CarLigne) ;
        return 0 ;
        }
    else
        {
        puts("/* text is OK! */") ;
        printf("#include %cusers.h%c\n", '"', '"') ;
        printf("#include %cqueue.h%c\n", '"', '"') ;
        }

    return 1 ;
    }

