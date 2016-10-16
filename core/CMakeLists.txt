set(SRC "core.cpp"
	"Data.cpp"
	"Chunk.cpp"
	"maths/Quaternion.cpp")
add_library(core SHARED ${SRC})
target_link_libraries(core pthread)
