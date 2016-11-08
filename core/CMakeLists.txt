set(SRC "core.cpp"
	"data/Position.cpp"
	"data/Data.cpp"
	"data/DataManager.cpp"
	"data/Chunk.cpp"
	"data/Object.cpp"
	"maths/Quaternion.cpp"
	"maths/Vector.cpp")
add_library(core SHARED ${SRC})
target_link_libraries(core pthread)
