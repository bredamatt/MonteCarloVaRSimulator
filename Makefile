timestamp := $(shell /bin/date +"%Y-%m-%d-%H-%M-%S")
NAME := MCVarEngine-$(timestamp)
CXX := g++
CXXFLAGS := -std=c++11

srcfiles := $(shell find ./src -maxdepth 1 -name "*.cpp")
objects := $(patsubst %.cpp, %.o, $(srcfiles))

all: $(NAME)

$(NAME): $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o bin/$(NAME) $(objects) $(LDLIBS)

depend: .dependencies

.dependencies: $(srcfiles)
	rm -rf .dependencies
	$(CXX) $(CXXFLAGS) -MM $^>>./.dependencies;

clean:
	rm -rf $(objects)

dist-clean: clean
	rm -rf *~ .dependencies
	rm -rf bin/MCVarEngine-*

include .dependencies