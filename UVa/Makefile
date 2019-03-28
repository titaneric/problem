CXX=g++ -std=c++11
%: %.cpp
	$(CXX) -o  $@ $< -g
%: %.c
	$(CC) -o  $@ $< -g
.PHONY: clean
clean:
	@rm -rf  *.o
