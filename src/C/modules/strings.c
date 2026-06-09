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

// commands without arguments

volatile const char* CLEARCMD = "CLEAR";
volatile const char* FUNNYCMD = "FUNNY MOMENT";
volatile const char* SUICIDECMD = "SUICIDE";
volatile const char* HALTCMD = "HALT";

// commands with arguments

volatile const char* ECHOCMD = "ECHO ";
volatile const char* WRITECMD = "WRITE ";
volatile const char* READCMD = "READ ";
volatile const char* ERASECMD = "ERASE ";
