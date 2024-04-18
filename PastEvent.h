#ifndef PASTEVENT_H
#define PASTEVENT_H

#include "Event.h"
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class PastEvent: public Event<T> 
{
    private:
        bool wasRecorded;
        int attendance;
        std::string recording;
        std::vector<std::string> reviews;
    
};
#endif