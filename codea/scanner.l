%option noyywrap
%{
#include "y.tab.h"
#include "ag.h"
#include "codegen.h"

#include <string.h>

#define lexeme strcpy((char *) malloc(yyleng+1), yytext)
%}

whitespace  [\n\t ]
comment     "{".*"}"
identifier  [A-Za-z][A-Za-z0-9]*
decdigit    [0-9]+
hexdigit    \$[a-fA-F0-9]+    

%%

end             return (END);
return          return (RETURN);
var             return (VAR);
cond            return (COND);
continue        return (CONTINUE);
break           return (BREAK);
not             return (NOT);
head            return (HEAD);
tail            return (TAIL);
islist          return (ISLIST);
or              return (OR);
"->"            return (RA);
";"             return (';');
"("             return ('(');
")"             return (')');
"+"             return ('+');
"*"             return ('*');
"="             return ('=');
"-"             return ('-');
"."             return ('.');
":"             return (':');
","             return (',');
">="            return (GTEQ);
{identifier}    return (ID); @{ @ID.val@ = lexeme; @}
{decdigit}      return (NUM); @{ @NUM.val@ = strtol(yytext, NULL, 10); @}
{hexdigit}      return (NUM); @{ @NUM.val@ = strtol(yytext+1, NULL, 16); @}
{whitespace}+   ;
{comment}       ;
.               {
                    fprintf(stderr, "Invalid token: %s", yytext); 
                    exit(EXIT_FAILURE);
                }
