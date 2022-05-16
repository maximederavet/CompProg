include ../Makefile.compilation

test_array: point2d.o polyligne_tableau.o polyligne_tableau_test.o seatest.o
	$(LD) -o polyligne_tableau_test point2d.o polyligne_tableau.o polyligne_tableau_test.o seatest.o $(LDFLAGS)

polyligne_tableau_test.o: polyligne_tableau_test.c
	$(CC) -c polyligne_tableau_test.c -o polyligne_tableau_test.o $(CFLAGS)

polyligne_tableau.o: polyligne_tableau.c polyligne.h 
	$(CC) -c polyligne_tableau.c -o polyligne_tableau.o $(CFLAGS)

test_list: point2d.o polyligne_liste.o polyligne_liste_test.o seatest.o
	$(LD) -o polyligne_liste_test point2d.o polyligne_liste.o polyligne_liste_test.o seatest.o $(LDFLAGS)

polyligne_liste_test.o: polyligne_liste_test.c
	$(CC) -c polyligne_liste_test.c -o polyligne_liste_test.o $(CFLAGS)

polyligne_liste.o: polyligne_liste.c polyligne.h
	$(CC) -c polyligne_liste.c -o polyligne_liste.o $(CFLAGS)

point2d.o: point2d.c point2d.h
	$(CC) -c point2d.c -o point2d.o $(CFLAGS)


seatest.o: seatest.c seatest.h
	$(CC) -c seatest.c -o seatest.o $(CFLAGS)

doc:
	doxygen Doxyfile

clean:
	rm -f *.o polyligne_tableau_test polyligne_liste_test test_list -r doc