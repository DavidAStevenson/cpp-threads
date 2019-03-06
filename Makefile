APP      = app
OBJS     = thready.o
CXXFLAGS = -g -std=c++14 -Wall -Wextra -pthread
LDFLAGS  = -pthread

all: $(APP)
	./$(APP)

$(APP): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

