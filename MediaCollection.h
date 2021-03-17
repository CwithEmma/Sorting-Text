
#pragma once
#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>
#include "IMedia.h"

/*
Class to hide HOW data is stored.  Arrays are dynamically created and expanded as necessary
You can get individual elements by index or search a collection.
Notice this is a far more general solution than for just this assignment.  Feel free to use
it in the future.
*/

const int DEFAULT_MAX_COLLECTION_SIZE = 40;
class MediaCollection
{
public:
    MediaCollection();
    ~MediaCollection();
    int add(IMedia* p_toAdd);

    void printCollection();
    void outCollectionToFile(std::ofstream* p_stream);

    // Clear all media from the collection
    void clear();

    // To avoid accidentally deleting media objects too early.
    void setMainCollection(bool isMain);

    IMedia* getElement(int idx);
    unsigned int size();

private:
    // Could just use the Vector class (covered later in the term) and
    // it won't change any of the functions or functionality.
    unsigned int mSize;
    IMedia** ap_media;
    unsigned int max_size;
    bool isMainCollection;
};
