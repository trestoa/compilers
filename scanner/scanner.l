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
{decdigit}      {
                    long res = strtol(yytext, NULL, 10);
                    if (errno != 0 && res == 0) {
                        fprintf(stderr, "Failed to convert to number: %s\n", strerror(errno));
                    }
                    printf("num %lu\n", res);
                }
{hexdigit}      {
                    // Skip $ character by adding 1
                    long res = strtol(yytext + 1, NULL, 16);
                    if (errno != 0 && res == 0) {
                        fprintf(stderr, "Failed to convert to number: %s\n", strerror(errno));
                    }
                    printf("num %lu\n", res);
                }
{whitespace}+   ;
{comment}       ;
.               {
                    fprintf(stderr, "Invalid token: %s", yytext); 
                    exit(EXIT_FAILURE);
                }
