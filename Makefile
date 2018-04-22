all:
	g++ -o ripper ripper.cpp -lwiringPi
pintest:
	g++ -o pintest pintest.cpp -lwiringPi
