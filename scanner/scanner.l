%option noyywrap

whitespace  [\n\t ]
specialchar [;\(\),=:+*\.-]|->|>=
comment     "{".*"}"
identifier  [A-Za-z][A-Za-z0-9]*
decdigit    [0-9]+
hexdigit    \$[a-fA-F0-9]+    

%%

end      | 
return   | 
var      |
cond     |
continue |
break    |
not      |
head     |
tail     |
islist   |
or              printf("%s\n", yytext);
{specialchar}   printf("%s\n", yytext);
{identifier}    printf("id %s\n", yytext);
{decdigit}  |
{hexdigit}      printf("num %s\n", yytext);
{whitespace}+   ;
{comment}       ;
.               {
                    fprintf(stderr, "Invalid token: %s", yytext); 
                    exit(EXIT_FAILURE);
                }
