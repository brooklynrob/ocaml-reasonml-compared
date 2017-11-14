(* ocamlbuild basicmodules.byte basicmodules.ml *)
(* See https://youtu.be/24S5u_4gx7w?t=8m22s for some context *)

open Printf;;

module type MyComponent = sig
	type t = string
	val greeting : t
	val count : int
end

module BaseComponent : MyComponent = struct
	type t = string;;
	let greeting = "Hello from base component";;
	let count = 10;;
end

module ActualComponent = struct
	include BaseComponent;;
	let greeting = "Hello from actual component in OCaml";;
	let printgreeting = print_endline (greeting);;
end

let () = ActualComponent.printgreeting;
