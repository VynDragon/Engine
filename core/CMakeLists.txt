set(SRC "core.cpp"
	"Chunk.cpp"
	"parts/Position.cpp"
	"parts/Data.cpp"
	"maths/Quaternion.cpp"
	"maths/Vector.cpp")
add_library(core SHARED ${SRC})
target_link_libraries(core pthread)
