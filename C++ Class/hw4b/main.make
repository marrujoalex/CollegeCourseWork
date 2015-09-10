pw: userpw.o pwfile.o main.o
	g++ userpw.o pwfile.o main.o -o pw

userpw.o: userpw.cpp
	g++ -c userpw.cpp

pwfile.o: pwfile.cpp
	g++ -c pwfile.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *~
