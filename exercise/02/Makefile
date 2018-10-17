CC = gcc
OBJDIR = bin
exec = reverse sort vector3d

.PHONY: all clean zip

zip: archive.zip

all: $(OBJDIR) $(exec)

clean: 
	rm -r $(OBJDIR)

archive.zip: 
	zip archive.zip . -i *.c -i *.h

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(exec): %: %.c
	$(CC) -o $(OBJDIR)/$@ $<
