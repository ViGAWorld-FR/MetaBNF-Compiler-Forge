#include "head.h"
Start()
    {
    int rc = 0 ;

    trace("Start") ;
    br(ligne_start(), suite_de_lignes())

    return rc ;
    }

ligne_start()
    {
    int rc = 0 ;

    trace("ligne_start") ;
    br(nom_test_start() && C_nom_test_start_end(), description())

    return rc ;
    }

nom_test_start()
    {
    int rc = 0 ;

    trace("nom_test_start") ;
    br(nom_test(), 1)

    return rc ;
    }

description()
    {
    int rc = 0 ;

    trace("description") ;
    C_description_begin() ;
    br(car(':'), car(':') && car('=') && partie_droite())
    C_description_end() ;

    return rc ;
    }

partie_droite()
    {
    int rc = 0 ;

    trace("partie_droite") ;
    br(repetition(), 1)
    br(tests(), partie_droite_rep() && car('\n'))

    return rc ;
    }

partie_droite_rep()
    {
    int rc = 0 ;

    trace("partie_droite_rep") ;
    do { rc = 0 ;
    br(car('|'), tests())
        } while (ok && rc) ; rc = 1 ;

    return rc ;
    }

tests()
    {
    int rc = 0 ;

    trace("tests") ;
    C_tests_begin() ;
    br(test(), tests_rep())
    C_tests_end() ;

    return rc ;
    }

tests_rep()
    {
    int rc = 0 ;

    trace("tests_rep") ;
    do { rc = 0 ;
    br(test(), 1)
        } while (ok && rc) ; rc = 1 ;

    return rc ;
    }

test()
    {
    int rc = 0 ;

    trace("test") ;
    br(car('<'), meta_caractere_ou_nom_test() && car('>'))
    br(repetition(), 1)
    br(caractere_non_signfctf(), test_rep())

    return rc ;
    }

test_rep()
    {
    int rc = 0 ;

    trace("test_rep") ;
    do { rc = 0 ;
    br(caractere_non_signfctf(), 1)
        } while (ok && rc) ; rc = 1 ;

    return rc ;
    }

meta_caractere_ou_nom_test()
    {
    int rc = 0 ;

    trace("meta_caractere_ou_nom_test") ;
    br(car('\''), caractere() && car('\''))
    br(nom_test(), 1)

    return rc ;
    }

nom_test()
    {
    int rc = 0 ;

    trace("nom_test") ;
    C_nom_test_begin() ;
    br(caractere_de_nom(), nom_test_rep())
    C_nom_test_end() ;

    return rc ;
    }

nom_test_rep()
    {
    int rc = 0 ;

    trace("nom_test_rep") ;
    do { rc = 0 ;
    br(caractere_de_nom(), 1)
        } while (ok && rc) ; rc = 1 ;

    return rc ;
    }

caractere_de_nom()
    {
    int rc = 0 ;

    trace("caractere_de_nom") ;
    br(majuscule(), 1)
    br(minuscule(), 1)
    br(numerique(), 1)
    br(car('_'), 1)
    br(car('*'), 1)

    return rc ;
    }

repetition()
    {
    int rc = 0 ;

    trace("repetition") ;
    br(car('['), C_repetition_corps_begin() && repetition_corps() && C_repetition_corps_end() && car(']') && car('*'))

    return rc ;
    }

repetition_corps()
    {
    int rc = 0 ;

    trace("repetition_corps") ;
    br(tests(), 1)

    return rc ;
    }

suite_de_lignes()
    {
    int rc = 0 ;

    trace("suite_de_lignes") ;
    br(ligne(), suite_de_lignes_rep())

    return rc ;
    }

suite_de_lignes_rep()
    {
    int rc = 0 ;

    trace("suite_de_lignes_rep") ;
    do { rc = 0 ;
    br(ligne(), 1)
        } while (ok && rc) ; rc = 1 ;

    return rc ;
    }

ligne()
    {
    int rc = 0 ;

    trace("ligne") ;
    br(car('\n'), 1)
    br(nom_test(), description())

    return rc ;
    }

caractere()
    {
    int rc = 0 ;

    trace("caractere") ;
    br(C_caractere(), 1)

    return rc ;
    }

majuscule()
    {
    int rc = 0 ;

    trace("majuscule") ;
    br(Car >= 'A' && Car <= 'Z' && car('\0'), 1)

    return rc ;
    }

minuscule()
    {
    int rc = 0 ;

    trace("minuscule") ;
    br(Car >= 'a' && Car <= 'z' && car('\0'), 1)

    return rc ;
    }

numerique()
    {
    int rc = 0 ;

    trace("numerique") ;
    br(Car >= '0' && Car <= '9' && car('\0'), 1)

    return rc ;
    }

/* text is OK! */
#include "users.h"
#include "queue.h"
