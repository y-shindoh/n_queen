# -*- coding: utf-8; tab-width: 4 -*-

SOURCE	:= main.cpp
HEADER	:= nqueen.hpp
EXECUTE	:= nqueen.exe

NUMBER	:= 15

CXX			:= clang++
CXXFLAGS	:= -Wall -Weffc++ -Os

check: $(EXECUTE)
	time ./$(EXECUTE) $(NUMBER)

all: $(EXECUTE)

$(EXECUTE): $(SOURCE) $(HEADER)
	# create: $(@F)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $@

clean:
	rm -f $(EXECUTE)
	find . -name '*~' -print0 | xargs -0 rm -f

.PHONY: check all clean
