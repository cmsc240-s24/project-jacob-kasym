all: Artist.o static-analysis run-unit-tests docs

Artist.o: Artist.cpp Artist.h
	g++ Artist.cpp -c 

static-analysis:
	cppcheck *.cpp

docs: Artist.h
	doxygen doxyfile

ArtistTest: ArtistTest.cpp Artist.cpp Artist.h
	g++ ArtistTest.cpp Artist.o -o ArtistTest

run-unit-tests: ArtistTest
	./ArtistTest

clean-code:
	rm -f Artist.o ArtistTest

clean-docs:
	rm -r -f ./docs

clean: clean-code clean-docs