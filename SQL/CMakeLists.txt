# Current dir
set(CD ${CMAKE_CURRENT_SOURCE_DIR})

set(SQL_SOURCES
	SQL/Manager/SQLManager.hpp SQL/Manager/SQLManager.cpp

	SQL/TableRecord/TableRecord.hpp SQL/TableRecord/TableRecord.cpp

	PARENT_SCOPE
)