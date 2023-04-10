<!DOCTYPE html>
<html>
<head>
</head>
<body>
	<h1>ft_printf</h1>
	<p>This project is an implementation of the printf function in C, as part of the 42 school curriculum. The function allows formatted output to the console, similar to the printf function provided by the standard C library.</p>
	<h2>Usage</h2>
	<p>The ft_printf function is defined in the ft_printf.h header file, and can be called like any other function in your C program. The function takes a format string and a variable number of arguments, and returns the number of characters written to the console.</p>
	<p>The format string can contain format specifiers, which start with the % character, and are followed by a letter indicating the type of the argument, such as d for integer, s for string, c for character, etc.</p>
	<h2>Supported format specifiers</h2>
	<ul>
		<li>%c - character</li>
		<li>%s - string</li>
		<li>%p - pointer</li>
		<li>%d - integer</li>
		<li>%i - integer</li>
		<li>%u - unsigned integer</li>
		<li>%x - hexadecimal integer (lowercase)</li>
		<li>%X - hexadecimal integer (uppercase)</li>
	</ul>

<h2>Examples</h2>
<pre>
ft_printf("Hello, %s!\n", "world"); // output: Hello, world!
ft_printf("%d + %d = %d\n", 2, 2, 4); // output: 2 + 2 = 4
ft_printf("%x\n", 255); // output: ff
</pre>

</body>
</html>
