#include "CommonIO/BasicIO.h"
#include "CommonIO/ConditionalInput.h"
#include "FileIO/DatabaseFile.h"
#include "FileIO/Deserialization.h"
#include "FileIO/FileSystem.h"
#include "Lists/Database.h"
#include "UserInterface/Backup.h"
#include "UserInterface/Logo.h"

void backup(Database* database) {

    if(doesFileExist(BACKUP_FILE_NAME)) {

        clearConsole();
        displayLogo();
        printString("Dostepna jest kopia zapasowa poprzedniej bazy.\nCzy chcialbys z niej skorzystac (T/N): ");

        if(scanBoolean()) {
            
            freeDatabase(database);

            if(deserializeDatabase(BACKUP_FILE_NAME, database)) {
                database->isDatabaseModified = true;
                database->fileName[0] = '\0';
            }

        }

        remove(BACKUP_FILE_NAME);

    }

}
