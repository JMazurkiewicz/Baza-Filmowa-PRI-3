#include "Lists/Algo/Sort.h"
#include "Lists/MovieList.h"
#include <stddef.h>
#include "UserInterface/MenuPlayer.h"
#include "Utility/String.h"

static bool alphabeticalTitleCompare(const void* left, const void* right);
static bool reversedAlphabeticalTitleCompare(const void* left, const void* right);
static bool lessRunningTimeCompare(const void* left, const void* right);
static bool greaterRunningTimeCompare(const void* left, const void* right);

static const MenuData MOVIE_LIST_SORT_MENU_DATA = {

    .content =
        "Wedlug jakiego kryterium chcesz posortowac tabele filmy?\n"
        "1) Wedlug tytulow (w kolejnosci alfabetycznej)\n"
        "2) Wedlug tytulow (w odwrotnej kolejnosci alfabetycznej)\n"
        "3) Wedlug czasu trwania (rosnaco)\n"
        "4) Wedlug czasu trwania (malejaco)\n"
        "5) Rezygnuje...\n",

    .maxOptionValue = 5

};

bool movieListSortMenu(MovieList* movies) {

    SortCompareFunction compareFunction;

    switch(playMenu(&MOVIE_LIST_SORT_MENU_DATA)) {

    case 1:
        compareFunction = alphabeticalTitleCompare;
        break;

    case 2:
        compareFunction = reversedAlphabeticalTitleCompare;
        break;

    case 3:
        compareFunction = lessRunningTimeCompare;
        break;

    case 4:
        compareFunction = greaterRunningTimeCompare;
        break;

    case 5:
        return false;

    }

    return listSort(movies, offsetof(MovieListNode, value), compareFunction);

}

bool alphabeticalTitleCompare(const void* left, const void* right) {

    const Movie* const leftMovie = left;
    const Movie* const rightMovie = right;

    return strCaseInsensitiveCompare(leftMovie->title, rightMovie->title) < 0;

}

bool reversedAlphabeticalTitleCompare(const void* left, const void* right) {
    return alphabeticalTitleCompare(right, left);
}

bool lessRunningTimeCompare(const void* left, const void* right) {

    const Movie* const leftMovie = left;
    const Movie* const rightMovie = right;

    return leftMovie->runningTime < rightMovie->runningTime;

}

bool greaterRunningTimeCompare(const void* left, const void* right) {
    return lessRunningTimeCompare(right, left);
}
