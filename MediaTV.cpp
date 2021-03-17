/*
        Assigment 4: Emma Mcavoy
        3/11/2021
*/
#include "MediaTV.h"

// Constructor
MediaTV::MediaTV()
    :Media(),
    episode(0),
    Season(0)
{
}

// Destructor
MediaTV::~MediaTV()
{
}

/// <summary>
/// Class the extract fields class to move through the file 
/// </summary>
/// <param name="tabText">the line of the file you are looking at</param>
MediaTV::MediaTV(string tabText)
    :Media(),
    episode(0),
    Season(0)
{
    Media::extractFields(tabText);
}

/// <summary>
/// Turn the data back into a string to be printed
/// </summary>
/// <returns> the string with the data from the fill filled in</returns>
string MediaTV::toString()
{
    string ret = Media::toString();
    ret += "\t" + string("Episode:") + to_string(episode);
    ret += "\t" + string("Season:") + to_string(Season);
    return ret;
}

/// <summary>
/// The added set fields for TV objects
/// </summary>
/// <param name="fieldPair">The type the object belongs too</param>
void MediaTV::setFieldInfo(StringPair fieldPair)
{
    if (fieldPair.fName == "Episode")
    {
        episode = stoi(fieldPair.fValue);
    }
    else if (fieldPair.fName == "Season")
    {
        Season = stoi(fieldPair.fValue);
    }
    else
    {
        Media::setFieldInfo(fieldPair);
    }
}

string MediaTV::getMediaTypeName()
{
    return MEDIA_TYPE_TV;
}

/* 
        Child Class of MediaTV
*/  

//Constructor
TVMoments::TVMoments()
    :MediaTV(),
    start(0),
    end(0),
    rating(0)
{
}

// Destructor
TVMoments::~TVMoments()
{
}


TVMoments::TVMoments(string tabText)
    :MediaTV(),
    start(0),
    end(0),
    rating(0)
{
    Media::extractFields(tabText);
}

/// <summary>
/// Turn the data back into a string to be printed
/// </summary>
/// <returns> the string with the data from the fill filled in</returns>
string TVMoments::toString()
{
    string ret = MediaTV::toString();
    ret += "\t" + string("Start:") + to_string(start);
    ret += "\t" + string("End:") + to_string(end);
    ret += "\t" + string("Rating:") + to_string(rating);
    return ret;
}

/// <summary>
/// Sub-Child Class for Media TV
/// </summary>
/// <param name="fieldPair">Takes in String from file</param>
void TVMoments::setFieldInfo(StringPair fieldPair)
{
    if (fieldPair.fName == "Start")
    {
        start = stoi(fieldPair.fValue);
    }
    else if (fieldPair.fName == "End")
    {
        end = stoi(fieldPair.fValue);
    }
    else if (fieldPair.fName == "Rating")
    {
        rating = stoi(fieldPair.fValue);
    }
    else
    {
        MediaTV::setFieldInfo(fieldPair);
    }
}

string TVMoments::getMediaTypeName()
{
    return MEDIA_TYPE_TVM;
}
