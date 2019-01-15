#include "CommonIO/ConditionalInput.h"
#include "FileIO/DatabaseFile.h"
#include "FileIO/Serialization.h"
#include "Lists/Database.h"
#include "UserInterface/Submenus/SerializationMenus.h"

void newDatabase(Database* database) {

    if(saveDatabaseIfModified(database, "Czy chcesz zapisac baze przed utworzeniem nowej (T/N): ")) {
        freeDatabase(database);
    }

}

bool saveDatabaseIfModified(Database* database, StringView message) {

    bool isDatabaseSaved = false;

    if(database->isModified) {

        printString(message);
        isDatabaseSaved = scanBoolean();

        if(isDatabaseSaved) {
            saveDatabaseToFile(database);
        }

    }

    return isDatabaseSaved;

}

void saveDatabaseToFile(Database* database) {

    if(database->isModified) {

        if(strIsEmpty(database->fileName)) {

            puts("Twoja baza nie zostala jeszcze zapisana.");
            saveDatabaseAs(database);

        } else {

            serializeDatabase(database->fileName, database);
            database->isModified = false;

        }

    }

}

void saveDatabaseAs(Database* database) {

    printString("Podaj nazwe pliku dla twojej bazy: ");
    String fileName;
    scanLine(fileName);

    strcpy(database->fileName, fileName);
    saveDatabaseToFile(database);

}

void loadDatabaseFromFile(Database* database) {
    // @todo
}
