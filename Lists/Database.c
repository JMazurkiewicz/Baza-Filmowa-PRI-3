#include "Lists/Database.h"

static void clearDatabaseInfo(Database* database);

void initDatabase(Database* database) {

    initActorList(&database->actors);
    initRoleList(&database->roles);
    initMovieList(&database->movies);
    initStudioList(&database->studios);

    clearDatabaseInfo(database);

}

void freeDatabase(Database* database) {

    freeActorList(&database->actors);
    freeRoleList(&database->roles);
    freeMovieList(&database->movies);
    freeStudioList(&database->studios);

    clearDatabaseInfo(database);

}

void clearDatabaseInfo(Database* database) {
    database->isModified = false;
    database->filePath[0] = '\0';
}
