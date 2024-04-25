#ifndef PASTEVENT_H
#define PASTEVENT_H

#include "Event.h"
#include <vector>

class PastEvent: public Event
{
    private:
        std::vector<std::string> reviews;
    public:
        PastEvent(std::string id, Artist artist, Venue location, std::string date, std::string time);
        
        PastEvent(crow::json::rvalue readValueJson);

        std::string getReview();

        void addReview(std::string review);

        crow::json::wvalue convertToJson();

        void updateFromJson(crow::json::rvalue readValueJson);
};
#endif