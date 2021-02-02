make:
	g++ main.cpp -o run.a

run: make
	make
	clear
	./run.a

clean:
	rm run.a