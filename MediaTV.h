/*
        Assigment 4: Emma Mcavoy
        3/11/2021
*/
#pragma once
#include "Media.h"

/// <summary>
/// Child class of Media
/// </summary>
class MediaTV : public Media
{
public:
    MediaTV();
    virtual ~MediaTV();
    MediaTV(string tabText);
    virtual string toString();

    void setFieldInfo(StringPair fieldPair);

protected:
    virtual string getMediaTypeName();
    int episode;
    int Season;
};

/// <summary>
/// Child class of TVMoments
/// Grand-Child class of Media.
/// I uses TVMedia as it parent class and adds on to it features,
/// by creating objects of start, end and rating 
/// </summary>
class TVMoments : public MediaTV
{
public:
    TVMoments();
    virtual ~TVMoments();
    TVMoments(string tabText);
    virtual string toString();
    void setFieldInfo(StringPair fieldPair);

protected:
    virtual string getMediaTypeName();
    int start;
    int end;
    int rating;

};