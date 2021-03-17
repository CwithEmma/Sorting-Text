#pragma once
/*
        Assigment 4: Emma Mcavoy
        3/11/2021
*/
#include <string>

/// <summary>
/// Completely virutal class, to make Media an abstract class
/// Base Class for the project
/// </summary>
class IMedia
{
public:
	IMedia();
	virtual ~IMedia();

    virtual std::string toString() = 0;

    virtual unsigned long long getFileSize() = 0;

    virtual std::string getName() = 0;

    virtual std::string getPath() = 0;

    virtual bool find(std::string toFind) = 0;
};

