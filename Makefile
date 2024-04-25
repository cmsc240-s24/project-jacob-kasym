all: Artist.o Venue.o static-analysis run-unit-tests docs

EventPlannerAPI: EventPlannerAPI.o Artist.o Venue.o venueFunctions.h venueFunctions.cpp artistFunctions.h  artistFunctions.cpp
	g++ -lpthread EventPlannerAPI.o Artist.o Venue.o venueFunctions.cpp artistFunctions.cpp -o EventPlannerAPI

EventPlannerAPI.o: EventPlannerAPI.cpp  Artist.h  Venue.h  templateSaving.h
	g++ -Wall -c EventPlannerAPI.cpp

Artist.o: Artist.cpp Artist.h
	g++ Artist.cpp -c 

Venue.o: Venue.cpp Venue.h
	g++ Venue.cpp -c

Event.o: Event.cpp Event.h
	1

PastEvent.o: PastEvent.cpp PastEvent.h
	1

static-analysis:
	cppcheck *.cpp

docs: Artist.h
	doxygen doxyfile

ArtistTest: ArtistTest.cpp Artist.cpp Artist.h Artist.o
	g++ -lpthread ArtistTest.cpp Artist.o -o ArtistTest

VenueTest: VenueTest.cpp Artist.cpp Artist.h Venue.o
	g++ -lpthread VenueTest.cpp Venue.o -o VenueTest

run-unit-tests: ArtistTest VenueTest
	./ArtistTest; ./VenueTest

clean-code:
	rm -f *.o ArtistTest VenueTest EventPlannerAPI

clean-docs:
	rm -r -f ./docs

clean: clean-code clean-docs