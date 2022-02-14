mengersponge: mengersponge.o outputtriangle.o
	g++ -o mengersponge mengersponge.o outputtriangle.o

mengersponge.o: mengersponge.cpp outputtriangle.hpp
	g++ -c mengersponge.cpp

outputtriangle.o: outputtriangle.cpp outputtriangle.hpp
	g++ -c outputtriangle.cpp
