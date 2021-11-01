-module(lists1).
-export([min/1, max/1, min_max/1]).

-compile({no_auto_import,[max/2]}).
-compile({no_auto_import,[min/2]}).

min([Head | Tail], Acc) ->
	if
		Head < Acc -> min(Tail, Head);
		true -> min(Tail, Acc)
	end;
min([], Acc) ->
	Acc.

min([Head | Tail]) ->
	min(Tail, Head).

max([Head | Tail], Acc) ->
	if
		Head > Acc -> max(Tail, Head);
		true -> max(Tail, Acc)
	end;
max([], Acc) ->
	Acc.

max([Head | Tail]) ->
	max(Tail, Head).

min_max(L) ->
	{min(L), max(L)}.
