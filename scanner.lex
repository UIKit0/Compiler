%{ 
#include <stdint.h>
#include <stdio.h>


#define T_eof 0;
#define T_and 256;
#define T_bool 257;
#define T_break 258;
#define T_case 259;
#define T_char 260;
#define T_const 261;
#define T_cont 262;
#define T_def 263;
#define T_do 264;
#define T_DOWNTO 265;
#define T_else 266;
#define T_false 267;
#define T_FOR 268;
#define T_FORM 269;
#define T_FUNC 270;
#define T_if 271;
#define T_int 272;
#define T_MOD 273;
#define T_NEXT 274;
#define T_not 275;
#define T_or 276;
#define T_PROC 277;
#define T_PROGRAM 278;
#define T_REAL 279;
#define T_return 280;
#define T_STEP 281;
#define T_switch 282;
#define T_TO 283;
#define T_true 284;
#define T_while 285;
#define T_WRITE 286;
#define T_WRITELN 286;
#define T_WRITESP 287;
#define T_WRITESPLN 288;
#define T_const_int 289;
#define T_const_real 290;
#define T_id 291;
#define T_const_char 292;
#define T_string 293;
#define T_equal 294;
#define T_greater 295;
#define T_less 296;
#define T_nequal 297;
#define T_egreater 298;
#define T_lequal 299;
#define T_plus 300;
#define T_minus 301;
#define T_mult 302;
#define T_div 303;
#define T_mod 304;
#define T_notb 305;
#define T_AND 306;
#define T_OR 307;
#define T_pp 308;
#define T_mm 309;
#define T_assign 310;
#define T_plusassign 311;
#define T_minusassign 312;
#define T_multassign 313;
#define T_divassign 314;
#define T_modassign 315;
#define T_ampersand 316;
#define T_mark 317;
#define T_dot 318;
#define T_lpar 319;
#define T_rpar 320;
#define T_2dots 321;
#define T_coma 322;
#define T_lbracket 323;
#define T_rbracket 324;
#define T_lhook 325;
#define T_rhook 326

int lineno = 1;
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
"false" { return T_false;      }
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
"true" 	{ return T_true;	   }
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
[a-zA-Z]([a-zA-Z]|[0-9]|_)*  { return T_id; 		}

[0]+        				 { return T_const_int;  }
[1-9][0-9]* 				 { return T_const_int;  }

[0-9]+(\.[0-9]+)?([eE]([-+]?)[0-9]+)? { return T_const_real;}

'[^\\\'\"]*' 			     { return T_const_char; }

\"[^\n]*\"			  		 { return T_string;	    } 

"//"[.]*\n 			         { lineno++;		    }


"/*" 				 		 { BEGIN(COMMENT) ;  	}
<COMMENT>"*/"	      		 { BEGIN(INITIAL) ;   	}
<COMMENT>"\n"		  		 {    lineno++;	 		}
<COMMENT>"*"		  		 {   /*nothing*/	 	}
<COMMENT>[^*\n]+	 		 {	  /*nothing*/	 	}

.  				 		     { printf( "UNRECOGNIZED CHARACTER %s\n at line:%d\n",yytext,lineno);
					           exit(1); 			}


%%

int main () {
	int token,_EOF = T_eof;
	yyin = stdin;
	do {
		token = yylex();
		printf("token=%d, lexeme=\"%s\"\n",token, yytext);
	
		} while (token != _EOF);
	return 0;
}