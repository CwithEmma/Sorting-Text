/*
        Assigment 4: Emma Mcavoy
        3/11/2021
*/
#pragma once
#include "Media.h"

/// <summary>
/// Child Class of Media 
/// </summary>
class MediaMovie : public Media
{
public:
    MediaMovie();
    MediaMovie(string tabText);
    virtual ~MediaMovie();

    virtual string toString();

    bool find(string toFind);

protected:
    void setFieldInfo(StringPair fieldPair);
    virtual string getMediaTypeName();

protected:
    string director;
    string URL;
};