include ../Makefile.compilation

test_array: Point2D.o Polyligne_tab.o Polyligne_tab_test.o seatest.o
	$(LD) -o Polyligne_tab_test Point2D.o Polyligne_tab.o Polyligne_tab_test.o seatest.o $(LDFLAGS)

Polyligne_tab_test.o: Polyligne_tab_test.c
	$(CC) -c Polyligne_tab_test.c -o Polyligne_tab_test.o $(CFLAGS)

Polyligne_tab.o: Polyligne_tab.c Polyligne.h 
	$(CC) -c Polyligne_tab.c -o Polyligne_tab.o $(CFLAGS)

test_list: Point2D.o Polyligne_liste.o Polyligne_liste_test.o seatest.o
	$(LD) -o Polyligne_liste_test Point2D.o Polyligne_liste.o Polyligne_liste_test.o seatest.o $(LDFLAGS)

Polyligne_liste_test.o: Polyligne_liste_test.c
	$(CC) -c Polyligne_liste_test.c -o Polyligne_liste_test.o $(CFLAGS)

Polyligne_liste.o: Polyligne_liste.c Polyligne.h
	$(CC) -c Polyligne_liste.c -o Polyligne_liste.o $(CFLAGS)

Point2D.o: Point2D.c Point2D.h
	$(CC) -c Point2D.c -o Point2D.o $(CFLAGS)


seatest.o: seatest.c seatest.h
	$(CC) -c seatest.c -o seatest.o $(CFLAGS)

clean:
	rm -f *.o test_array test_list -r doc