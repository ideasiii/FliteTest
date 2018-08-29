


include_directories (
	"include"
	"../flite/include"

	)


add_library (analyze
    STATIC
   src/Label.cpp
   src/Text.cpp
   src/Analyze.cpp
   )
target_link_libraries(analyze   flite)



