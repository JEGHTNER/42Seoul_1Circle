<!DOCTYPE html>
<html>
<head>
</head>
<body>
	<h1>Libft</h1>
  <p>Libft is a custom C library created to provide various useful functions not included in the standard C library. It is a required project at 42, the French programming school, and serves as a foundation for many other projects.</p>

<p>The library includes functions related to memory management, string manipulation, character manipulation, and other commonly used tasks, as well as more specialized functions such as sorting algorithms and linked list manipulation.</p>

<h2>Getting Started</h2>

<p>To use Libft in your project, simply include the `libft.h` header file and link your project to the `libft.a` library. The library can be compiled using the `Makefile` included in the repository.</p>

<pre><code>make</code></pre>

<h2>Usage</h2>

<p>The functions in Libft are organized into several categories based on their functionality. Below is a brief overview of each category:</p>

<h3>Memory Management</h3>

<p>Functions related to memory allocation, deallocation, and manipulation.</p>

<ul>
	<li><code>ft_memset</code> - Fill a block of memory with a specified value.</li>
	<li><code>ft_memcpy</code> - Copy a block of memory from one location to another.</li>
	<li><code>ft_memccpy</code> - Copy a block of memory from one location to another until a specified character is encountered.</li>
	<li><code>ft_memmove</code> - Copy a block of memory from one location to another, handling overlaps correctly.</li>
	<li><code>ft_memchr</code> - Find the first occurrence of a character in a block of memory.</li>
	<li><code>ft_memcmp</code> - Compare two blocks of memory.</li>
</ul>

<h3>String Manipulation</h3>

<p>Functions for manipulating and analyzing strings.</p>

<ul>
	<li><code>ft_strlen</code> - Get the length of a string.</li>
	<li><code>ft_strlcpy</code> - Copy a string up to a specified size.</li>
	<li><code>ft_strlcat</code> - Append a string to another string, up to a specified size.</li>
	<li><code>ft_strchr</code> - Find the first occurrence of a character in a string.</li>
	<li><code>ft_strrchr</code> - Find the last occurrence of a character in a string.</li>
	<li><code>ft_strncmp</code> - Compare two strings up to a specified length.</li>
	<li><code>ft_strnstr</code> - Search a string for a specified substring.</li>
</ul>

<h3>Character Manipulation</h3>

<p>Functions for manipulating individual characters.</p>

<ul>
	<li><code>ft_isalpha</code> - Check if a character is alphabetic.</li>
	<li><code>ft_isdigit</code> - Check if a character is a digit.</li>
	<li><code>ft_isalnum</code> - Check if a character is alphanumeric.</li>
	<li><code>ft_isascii</code> - Check if a character is a valid ASCII character.</li>
	<li><code>ft_isprint</code> - Check if a character is printable.</li>
  <li><code>ft_toupper</code> - Convert a character to uppercase.</li>
  <li><code>ft_tolower</code> - Convert a character to lowercase.</li>
</ul>
 <h3>Other Functions</h3>

<p>Other commonly used functions.</p>

<ul>
	<li><code>ft_atoi</code> - Convert a string to an integer.</li>
	<li><code>ft_calloc</code> - Allocate memory and initialize it to zero.</li>
	<li><code>ft_strdup</code> - Duplicate a string.</li>
	<li><code>ft_substr</code> - Extract a substring from a string.</li>
	<li><code>ft_strjoin</code> - Join two strings.</li>
	<li><code>ft_strtrim</code> - Trim whitespace from the beginning and end of a string.</li>
	<li><code>ft_split</code> - Split a string into substrings based on a delimiter.</li>
	<li><code>ft_itoa</code> - Convert an integer to a string.</li>
</ul>

<h3>Bonus Functions</h3>

<p>Additional functions included in the bonus part of the project.</p>

<ul>
	<li><code>ft_lstnew</code> - Create a new linked list node.</li>
	<li><code>ft_lstadd_front</code> - Add a node to the beginning of a linked list.</li>
	<li><code>ft_lstsize</code> - Get the size of a linked list.</li>
	<li><code>ft_lstlast</code> - Get the last node in a linked list.</li>
	<li><code>ft_lstadd_back</code> - Add a node to the end of a linked list.</li>
	<li><code>ft_lstdelone</code> - Delete a single node from a linked list.</li>
	<li><code>ft_lstclear</code> - Delete an entire linked list.</li>
	<li><code>ft_lstiter</code> - Apply a function to each node in a linked list.</li>
	<li><code>ft_lstmap</code> - Create a new linked list by applying a function to each node in an existing linked list.</li>
</ul>
