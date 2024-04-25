all: Artist.o Venue.o static-analysis run-unit-tests docs

EventPlannerAPI: EventPlannerAPI.o Artist.o Venue.o Event.o venueFunctions.h venueFunctions.cpp artistFunctions.h  artistFunctions.cpp eventFunctions.h eventFunctions.cpp
	g++ -lpthread EventPlannerAPI.o Artist.o Venue.o Event.o venueFunctions.cpp artistFunctions.cpp eventFunctions.cpp -o EventPlannerAPI

EventPlannerAPI.o: EventPlannerAPI.cpp  Artist.h  Venue.h  Event.h templateSaving.h
	g++ -Wall -c EventPlannerAPI.cpp

Artist.o: Artist.cpp Artist.h
	g++ Artist.cpp -c 

Venue.o: Venue.cpp Venue.h
	g++ Venue.cpp -c

Event.o: Event.cpp Event.h
	G++ Event.cpp -c

PastEvent.o: PastEvent.cpp PastEvent.h
	1

static-analysis:
	cppcheck *.cpp

docs: Artist.h
	doxygen doxyfile

ArtistTest: ArtistTest.cpp Artist.o
	g++ -lpthread ArtistTest.cpp Artist.o -o ArtistTest

VenueTest: VenueTest.cpp Venue.o
	g++ -lpthread VenueTest.cpp Venue.o -o VenueTest

EventTest: EventTest.cpp Event.o
	g++ -lpthread EventTest.cpp Event.o -o EventTest
run-unit-tests: ArtistTest VenueTest
	./ArtistTest; ./VenueTest

clean-code:
	rm -f *.o ArtistTest VenueTest EventPlannerAPI

clean-docs:
	rm -r -f ./docs

clean: clean-code clean-docs