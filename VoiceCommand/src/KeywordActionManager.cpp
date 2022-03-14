#include "KeywordActionManager.hpp"



KeywordAction KeywordActionManager::parseText(std::string text){

    if ((text.find("Say Hello") != std::string::npos) ){
        std::cout << "hello" << std::endl;
        return Hello;
    }else if ((text.find("Say Goodbye") != std::string::npos) ){
         std::cout << "goodbye" << std::endl;
        return Bye;
    } else{
        return NaN;
    }
    return Err;
}

