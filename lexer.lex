%{ 
#include <stdint.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "symbol.h"
//#include "semantics.h"
#include "parser.h"
#define T_eof 0


int lineno = 1;
void yyerror (const char *msg);
%}

%x COMMENT

L 	[A-Za-z]     /* letters */
DIGIT 	[0-9]    /* digits  */
WHITE 	[ \t]    /* white space */


%%


"and"   { return T_and; 	   }
"bool"  { return T_bool; 	   }
"break" { return T_break;	   }
"case"  { return T_case;	   }
"char"  { return T_char;  	   }
"const" { return T_const; 	   }
"continue" { return T_cont;    }
"default"  { return T_def;     }
"do"    { return T_do;		   }
"DOWNTO" { return T_DOWNTO;	   }
"else"  { return T_else;	   }
"false" { yylval.expression.value.y = 0; return T_false;      }
"FOR"	{ return T_FOR;		   }
"FORM"  { return T_FORM;	   }
"FUNC"  { return T_FUNC;	   }
"if"	{ return T_if;		   }
"int"	{ return T_int;		   }
"MOD"	{ return T_MOD;		   }
"NEXT"  { return T_NEXT;	   }
"not"	{ return T_not;		   }
"or"	{ return T_or;		   }
"PROC"	{ return T_PROC;	   }
"PROGRAM" { return T_PROGRAM;  }
"REAL"	{ return T_REAL;	   }
"return" { return T_return;	   }
"STEP"	{ return T_STEP;	   }
"switch" { return T_switch;    }
"TO"	{ return T_TO;		   }
"true" 	{ yylval.expression.value.y = 1; return T_true;	   }
"while"	{ return T_while;	   }
"WRITE"	{ return T_WRITE;	   }
"WRITELN" { return T_WRITELN;  }
"WRITESP" { return T_WRITESP;  }
"WRITESPLN" { return T_WRITESPLN;}
"==" 	{ return T_equal;	   }
">"		{ return T_greater;	   }
"<"		{ return T_less;	   }
"!="	{ return T_nequal;     }
">="	{ return T_egreater;   }
"<="	{ return T_lequal;	   }
"+"		{ return T_plus;	   }
"-"		{ return T_minus;	   }
"*"		{ return T_mult;	   }
"/"		{ return T_div;		   }
"%"		{ return T_mod;		   }
"!"		{ return T_notb;	   }
"&&"	{ return T_AND;		   }
"||"	{ return T_OR;		   }
"++"	{ return T_pp;		   }
"--"	{ return T_mm;		   }
"="		{ return T_assign;	   }
"+="	{ return T_plusassign; }
"-="	{ return T_minusassign;}
"*="	{ return T_multassign; }
"/="	{ return T_divassign;  }
"%="	{ return T_modassign;  }
"&"		{ return T_ampersand;  }
";"		{ return T_mark;	   }
"."		{ return T_dot;		   }
"("		{ return T_lpar;	   }
")"		{ return T_rpar;       }
":"		{ return T_2dots;	   }
","		{ return T_coma;	   }
"["		{ return T_lbracket;   }
"]"		{ return T_rbracket;   }
"{"		{ return T_lhook;	   }
"}"		{ return T_rhook;	   }

[ \t]+ 	        			 { /* do nothing */ 	}
\n 				 			 { lineno++;			}
[a-zA-Z]([a-zA-Z]|[0-9]|_)*  {  yylval.string_value=strdup(yytext); return T_id; }

[0]+        				 { yylval.expression.value.x=atoi(yytext);  return T_const_int;  }
[1-9][0-9]* 				 { yylval.expression.value.x=atoi(yytext);	return T_const_int;  }

[0-9]+(\.[0-9]+)?([eE]([-+]?)[0-9]+)? {  yylval.expression.value.w=strtold(yytext,NULL); return T_const_real;}



"\'\\n\'"						 { yylval.expression.value.z='\n' ;   return T_const_char; }
"\'\\t\'"						 { yylval.expression.value.z='\t' ;  return T_const_char; }
"\'\\r\'"						 { yylval.expression.value.z='\r' ;  return T_const_char; }
"\'\\0\'"						 { yylval.expression.value.z='\0' ;  return T_const_char; }
"\'\\\\\'"						 { yylval.expression.value.z='\\' ;  return T_const_char; }
"\'\\\"\'"						 { yylval.expression.value.z='"' ;   return T_const_char; }
"\'\\\'\'"						 { yylval.expression.value.z='\'' ; return T_const_char; }

'[^\\\'\"]*' 			     { yylval.expression.value.z=yytext[1];  return T_const_char; }

\"[^\n^\"]*\"			  		 { yylval.expression.value.q=strdup(yytext);  return T_string;    } 

"//"[^\n]*\n 			         { lineno++;		    }


"/*" 				 		 {  BEGIN(COMMENT) ;  	}
<COMMENT>"*/"	      		 {  BEGIN(INITIAL) ;   	}
<COMMENT>"\n"		  		 {   lineno++;	 		}
<COMMENT>"*"		  		 {   /*nothing*/	 	}
<COMMENT>[^*\n]+	 		 {	 /*nothing*/	 	}

.  				 		     { printf( "UNRECOGNIZED CHARACTER %s\n at line:%d\n",yytext,lineno);
					           exit(1); 			}

%%

