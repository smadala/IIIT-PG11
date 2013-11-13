all:
	g++ -Wall -g -O0 -D_FILE_OFFSET_BITS=64 memfs_r.cpp -o MemoryFS_r -lfuse
	g++ -Wall -g -O0 -D_FILE_OFFSET_BITS=64 memfs.cpp -o MemoryFS_rw -lfuse

clean:
	rm -f memfs_r.o MemoryFS_r
	rm -f memfs_rw.o MemoryFS_rw
