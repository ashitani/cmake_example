add_library(hoge STATIC hoge.c)
target_include_directories(hoge PUBLIC ${PROJECT_SOURCE_DIR}/hoge)
