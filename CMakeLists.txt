cmake_minimum_required(VERSION 2.8)
project( malaga_test )
find_package( OpenCV REQUIRED )

SET(SRC
    main.cpp
    malaga_test.cpp    
   )

ADD_EXECUTABLE( ${PROJECT_NAME} ${SRC} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME}  ${OpenCV_LIBS} )
