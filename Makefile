all: Artist.o static-analysis run-unit-tests docs

Artist.o: Artist.cpp Artist.h
	g++ Artist.cpp -c 

static-analysis:
	cppcheck *.cpp

docs: Artist.h
	doxygen doxyfile

ArtistTest: ArtistTest.cpp Artist.cpp Artist.h
	g++ ArtistTest.cpp Artist.o -o ArtistTest

VenueTest: VenueTest.cpp Artist.cpp Artist.h
	g++ VenueTest.cpp -o VenueTest

run-unit-tests: ArtistTest VenueTest
	./ArtistTest; ./VenueTest

clean-code:
	rm -f Artist.o ArtistTest VenueTest

clean-docs:
	rm -r -f ./docs

clean: clean-code clean-docs