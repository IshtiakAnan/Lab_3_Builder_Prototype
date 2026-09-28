# CSE 3206 Software Engineering Sessional
# Lab 3: Design Pattern Analysis & Implementation
# Group 2: Builder & Prototype Patterns

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

all: builder prototype

builder: Builder_Pattern/builder_pattern.cpp
	$(CXX) $(CXXFLAGS) Builder_Pattern/builder_pattern.cpp -o Builder_Pattern/builder_pattern

prototype: Prototype_Pattern/prototype_pattern.cpp
	$(CXX) $(CXXFLAGS) Prototype_Pattern/prototype_pattern.cpp -o Prototype_Pattern/prototype_pattern

run-builder: builder
	@echo "================ RUNNING BUILDER PATTERN ================"
	@./Builder_Pattern/builder_pattern

run-prototype: prototype
	@echo "================ RUNNING PROTOTYPE PATTERN ================"
	@./Prototype_Pattern/prototype_pattern

run: run-builder run-prototype

clean:
	rm -f Builder_Pattern/builder_pattern Prototype_Pattern/prototype_pattern

.PHONY: all builder prototype run-builder run-prototype run clean
