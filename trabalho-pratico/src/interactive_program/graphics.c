#include "interactive_program/graphics.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define LARGE_BUFFER 4096



const char *plane_art[] = {
"__  _",
"\\ `/ |",
" \\__`!",
" / ,' `-.__________________",
"'-'\\_____              LI3 `-.",
"   <____()-=O=O=O=O=O=[]====--)",
"     `.___ ,-----,_______...-'",
"          /    .'",
"         /   .'",
"        /  .'",         
"        `-'",
NULL
};

const char *clouds_art[] = {
"          _  _",
"         ( `   )_",
"        (    )    `)",
"      (_   (_ .  _) _)",
"",
"                                     _",
"                                    (  )",
"                                 ( `  ) . )",
"                               (_, _(  ,_)_)",
NULL
};

const char *clock_art[] = {
"     Loading ...",

"        _____",
"     _.'_____`._",
"   .'.-'  12 `-.`.",
"  /,' 11      1 `.\\",    
" // 10      /   2 \\\\",  
";;         /       ::",
"|| 9  ----O      3 ||",
"::                 ;;",