#include "BasicSerialization.h"
#include "FileIO/Tag.h"
#include "TagSerialization.h"
#include "Utility/Date.h"

void startListSerialization(DatabaseFile* file) {
    serializeByte(file, START_OF_LIST);
}

void startObjectSerialization(DatabaseFile* file) {
    serializeByte(file, START_OF_OBJECT);
}

void endObjectSerialization(DatabaseFile* file) {
    serializeByte(file, END_OF_OBJECT);
}

void endListSerialization(DatabaseFile* file) {
    serializeByte(file, END_OF_LIST);
}

void serializeHeader(DatabaseFile* file) {
    Date now;
    currentDate(&now);
    serializeInt64(file, dateToLongLong(&now));
}
