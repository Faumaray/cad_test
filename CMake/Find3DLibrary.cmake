set (3DLibrary_FOUND true)


set (3DLibrary_INCLUDE_DIR
    ${3DLibrary_ROOT_DIR}/include;
)

set (3DLibrary_LIBRARY
    3DLibrary
)

if (UNIX)
    set (3DLibrary_LIBRARY
	${3DLibrary_LIBRARY}
	dl
    )
endif()