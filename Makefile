INC_DIR := ./
SRC_DIR := ./

CC_FILE := $(wildcard ./*.cc)

CC := g++
CPPFLAGS := -std=c++11 -g
LIBS := -lpthread
INC_FILE := $(addprefix -I, $(INC_DIR))

TARGET := aim.exe

$(TARGET):$(CPP_FILE)
	$(CC) $(CPPFLAGS) -o $@ $(CC_FILE) $(INC_FILE) $(LIBS)

clean:
	rm -rf $(TARGET)
