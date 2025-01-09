CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -O2 -fPIC
CXXFLAGS = -Wall -Wextra -O2 -fPIC `pkg-config --cflags Qt5Core Qt5Gui Qt5Widgets Qt5Charts`
LDFLAGS = `pkg-config --libs Qt5Core Qt5Gui Qt5Widgets Qt5Charts`

TARGET = NetworkMonitor

SRCS_C = src/backend.c
SRCS_CPP = src/frontend.cpp src/main.cpp
OBJS = $(SRCS_C:.c=.o) $(SRCS_CPP:.cpp=.o)
MOC_SRCS = src/moc_frontend.cpp
MOC_OBJS = $(MOC_SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS) $(MOC_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run moc to generate meta-object code
src/moc_frontend.cpp: src/frontend.h
	moc $(shell pkg-config --cflags Qt5Core) $< -o $@

clean:
	rm -f $(OBJS) $(MOC_OBJS) $(TARGET) src/moc_frontend.cpp

.PHONY: all clean