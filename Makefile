# set g++ version 6
ifndef GXX
        GXX = g++-6
endif

# We use our project directory as a search path so we don't need "../../../.." all over the place.
PROJECT = $(shell pwd)


# include project libs
INCLUDE_PATH +=  -I$(PROJECT)/Bedrock -I$(PROJECT)/Bedrock/plugins -I$(PROJECT)/Bedrock/mbedtls/include -I $(PROJECT)
CXXFLAGS = -g -std=c++14 -fPIC -O2 -Wall -Werror -Wformat-security

.PHONY: all 

all: Bedrock/bedrock GameEngine.o gameengine.so

Bedrock/bedrock:
	cd Bedrock && make bedrock

gameengine.so: GameEngine.h GameEngine.o
	$(GXX) -v $(INCLUDE_PATH) GameEngine.o -o $@ -shared  
	touch /tmp/gameengine.db

GameEngine.o: GameEngine.cpp 
	$(GXX) -v $(CXXFLAGS) $(INCLUDE_PATH) -Wl,--no-undefined GameEngine.cpp -o $@ -c

clean:
	rm GameEngine.o
	rm gameengine.so
	pkill bedrock

clean_all:
	cd Bedrock && make clean
	rm GameEngine.o
	rm gameengine.so
