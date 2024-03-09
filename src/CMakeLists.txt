set(SRC_FILES
  chessPiece/chessPiece.cpp
  square/square.cpp
  main.cpp
)

set(HEADERS
  chessPiece/chessPiece.h
  square/square.h
  main.h
)



add_executable(${PROJECT_NAME}
  ${HEADERS}
  ${SRC_FILES}
  
)
target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets
)
