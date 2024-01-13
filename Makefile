TARGET := mpp-wasm
SOURCES := src/main.cpp
EMCC_FLAGS := -lwebsocket.js -sFORCE_FILESYSTEM -sNO_EXIT_RUNTIME=1 -s"EXPORTED_RUNTIME_METHODS=['ccall','cwrap']"

.PHONY: all
all:
	@mkdir -p bin
	emcc -o bin/$(TARGET).js $(SOURCES) $(EMCC_FLAGS)
