include(${BIN2H})

file(WRITE "${BIN2H_HEADER_FILE}" "/* This file was auto-generated by cmake */")
bin2h(SOURCE_FILE "${BIN2H_SOURCE_FILE}" HEADER_FILE "${BIN2H_HEADER_FILE}" VARIABLE_NAME "${BIN2H_VARIABLE_NAME}" APPEND NULL_TERMINATE)