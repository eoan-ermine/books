-module(third).
-export([house/0, get_location/1, get_type/1, get_rooms/1,
		 street/0, first_house/1, last_house/1]).

house() ->
	{{location, "suburbs"}, {type, "detached"}, {rooms, 7}}.

get_location({{location, Location}, {_, _}, {_, _}})
	-> Location.

get_type({{_, _}, {type, Type}, {_, _}})
	-> Type.

get_rooms({{_, _}, {_, _}, {rooms, Rooms}})
	-> Rooms. 

street() ->
	[
		house(), house(), house()
	].


first_house([H|_]) ->
	H.

last_house([H]) ->
	H;

last_house([_|T]) ->
	last_house(T).
	
