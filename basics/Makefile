CXX := clang++
CXXINCFLAGS := -std=c++17 # -stdlib=libc++ # -I /home/maran/eclipse/boost_1_62_0 -Werror=narrowing #-O3
CXXFLAGS := -Wall -g $(CXXINCFLAGS) # -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
#CXXDEFS := -DDEBUG
#LDFLAGS := -lpthread
SRC := $(wildcard *.cpp)
TARGET := $(SRC:%.cpp=bin/%)

all: | bin $(TARGET)

bin/% : %.cpp
	$(CXX) $(CXXFLAGS) $(CXXDEFS) $< -o $@ $(LDFLAGS)

bin:
	mkdir bin

clean:
	rm -fr bin/ *~
