TARGET_DIR := bin
TARGET := mpp-wasm

SOURCES_DIR := src
SOURCES := $(wildcard $(SOURCES_DIR)/*.cpp) $(wildcard $(SOURCES_DIR)/**/*.cpp)

OBJECTS_DIR := bin/obj
OBJECTS := $(patsubst $(SOURCES_DIR)/%.cpp,$(OBJECTS_DIR)/%.o,$(SOURCES))

LD_FLAGS := -lwebsocket.js -sFORCE_FILESYSTEM -sNO_EXIT_RUNTIME=1 -s"EXPORTED_RUNTIME_METHODS=['ccall','cwrap']"

.PHONY: all
all: $(TARGET_DIR)/$(TARGET)

$(TARGET_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p bin
	echo $(OBJECTS)
	emcc -o $(TARGET_DIR)/$(TARGET).js $(OBJECTS) $(LD_FLAGS)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	mkdir -p $(dir $@ hacks)
	emcc -c -o "$@" "$<"
