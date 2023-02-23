fetch: main.c
	$(CC) main.c -o fetch

install:
	@cp -p fetch $(DESTDIR)$(PREFIX)/bin/fetch
	@chmod 755 $(DESTDIR)$(PREFIX)/bin/fetch

uninstall:
	@rm -rf $(DESTDIR)$(PREFIX)/bin/fetch
