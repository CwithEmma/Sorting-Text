#include "MediaLibrary.h"
#include "MediaMovie.h" 
#include "MediaTV.h"

using namespace std;

// Load the text media file (based on the string file name fileName)
// Return true if the file creates the media library successfully 
// and false othewise
bool MediaLibrary::loadFile(const char* fileName)
{
    ifstream myFile(fileName);
    string mdLine;
    collection.clear();

    if (myFile.is_open())
    {
        // Make a Media object for EACH line of the file and add to the collection.
        while (getline(myFile, mdLine))
        {
            IMedia* p_nextMedia = createMedia(mdLine);
            assert(p_nextMedia);
            collection.add(p_nextMedia);
        }
    }
    return false;
}

// Save the media library information to a text file (fileName)
// Return true if successful and false otherwise
bool MediaLibrary::exportLibrary(const char* fileName)
{
    ofstream myStream;
    myStream.open(fileName);

    if (myStream.is_open())
    {
        collection.outCollectionToFile(&myStream);
        myStream.close();
        return true;
    }
    else
    {
        return false;
    }
}

// printLibrary: simply prints the information for each Media object in the collection.
void MediaLibrary::printLibrary()
{
    collection.printCollection();
}


/// <summary>
/// A pointer to a new collection that is made on the heap.
/// Determines if the incoming string is apart of the collection.
/// If found, it adds it to the new collection. 
/// If not found, the new retCollection is automatically delete at the end of the function.
/// </summary>
/// <param name="toFind">The "Word" you are looking for in the file</param>
void MediaLibrary::find(string toFind, MediaCollection* retCollection)
{
    for (int i = 0; i < collection.size(); i++)
    {
        IMedia* m = collection.getElement(i);
        if (m->find(toFind))
        {
            retCollection->add(m);
        }
    }
}

// For a field in the format <fieldName>:<Value>...such as Genre:Action
// return the name of the field ("Genre" for this example) and the value ("Action")
// as a pair of values in a StringPair struct
StringPair MediaLibrary::extractFieldNameVal(string field)
{
    StringPair pair;
    if (field.empty())
    {
        return pair;
    }
    int colonPos = field.find(':');
    string fieldName = field.substr(0, colonPos);
    string fieldValue = field.substr(colonPos + 1);

    pair.fName = fieldName;
    pair.fValue = fieldValue;
    return pair;
}


// Assumed default data tab delimited/seperated) format: 
// mediaType:XXX name:XXX genre:XXX fileSize:XXX filePath:XXX
// extractFieldPair returns the field at index fieldNum.
// For the example above fieldNum =2 would return "genre:XXX"
// If fieldNum is > the number of fields, the returned string is empty
string MediaLibrary::extractFieldIdx(unsigned int fieldNum, string tabText)
{
    int postTabPos1 = 0;
    int tabPos2 = tabText.find('\t', postTabPos1);
    string field;
    unsigned int count = 0;
    while (tabPos2 > 0 && tabPos2 <= tabText.size())
    {
        assert(count <= fieldNum);
        if (fieldNum == count)
        {
            field = tabText.substr(postTabPos1, tabPos2 - postTabPos1);
            return field;
        }
        postTabPos1 = tabPos2 + 1;
      
        tabPos2 = tabText.find('\t', postTabPos1);
        count++;
    }
    // Only option is the last field MIGHT be the one being sought
    if (fieldNum == count)
    {
        field = tabText.substr(postTabPos1);
        return field;
    }
    return "";
}


IMedia* MediaLibrary::createMedia(string tabText)
{
    int fieldNum = 0;
    string field = extractFieldIdx(fieldNum, tabText);
    while (!field.empty())
    {
        StringPair fieldPair = extractFieldNameVal(field);
        if (fieldPair.fName == FIELDNAME_MEDIATYPE)
        {
            return createMedia(fieldPair.fValue, tabText);
        }
        fieldNum++;
        field = extractFieldIdx(fieldNum, tabText);
    }
    return NULL;
}

/// <summary>
/// Creates a new object in the child class based on their mTypeTxt
/// </summary>
/// <param name="mTypeTxt"> The type you are looking for </param>
/// <param name="tabText"></param>
/// <returns> a new object in the child classes </returns>
IMedia* MediaLibrary::createMedia(string mTypeTxt, string tabText)
{
    if (mTypeTxt == MEDIA_TYPE_MOVIE)
    {
        return new MediaMovie(tabText);
    }
    else if (mTypeTxt == MEDIA_TYPE_TV)
    {
        return new MediaTV(tabText);
    }
    else if (mTypeTxt == MEDIA_TYPE_TVM)
    {
        return new TVMoments(tabText);
    }
    else
    {
        return new Media(tabText);
    }
}
    
