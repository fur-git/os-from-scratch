#include "strings.h"

// system messages

volatile const char* PLACEHOLDER = "PLACEHOLDER (Something unexpected happened)\n";
volatile const char* DEFAULT = "Hello, World!\n";
volatile const char* INPUT = "Input: ";
volatile const char* NEWLINE = "\n";
volatile const char* INVALID = "Invalid command\n";

// misc messages

volatile const char* FUNNYEASTEREGG = "CPU Triple Fault GNU x86 GNU/LINUX DEBIAN UPDATE BIOS ERASE Crash (Your Disk And RAM Are Going To Explode in THIRTY SECONDS)\n";
volatile const char* KERNELPANIC = "KERNEL PANIC ";
volatile const char* HELPTEXT =
"Available commands:\n"
"  HELP               - show this message\n"
"  ECHO <text>        - print text\n"
"  CLEAR              - clear the screen\n"
"  WRITE <0-9> <text> - write to virtual file\n"
"  READ <0-9>         - read virtual file\n"
"  ERASE <0-9>        - erase virtual file\n"
"  HALT               - stop the CPU\n"
"  SUICIDE            - trigger kernel panic\n";

// commands without arguments

volatile const char* HELPCMD = "HELP";
volatile const char* CLEARCMD = "CLEAR";
volatile const char* FUNNYCMD = "FUNNY MOMENT";
volatile const char* SUICIDECMD = "SUICIDE";
volatile const char* HALTCMD = "HALT";

// commands with arguments

volatile const char* ECHOCMD = "ECHO ";
volatile const char* WRITECMD = "WRITE ";
volatile const char* READCMD = "READ ";
volatile const char* ERASECMD = "ERASE ";
