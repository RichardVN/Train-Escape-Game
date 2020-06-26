# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors


# Valgrind Options
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

# Project Name
PROJ = TrainGame

# Zip Name
ZIP = TrainGameZipped
 
# Source Files
SRCS = main.cpp menu.cpp game.cpp player.cpp item.cpp space.cpp passenger.cpp conductor.cpp dining.cpp sleeper.cpp caboose.cpp

# Object Files (created from each source file)
OBJS = $(SRCS:.cpp=.o)

# Linking
# All header files will be brought in as dependencies
${PROJ}: ${OBJS} 
	${CXX} ${LDFLAGS} ${OBJS} -o ${PROJ}

${OBJS}: ${SRCS}  
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

# Names of tags that aren't files. 
.PHONY: default debug clean zip

# Invoke to clean the files to start from scratch
clean:
	rm -f ${PROJ} ${OBJS}

# Invoke to zip all files up or update zipped files
zip: 
	zip $(ZIP).zip *.cpp *.hpp makefile

# Invoke to run valgrind debugging
debug: $(PROJ)
	@valgrind $(VOPT) ./$(PROJ)

default: clean $(PROJ) debug
