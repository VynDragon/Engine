set(SRC "core.cpp"
	"data/Position.cpp"
	"data/Data.cpp"
	"data/DataManager.cpp"
	"data/Chunk.cpp"
	"data/Object.cpp"
	"data/DataExplorer.cpp"
	"physics/Physical.cpp"
	"maths/Quaternion.cpp"
	"maths/Vector.cpp")
add_library(core SHARED ${SRC})
target_link_libraries(core pthread)
