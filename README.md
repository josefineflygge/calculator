# Simple calculator

The simple calculator can add, subtract and multiply values in a set of registers.

The syntax is:
```
<register> <operation> <value>
print <register>
quit
```

Allowed operations are add, subtract and multiply.
`value` can be an integer value or a register.

## To run application from console
```
Simple_Calculator.exe filepath

example:
Simple_Calculator.exe input.txt
```

## Input
- The program allows the user to enter a file with a set of commands, one per line.
- Names consisting of alphanumeric characters are allowed as register names.(*)
- All input is case insensitive
- Invalid commands are ignored and logged to the console

## Evaluation
The calculator uses lazy evaluation to evaluate the set of commands for a register only on `print`.

## Assumptions and modifications
- The program currently takes input from a file, but could be modified to accept input from console
- (*) The name of a register needs to include at least one letter
- The program is customizable and allows for addition of operations
