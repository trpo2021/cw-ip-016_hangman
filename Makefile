APP_NAME = hangman
LIB_NAME = libhangman
TEST_NAME = testhangman

CXX = g++

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
CPPFLAGS_TEST = -I src -I thirdparty -MP -MMD
LDFLAGS = 
LDLIBS =

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

THPY_DIRTY = thirdparty
SFML_DIR = SFML-2.5.1
SFML_INC_DIR = include
SMFL_LIB_DIR = lib

SFMLLIB_PATH = -L $(THPY_DIRTY)/$(SFML_DIR)/$(SMFL_LIB_DIR)
SFMLINC_PATH = -I $(THPY_DIRTY)/$(SFML_DIR)/$(SFML_INC_DIR)
SFMLLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)
TEST_DEPS = $(TEST_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH) 

#	sudo apt-get install libsfml-dev
#	export LD_LIBRARY_PATH=/home/vl1ts/cw-ip-016_hangman/thirdparty/SFML-2.5.1/lib/ && cd bin && ./$(APP_NAME)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(SFMLLIB_PATH) $^ -o $@ $(LDFLAGS) $(LDLIBS) $(SFMLLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)%.o: $(SRC_DIR)/$(APP_NAME)/%.$(SRC_EXT)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(SFMLINC_PATH) $< -o $@
	
$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)%.o: $(SRC_DIR)/$(LIB_NAME)/%.$(SRC_EXT)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(SFMLINC_PATH) $< -o $@

.PHONY: test
test: $(TEST_PATH)
	./$(TEST_PATH)

-include $(TEST_DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CXX) $(CFLAGS) $(CPPFLAGS_TEST) $(SFMLLIB_PATH) $^ -o $@ $(LDFLAGS) $(LDLIBS) $(SFMLLIBS)

$(OBJ_DIR)/$(TEST_DIR)%.o: $(TEST_DIR)/%.$(SRC_EXT)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS_TEST) $(SFMLINC_PATH) $< -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
