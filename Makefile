prefix = /usr/local

CXX = gcc
CXXFLAGS = -I.
DEPS = maxcontig.h post_script.h
OBJ = main.o maxcontig.o post_script.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

maxcontig: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

install: maxcontig
	install -D maxcontig \
		$(DESTDIR)$(prefix)/bin/

.PHONY: clean

clean:
	rm -f *.o
