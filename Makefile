NAME := endgame
SRC_DIR := $(wildcard src/*.c)
LIB_DIR := resource/graphic_library
FRAMEWORKS := -framework IOKit -framework Cocoa -framework OpenGL -framework CoreAudio

RAYLIB_CFLAGS := -I$(LIB_DIR)
RAYLIB_LIBS := -L$(LIB_DIR) -lraylib

all: $(NAME)

$(NAME): $(SRC_DIR)
	cc -Iinc $^ $(RAYLIB_CFLAGS) $(FRAMEWORKS) $(RAYLIB_LIBS) -o $@

clean:
	rm -rf $(NAME)

uninstall: clean

reinstall: uninstall all
