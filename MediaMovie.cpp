/*
        Assigment 4: Emma Mcavoy
        3/11/2021
*/
#include "MediaMovie.h"

MediaMovie::MediaMovie()
    :Media()
{
}

/// <summary>
/// Class the extract fields class to move through the file 
/// </summary>
/// <param name="tabText">the line of the file you are looking at</param>
MediaMovie::MediaMovie(string tabText)
    : Media(tabText)
{
    Media::extractFields(tabText);
}

MediaMovie::~MediaMovie()
{
}

/// <summary>
/// Turn the data back into a string to be printed
/// </summary>
/// <returns> the string with the data from the fill filled in</returns>
string MediaMovie::toString()
{
    string ret = Media::toString();
    ret += "\t" + string("Director:") + director;
    ret += "\t" + string("IMDB URL:") + URL;
    return ret;
}

/// <summary>
/// The added set fields for Movie objects
/// </summary>
/// <param name="fieldPair">The type the object belongs too</param>
void MediaMovie::setFieldInfo(StringPair fieldPair)
{
    if (fieldPair.fName == "Director")
    {
        director = fieldPair.fValue;
    }
    else if (fieldPair.fName == "IMDB URL")
    {
        URL = fieldPair.fValue;
    }
    else
    {
        Media::setFieldInfo(fieldPair);
    }
}

string MediaMovie::getMediaTypeName()
{
    return MEDIA_TYPE_MOVIE;
}

/// <summary>
/// The find string function for objects inside MediaMovie Class
/// Looks through Movie objects to determine if the incoming parameters
/// are apart of their collection. First class the media find, and if not
/// found in there, it checks objects that are just in MediaMovie collection
/// </summary>
/// <param name="toFind">The word you are looking to match</param>
/// <returns>true, if found. False if not found</returns>
bool MediaMovie::find(string toFind)
{
    bool matchFound = Media::find(toFind);
    if (!matchFound)
    {
        matchFound = matchFound || director.find(toFind) < director.length();
        matchFound = matchFound || URL.find(toFind) < URL.length();
    }

    return matchFound;
}