opencv_path := /usr/local/include/opencv4
opencv_lib_path := $(HOME)/libraries/build_opencv_nodyn/lib
cpp_version := c++17

build/opencv_handler.o : src/opencv_handler.cc
	g++ -I$(opencv_path) -Iinclude/ -O0 -g3 -Wall -c -fmessage-length=0 -std=$(cpp_version) -static -o build/opencv_handler.o src/opencv_handler.cc 

clean:
	rm build/*