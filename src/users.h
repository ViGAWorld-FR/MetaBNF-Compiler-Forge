
/* ---------------------------------------------------- */

int b_nom_test_supl = 0, C_nom_test_i1 ;
int b_description = 0, b_partie_gauche_begin = 0, b_partie_gauche_end = 0 ;

char * nom ;
char ligne_nom[123] ;

C_caractere(){
    char c ;
    int b_back_slash = 0 ;

    if (b_nom_test_supl == 1) printf(", ") ;
    if (b_nom_test_supl > 1) printf(" && ") ;

    if (Car == '\\')
        {
        car('\0') ;
        b_back_slash = 1 ;
        }
    c = Car ;
    car('\0') ;

    if (Car == '_') /* intervale */
        {
        car('\0') ;
        printf("Car >= '%c' && Car <= '%c' && car('\\0')", c, Car) ;
        car('\0') ;
        }
    else
        {
        if (b_back_slash) printf("car('\\%c')", c) ;
        else
            if (c == '\'')
                printf("car('\\%c')", c) ;
            else
                printf("car('%c')", c) ;
        }

    b_nom_test_supl++ ;
    return 1;}

C_nom_test_begin(){
    C_nom_test_i1 = strlen(CarLigne) ;
    return 1;}

C_nom_test_end(){
    int len, bBegin = 0, bEnd = 0 ;

    nom = &CarLigne[C_nom_test_i1] ;
    len = strlen(nom) ;

    if (b_nom_test_supl == 1) printf(", ") ;
    if (b_nom_test_supl > 1) printf(" && ") ;

    if (nom[0] == '*')
        {
        bBegin = 1 ;
        nom++ ;
        len -= 1 ;
        }
    if (nom[len -1] ==  '*')
        {
        bEnd = 1 ;
        nom[len -1] = 0 ;
        len -= 1 ;
        }

    if (!b_description)
        {
        if (bBegin) b_partie_gauche_begin = 1 ;
        else b_partie_gauche_begin = 0 ;
        if (bEnd) b_partie_gauche_end = 1 ;
        else b_partie_gauche_end = 0 ;

        if (*nom) printf("%s()", nom) ;
        }
    else
        {
        if (bBegin) {printf("C_%s_begin() && ", nom) ;}
        printf("%s()", nom) ;
        if (bEnd) {printf(" && C_%s_end()", nom) ;}

        b_nom_test_supl++ ;
        }

    return 1;}

C_tests_begin()
    {
    b_nom_test_supl = 0 ;
    printf("    br(") ;
    return 1 ;
    }

C_tests_end()
    {
    if (b_nom_test_supl > 1)
        puts(")") ;
    else
        puts(", 1)") ;
    b_nom_test_supl = 0 ;
    return 1 ;
    }

C_repetition_corps_begin()
    {
    b_nom_test_supl = 0 ;
    printf("    do { rc = 0 ;\n") ;
    return 1 ;
    }

C_repetition_corps_end()
    {
    if (b_nom_test_supl > 1)
        puts(")") ;
    else
        puts("        } while (ok && rc) ; rc = 1 ;") ;
    b_nom_test_supl = 0 ;
    return 1 ;
    }

C_description_begin()
    {
    strcpy(ligne_nom, nom) ;

    printf("\n    {\n") ;
    puts("    int rc = 0 ;") ;
    printf("\n    trace(%c%s%c) ;\n", '"', ligne_nom, '"') ;

    if (b_partie_gauche_begin)
        printf("    C_%s_begin() ;\n", nom) ;

    b_description = 1 ;

    return 1 ;
    }

C_description_end()
    {
    if (b_partie_gauche_end)
        printf("    C_%s_end() ;\n", ligne_nom) ;

    puts("\n    return rc ;\n    }\n") ;

    b_description = 0 ;

    return 1 ;
    }

C_nom_test_start_end()
    {
    if (strcmp(nom, "Start") == 0) return 1 ;
    return 0 ;
    }

/* ---------------------------------------------------- */

