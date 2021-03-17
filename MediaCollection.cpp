#include "MediaCollection.h"

using namespace std;

// Reminder: MediaCollection is just a dynamically adjusting array to store media
// objects.  You could use a vector or linked list or anything else for this.

MediaCollection::MediaCollection()
{
    max_size = DEFAULT_MAX_COLLECTION_SIZE;
    mSize = 0;
    ap_media = new IMedia * [max_size];

    // Default is not to delete the media objects
    // Need to call setMainCollection if you want the media deleted.
    isMainCollection = false;
}

MediaCollection::~MediaCollection()
{
    if (ap_media)
    {
        clear();

        delete[] ap_media;
        ap_media = NULL;
        max_size = 0;
    }
}

// To avoid accidentally deleting media objects too early.
void MediaCollection::setMainCollection(bool isMain)
{
    this->isMainCollection = isMain;
}

void MediaCollection::printCollection()
{
    cout << "Media Collection: " << endl;
    for (int i = 0; i < mSize; i++)
    {
        string mediaTxt = ap_media[i]->toString();
        cout << "     " << mediaTxt << endl;
    }
}
void MediaCollection::outCollectionToFile(ofstream* p_stream)
{
    if (p_stream && p_stream->is_open())
        for (int i = 0; i < mSize; i++)
        {
            string mediaTxt = ap_media[i]->toString();
            *p_stream << mediaTxt << endl;
        }
}

void MediaCollection::clear()
{
    if (ap_media && mSize > 0)
    {
        for (unsigned int i = 0; i < mSize; i++)
        {
            assert(ap_media[i]);
            if (isMainCollection)
            {
                delete ap_media[i];
            }
            ap_media[i] = NULL;
        }
        mSize = 0;
    }
}

int MediaCollection::add(IMedia* p_toAdd)
{
    // If there isn't enough space for the new media object
    // copy all media over to a new array and delete the old array
    if (max_size <= mSize)
    {
        max_size *= 2;
        IMedia** ap_newArray = new IMedia * [max_size];
        for (int i = 0; i < mSize; i++)
        {
            ap_newArray[i] = ap_media[i];
        }
        delete[] ap_media;
        ap_media = ap_newArray;
    }
    // Add the new media file
    ap_media[mSize] = p_toAdd;
    mSize++;

    return mSize;
}

// Return the media file pointer found at index idx.  Return NULL
// if that index is out of bounds for the array.
IMedia* MediaCollection::getElement(int idx)
{
    if (idx >= mSize || idx < 0)
    {
        return NULL;
    }
    return ap_media[idx];
}

// Return the size or length of the media file collection.
unsigned int MediaCollection::size()
{
    return mSize;
}