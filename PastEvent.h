#ifndef PASTEVENT_H
#define PASTEVENT_H

#include "Event.h"
#include <iostream>
#include <string>
#include <vector>

class PastEvent: public Event
{
    private:
        bool wasRecorded;
        int attendance;
        std::string recording;
        std::vector<std::string> reviews;
    public:
        std::string getRecording();

        void addRecording(std::string file);

        std::string getReview();

        void addReview(std::string review);

        int getAttendance();
};
#endif