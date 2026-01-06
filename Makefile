CXX = g++
CXXFLAGS = -Wall -std=c++23

# すべての.cppファイルをソースとして検出
SRCS = $(wildcard *.cpp)
# .cppを除いた名前を実行ファイル名とする
PROGS = $(SRCS:.cpp=)

.PHONY: all clean re

all: $(PROGS)

# 汎用的なコンパイルルール
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)

re: clean all
