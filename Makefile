all:
	cc /src/main.c /src/gauss.c /src/mat_io.c /src/backsubst.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
