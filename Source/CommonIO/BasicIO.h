#pragma once

#include <stdio.h>
#include "Utility/String.h"

void clearStdin(void);
void discardWhitespace(void);
void waitForEnter(void);
void scanLine(String target);

void clearConsole(void);
void newLine(void);
void printString(StringView string);
