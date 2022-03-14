#ifndef _KEYWORDACTIONMANAGER_HPP_
#define _KEYWORDACTIONMANAGER_HPP_
#include <string>
#include <iostream>

enum KeywordAction{
    NaN,
    Err,
    Hello,
    Bye
};

class KeywordActionManager{

public:
KeywordAction parseText(std::string text);

};


#endif