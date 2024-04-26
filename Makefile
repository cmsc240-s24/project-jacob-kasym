all: static-analysis Artist.o Venue.o Event.o run-unit-tests EventPlannerAPI.o EventPlannerAPI

EventPlannerAPI: EventPlannerAPI.o Artist.o Venue.o Event.o PastEvent.o venueFunctions.h venueFunctions.cpp artistFunctions.h  artistFunctions.cpp eventFunctions.h eventFunctions.cpp
	g++ -lpthread EventPlannerAPI.o Artist.o Venue.o Event.o PastEvent.o venueFunctions.cpp artistFunctions.cpp eventFunctions.cpp -o EventPlannerAPI

EventPlannerAPI.o: EventPlannerAPI.cpp  Artist.h  Venue.h  Event.h templateSaving.h
	g++ -Wall -c EventPlannerAPI.cpp

Artist.o: Artist.cpp Artist.h
	g++ Artist.cpp -c 

Venue.o: Venue.cpp Venue.h
	g++ Venue.cpp -c

Event.o: Event.cpp Event.h
	g++ Event.cpp -c

PastEvent.o: PastEvent.cpp PastEvent.h Event.h
	g++ PastEvent.cpp -c

static-analysis:
	cppcheck *.cpp

docs: Artist.h
	doxygen doxyfile

ArtistTest: ArtistTest.cpp Artist.o
	g++ -lpthread ArtistTest.cpp Artist.o -o ArtistTest

VenueTest: VenueTest.cpp Venue.o
	g++ -lpthread VenueTest.cpp Venue.o -o VenueTest

EventTest: EventTest.cpp Event.o Artist.o Venue.o
	g++ -lpthread EventTest.cpp Event.o Artist.o Venue.o -o EventTest

PastEventTest: PastEventTest.cpp PastEvent.o Event.o Artist.o Venue.o
	g++ -lpthread PastEventTest.cpp PastEvent.o Event.o Artist.o Venue.o -o PastEventTest
	
run-unit-tests: ArtistTest VenueTest PastEventTest EventTest
	./ArtistTest; ./VenueTest; ./EventTest; ./PastEventTest

clean-code:
	rm -f *.o ArtistTest VenueTest PastEventTest EventTest EventPlannerAPI

clean-docs:
	rm -r -f ./docs

clean: clean-code clean-docs