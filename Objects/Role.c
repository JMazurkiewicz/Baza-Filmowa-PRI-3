#include "Objects/Role.h"

bool hasRoleTheseParams(const Role* role, const Actor* actor, const Movie* movie) {
    return role->actor == actor && role->movie == movie;
}
