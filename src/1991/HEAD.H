#include "stdio.h"
#include "string.h"

/* ---------------------------------------------------- */

#define cut(_test) if (!(_test)) \
    {printf("ERREUR dans <%s>\n", trace_fonction) ; ok = 0 ; rc = 0; } \
    else rc = 1 ;

#define br(_t1, _t2) \
    if (ok && !rc && _t1) cut(_t2)


int ok = 1 ; /* en cas de cassure== erreur de syntaxe, ok <== 0 */
char Car, CarLigne[321], Ligne[321] ;
int debug ;

/* ---------------------------------------------------- */

int trace_indent = 0 ;
char trace_str[345], * trace_fonction ;

void trace(fonction)
char * fonction ;
{
int i ;

trace_fonction = fonction ;
if (!debug) return ;

*trace_str = 0 ;
for (i = 0 ; i < trace_indent ; i++) strcat(trace_str, " ") ;

sprintf(trace_str, "### Car='%c', CarLigne=''%s'' : %s", Car, CarLigne, fonction) ;
puts(trace_str) ;
}

/* ---------------------------------------------------- */

