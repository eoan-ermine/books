-module(time).
-export([swedish_date/0]).

swedish_date() ->
	{Y, M, D} = date(),
	string:right(string:slice(integer_to_list(Y), 2, 2), 2, $0) ++ string:right(integer_to_list(M), 2, $0) ++ string:right(integer_to_list(D), 2, $0).
