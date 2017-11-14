/* rebuild rebasicmodules.byte rebasicmodules.re */
/* rebuild rebasicmodules.byte rebasicmodules.re && ./rebasicmodules.byte */
/* See https://youtu.be/24S5u_4gx7w?t=8m22s for some context */

open Printf;

module type MyComponent =
{
	type t = string;
	let greeting : t;
	let count : int;
};

module BaseComponent : MyComponent = {
	type t = string;
	let greeting = "Hello from base component";
	let count = 10;
};

module ActualComponent = {
	include BaseComponent;
	let greeting = "Hello from actual component in Reason";
	let printgreeting = print_endline (greeting);
};

let () = ActualComponent.printgreeting;
