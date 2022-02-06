CXX ?= g++

# path #
SRC_PATH_1 = src/Task1
BUILD_PATH_1 = build_1
BIN_PATH_1 = $(BUILD_PATH_1)/bin

SRC_PATH_2 = src/Task2
BUILD_PATH_2 = build_2
BIN_PATH_2 = $(BUILD_PATH_2)/bin

# executable # 
BIN_NAME_1 = task1_runner
BIN_NAME_2 = task2_runner

# extensions #
SRC_EXT = cpp

# code lists #
# Find all source files in the source directory, sorted by
# most recently modified
SOURCES_1 = $(shell find $(SRC_PATH_1) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
SOURCES_2 = $(shell find $(SRC_PATH_2) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS_1 = $(SOURCES_1:$(SRC_PATH_1)/%.$(SRC_EXT)=$(BUILD_PATH_1)/%.o)
OBJECTS_2 = $(SOURCES_2:$(SRC_PATH_2)/%.$(SRC_EXT)=$(BUILD_PATH_2)/%.o)
# Set the dependency files that will be used to add header dependencies
DEPS_1 = $(OBJECTS_1:.o=.d)
DEPS_2 = $(OBJECTS_2:.o=.d)

# flags #
COMPILE_FLAGS = -std=c++17 -Wall -Wextra -g
INCLUDES = -I include/ -I /usr/local/include
# Space-separated pkg-config libraries used by this project
LIBS = 

.PHONY: default_target
default_target: release

.PHONY: release
release: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS)
release: dirs
	@$(MAKE) all

.PHONY: dirs
dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS_1))
	@mkdir -p $(dir $(OBJECTS_2))
	@mkdir -p $(BIN_PATH_1)
	@mkdir -p $(BIN_PATH_2)

.PHONY: clean
clean:
	@echo "Deleting $(BIN_NAME_1) symlink"
	@echo "Deleting $(BIN_NAME_2) symlink"
	@$(RM) $(BIN_NAME_1)
	@$(RM) $(BIN_NAME_2)
	@echo "Deleting directories"
	@$(RM) -r $(BUILD_PATH_1)
	@$(RM) -r $(BIN_PATH_1)
	@$(RM) -r $(BUILD_PATH_2)
	@$(RM) -r $(BIN_PATH_2)

# checks the executable and symlinks to the output
.PHONY: all
all: $(BIN_PATH_1)/$(BIN_NAME_1) $(BIN_PATH_2)/$(BIN_NAME_2)
	@echo "Making symlink: $(BIN_NAME_1) -> $<"
	@./$(BIN_PATH_1)/$(BIN_NAME_1) || (echo "Few tests have failed!"; exit 1)
	@$(RM) $(BIN_NAME_1)
	@ln -s $(BIN_PATH_1)/$(BIN_NAME_1) $(BIN_NAME_1)
	@echo "Making symlink: $(BIN_NAME_2) -> $<"
	@./$(BIN_PATH_2)/$(BIN_NAME_2) || (echo "Few tests have failed!"; exit 1)
	@$(RM) $(BIN_NAME_2)
	@ln -s $(BIN_PATH_2)/$(BIN_NAME_2) $(BIN_NAME_2)

# Creation of the executable
$(BIN_PATH_1)/$(BIN_NAME_1): $(OBJECTS_1)
	@echo "Linking: $@ $(OBJECTS_1)"
	$(CXX) $(OBJECTS_1) -o $@ ${LIBS} 

$(BIN_PATH_2)/$(BIN_NAME_2): $(OBJECTS_2)
	@echo "Linking: $@ $(OBJECTS_2)"
	$(CXX) $(OBJECTS_2) -o $@ ${LIBS} 

# Add dependency files, if they exist
-include $(DEPS_1)
-include $(DEPS_2)

# Source file rules
# After the first compilation they will be joined with the rules from the
# dependency files to provide header dependencies
$(BUILD_PATH_1)/%.o: $(SRC_PATH_1)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ 
$(BUILD_PATH_2)/%.o: $(SRC_PATH_2)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ 
