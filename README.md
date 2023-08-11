<h1 align="center">
	📖 Push_swap | 19 Brussels
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/dspilleb/Push_swap?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/dspilleb/Push_swap?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/dspilleb/Push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/dspilleb/Push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/dspilleb/Push_swap?color=green" />
</p>

## 💡 About the project

>The Push swap project is a very simple and a highly straightforward algorithm project:
<p align="center">
    <b><em>data must be sorted.</em></b>
</p>

## 💻 To use the program 
<h3>you must first compile it with the makefile by using the command 'make' in the shell</h3>

```bash
make all
```

<h3>Then the program must be executed as follows: </h3>

```bash
./push_swap nb1 nb2 nb3 nbn...
```

## ❌ Error handling | Parsing
<h3> These lines should produce an Error :</h3>
<p> <ul>
<li> arguments aren’t integers.
<li> some arguments are bigger/smaller than an integer.
<li> there are duplicates.
</ul> </p>

## ❔ How it works ?
<h3>We have 2 stacks named a and b.</h3>
<h4>At the beginning stack b is empty and stack a contains the number given as arguments</h4>

<h3>Here are the operations we can execute :</h3>

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |
<br>
<p>I decided to implement the stack as a double-linked list and I use ```radix sorting```, which works with the binary of the digits. 
First I set a rank for each number I have to sort, making the smallest number rank 0, which makes me work only with positive values. 
Then I compare each bit and decide whether to move it to stack b or not, repeating this operation until the stack A is sorted.<p>
------------

## 🎯 Goal
<h3>The goal is to sort the stack in an ascending order with the lowest possible number of operations.</h3>
<h4>Space used and comparaisons are not taken into account</4>

------------