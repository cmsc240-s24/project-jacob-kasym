all: static-analysis run-unit-tests docs

static-analysis:
	cppcheck *.cpp

docs: Artist.h
	doxygen doxyfile

ArtistTest: ArtistTest.cpp Artist.h
	g++ ArtistTest.cpp -o ArtistTest

run-unit-tests: ArtistTest
	./ArtistTest

clean-code:
	rm -f

clean-docs:
	rm -r -f ./docs

clean: clean-code clean-docs