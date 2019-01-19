#pragma once

#include <stdbool.h>
#include "Utility/Byte.h"

extern const Byte START_OF_LIST;
extern const Byte START_OF_OBJECT;
extern const Byte END_OF_OBJECT;
extern const Byte END_OF_LIST;

bool isByteTag(Byte symbol);