# set g++ version 6
ifndef GXX
        GXX = g++-6
endif

# We use our project directory as a search path so we don't need "../../../.." all over the place.
PROJECT = $(shell pwd)

# include standard libs
GXXPATH = -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6
# include project libs
GXXPATH +=  -I$(PROJECT)/Bedrock -I$(PROJECT)/Bedrock/mbedtls/include

gameengine: GameEngine.h
	#gcc-6 -v $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) $(LIBRARIES) GameEngine.h
	#gcc-6 -v -I/usr/include/c++/6 -I/usr/include/x86_64-linux-gnu/c++/6 GameEngine.h
	$(GXX) -v $(GXXPATH) GameEngine.h

test:
	cd test && $(MAKE)

clean:
	cd test && make clean
