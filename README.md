# Infix-Expression-Parser

Overview:
- This project aims to implement an infix expression parser in C++ using stacks. The parser will be capable of evaluating arithmetic and logical expressions efficiently.
  
Technical Requirements:
- Parse infix expressions with support for arithmetic and logical operators with the specified precedencies.
- Handle operator precedence according to specified rules.
- Parse an expression given in a string format. The program should be flexible with the given expressions. The user should not worry about writing the spaces between operands and operators.
- Evaluate expressions efficiently.
- The main() program should read expressions from an input file, and then output the evaluation results to the console.
- Provide error handling for invalid expressions or divide-by-zero errors.

Implementation: 
- The implementation will involve creating classes for expression parsing, evaluation, and error handling. The project will adhere to Object-Oriented Programming principles for better organization and scalability.

How to Use:
- Clone the repository to your local machine.
- Compile the source code using a C++ compiler.
- Run the compiled program and provide input expressions to evaluate.

Contributing:
- Fork the repository.
- Create a new branch for your feature or bug fix.
- Make your changes and test thoroughly.
- Submit a pull request detailing your changes.

License:
 - This project is licensed under the MIT License.
   
Author:
 - Athul Jaishankar, Timothy Huffman, Kathleen Dunn.

Version:
 - 1.0.0

Changelog:
 - 1.0.0 (Date): Initial release.

Future Improvements:

-	Support for more operators and functions:
  Improve the parser to support additional operators and functions, this could mean implementing more logic in order for the program to receive various new mathematical, logical, or bitwise operators.

-	Memory Management:
  Make sure memory usage is optimized, especially when dealing with larger expressions. Techniques like object pooling or even smart pointers can efficiently manage memory while avoiding any unnecessary allocations or deallocations.

-	Interactive Mode:
  Allow users to only enter expressions one at a time for immediate feedback or results that can inform the user step by step what procedures or occurring.

-	Error Recovery:
  Having an in-depth error recovery mechanism in order to gracefully handle syntax errors in expressions and provide valuable feedback to users without instantly terminating parsing.

-	Database Integration:
  Integrating a database system into the application to store and manage expression data, user preferences and evaluation results. This integration can provide advantages such as persistence, scalability and data management capabilities.

-	Graphical User Interface (GUI): 
  Developing a GUI application to provide a user-friendly interface for inputting expressions, displaying the results and possibly visualizing the parsing and evaluating process.

-	Support for floating-point numbers:
  Enhancing the parser to support floating-point numbers would make it more powerful and more useful for a wider range of applications.

-	Variable Support:
  Extend the parser to support variables. This would allow users to define and use variables within expressions and enhance the utility of the parser.

-	History Session:
  Implementing a history and session management would allow the users to refer back to previous calculations.

