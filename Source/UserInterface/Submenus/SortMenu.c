#include "CommonIO/BasicIO.h"
#include "Lists/Database.h"
#include "SortMenu.h"
#include "SortMenu/ActorListSortMenu.h"
#include "SortMenu/MovieListSortMenu.h"
#include "SortMenu/StudioListSortMenu.h"
#include "UserInterface/MenuPlayer.h"
#include "UserInterface/Messages.h"

static bool actorListSort(ActorList* actors);
static bool movieListSort(MovieList* movies);
static bool studioListSort(StudioList* studios);

static const MenuData SORT_MENU_DATA = {

    .content =
        "Ktora tabele chcesz posortowac:\n"
        "1) Aktorow\n"
        "2) Filmow\n"
        "3) Studiow nagraniowych\n"
        "4) Rezygnuje...\n",

    .maxOptionValue = 4

};

void sortMenu(Database* database) {

    bool isDatabaseModified = false;

    switch(playMenu(&SORT_MENU_DATA)) {

    case 1:
        isDatabaseModified = actorListSort(&database->actors);
        break;

    case 2:
        isDatabaseModified = movieListSort(&database->movies);
        break;

    case 3:
        isDatabaseModified = studioListSort(&database->studios);
        break;

    }

    if(isDatabaseModified) {
        database->isDatabaseModified = true;
    }

}

bool actorListSort(ActorList* actors) {

    bool isSorted;

    if(isActorListEmpty(actors)) {
        isSorted = false;
        puts(MSG_ACTOR_LIST_IS_EMPTY);
        waitForEnter();
    } else {
        isSorted = actorListSortMenu(actors);
    }

    return isSorted;

}

bool movieListSort(MovieList* movies) {

    bool isSorted;

    if(isMovieListEmpty(movies)) {
        isSorted = false;
        puts(MSG_MOVIE_LIST_IS_EMPTY);
        waitForEnter();
    } else {
        isSorted = movieListSortMenu(movies);
    }

    return isSorted;

}

bool studioListSort(StudioList* studios) {

    bool isSorted;

    if(isStudioListEmpty(studios)) {
        isSorted = false;
        puts(MSG_STUDIO_LIST_IS_EMPTY);
        waitForEnter();
    } else {
        isSorted = studioListSortMenu(studios);
    }

    return isSorted;

}
