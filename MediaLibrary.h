#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Media.h"
#include "MediaCollection.h"

using namespace std;

class MediaLibrary
{
public:
    bool loadFile(const char* fileName);
    bool exportLibrary(const char* fileName);
    void printLibrary();

    void find(string toFind, MediaCollection* retCollection);

    // Functions useful for parsing the fields
    //static string extractFieldName(string field);
    //static string extractFieldValue(string field);
    static StringPair extractFieldNameVal(string field);
    static string extractFieldIdx(unsigned int fieldNum, string tabText);


    // A call to createMedia with a line of tab delimited text
    // will create a new media object AND set all the fields in
    // the object based on the text information.
    IMedia* createMedia(string tabText);
    IMedia* createMedia(string mTypeTxt, string tabText);
private:
    MediaCollection collection;
};
