#include "IO/BasicIO.h"
#include "IO/ConditionalInput.h"
#include <stdbool.h>
#include "UserInterface/DeletionMenu.h"
#include "UserInterface/Logo.h"
#include "Utility/System.h"

typedef enum DeletionMenuCommand {

    DELETE_ACTOR,
    DELETE_MOVIE,
    DELETE_STUDIO,
    DELETE_ROLE

} DeletionMenuCommand;

static void displayMenu();
static bool isValidInput(char input);
static void executeCommand(Database* database, DeletionMenuCommand command);

void DeletionMenu(Database* database) {

    displayMenu();

    printString("Podaj numer operacji: ");
    const char input = readSingleCharIf(isValidInput);

    executeCommand(database, (DeletionMenuCommand)input);

}

void displayMenu() {

    clearConsole();
    displayBigLogo();

    puts("Usun: ");
    puts("1) Aktora [niedostepne]");
    puts("2) Film [niedostepne]");
    puts("3) Studio [niedostepne]");
    puts("4) Role [niedostepne]");

    newLine();

}

bool isValidInput(char input) {
    return input >= '1' && input <= '4';
}

void executeCommand(Database* database, DeletionMenuCommand command) {

    switch(command) {

    case DELETE_ACTOR:
        // [niedostepne]
        break;

    case DELETE_MOVIE:
        // [niedostepne]
        break;

    case DELETE_STUDIO:
        // [niedostepne]
        break;

    case DELETE_ROLE:
        // [niedostepne]
        break;

    }

}
