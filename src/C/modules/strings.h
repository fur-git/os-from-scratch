#ifndef STRINGS
#define STRINGS

// system messages

extern volatile const char* PLACEHOLDER;
extern volatile const char* DEFAULT;
extern volatile const char* INPUT;
extern volatile const char* NEWLINE;
extern volatile const char* INVALID;

// misc messages

extern volatile const char* FUNNYEASTEREGG;
extern volatile const char* KERNELPANIC;
extern volatile const char* HELPTEXT;

// commands without arguments

extern volatile const char* HELPCMD;
extern volatile const char* CLEARCMD;
extern volatile const char* FUNNYCMD;
extern volatile const char* SUICIDECMD;
extern volatile const char* HALTCMD;
extern volatile const char* LISTFSCMD;

// commands with arguments

extern volatile const char* ECHOCMD;
extern volatile const char* WRITECMD;
extern volatile const char* READCMD;
extern volatile const char* ERASECMD;
extern volatile const char* EXPRESSCMD;

#endif
