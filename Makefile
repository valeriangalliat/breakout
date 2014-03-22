BINDIR = bin
INCDIR = include
SRCDIR = src
OBJDIR = obj

CFLAGS += -Wall -I$(INCDIR) -O3
LDLIBS += -lncurses

TARGET = breakout

SOURCES = $(shell find $(SRCDIR) -type f -name *.c)
SOURCE_DIRS = $(shell find $(SRCDIR) -mindepth 1 -type d)

OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJECT_DIRS = $(SOURCE_DIRS:$(SRCDIR)/%=$(OBJDIR)/%)

DIRS = $(BINDIR) $(OBJDIR) $(OBJECT_DIRS)
ALL = $(DIRS) $(BINDIR)/$(TARGET)

all: $(ALL)

debug: CFLAGS += -DDEBUG -g
debug: $(ALL)

clean:
	$(RM) -r $(BINDIR) $(OBJDIR)

$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	mkdir $@
