all: chatroom client

chatroom: chatroom.cpp tcp.hpp numeric_type_header.hpp
	g++ -std=c++14 chatroom.cpp -lboost_system -lpthread -o chatroom

client: client.cpp tcp.hpp numeric_type_header.hpp
	g++ -std=c++14 client.cpp -lboost_system -lpthread -o client

clean:
	rm chatroom
	rm client
