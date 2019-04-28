%option noyywrap

whitespace  [\n\t ]
comment     "{".*"}"
specialchar [;\(\),=:+*\.-]
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
{identifier}    return (ID);
{decdigit}  |
{hexdigit}      return (NUM);
{whitespace}+   ;
{comment}       ;
.               {
                    fprintf(stderr, "Invalid token: %s", yytext); 
                    exit(EXIT_FAILURE);
                }
