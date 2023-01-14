opencv_path := /usr/local/include/opencv4
opencv_lib_path := /usr/local/lib
protobuf_path := $(HOME)/Downloads/protobuf-3.21.12
protobuf_inc_path := $(protobuf_path)/src
protobuf_lib_path := $(protobuf_path)/src/.libs
cpp_version := c++17

application: opencv/build/opencv_handler.o protobuf/build/protobuf_handler.a application.cpp
	cd opencv; $(MAKE)
	cd protobuf; $(MAKE)
	g++ opencv/build/opencv_handler.o protobuf/build/protobuf_handler.a application.cpp  -I$(opencv_path) -I$(protobuf_inc_path) -Iopencv/include -Iprotobuf/include  -L$(protobuf_lib_path)  -L$(opencv_lib_path) -L$(opencv_lib_path)/opencv4/3rdparty -lprotobuf -lopencv_calib3d -lopencv_core -lopencv_dnn -lopencv_features2d -lopencv_flann -lopencv_gapi -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_video -lopencv_videoio -lIlmImf -lade -littnotify -llibjpeg-turbo -llibopenjp2 -llibpng -llibprotobuf -llibtiff -llibwebp -lquirc -ltegra_hal -lzlib -o application -std=c++17

clean:
	rm -f *.o
	rm -f *.pb.*
print: 
	export DYLD_LIBRARY_PATH=/Users/pranav-pt6814/Downloads/protobuf-3.21.12/src/.libs
	echo $(opencv_libraries)
# -lopencv_calib3d -lopencv_core -lopencv_dnn -lopencv_features2d -lopencv_flann -lopencv_gapi -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_video -lopencv_videoio opencv4