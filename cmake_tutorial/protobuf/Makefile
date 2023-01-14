protobuf_path := $(HOME)/Downloads/protobuf-3.21.12
protobuf_inc_path := $(protobuf_path)/src
protobuf_lib_path := $(protobuf_path)/src/.libs
cpp_version := c++17
proto_compiler := $(protobuf_path)/src/protoc

build/protobuf_handler.a : src/protobuf_handler.cc include/imgmask.pb.h build/imgmask.pb.o
	g++ -I$(protobuf_inc_path) -Iinclude/ -c -static -std=$(cpp_version) -o build/protobuf_handler.o  src/protobuf_handler.cc
	ar cr build/protobuf_handler.a build/protobuf_handler.o build/imgmask.pb.o 

src/imgmask.pb.cc include/imgmask.pb.h : data/imgmask.proto
	$(proto_compiler) -Idata imgmask.proto --cpp_out=.
	mv *pb.cc src/
	mv *.pb.h include/

build/imgmask.pb.o : src/imgmask.pb.cc include/imgmask.pb.h
	g++ -I$(protobuf_inc_path) -Iinclude/ -c  -static -std=$(cpp_version) -o build/imgmask.pb.o src/imgmask.pb.cc

clean:
	rm -f build/*.o
	rm -f build/*.pb.o include/*pb.h* src/*pb.c*