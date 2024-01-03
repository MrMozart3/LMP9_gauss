all:
	cc main.c gauss.c mat_io.c backsubst.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
