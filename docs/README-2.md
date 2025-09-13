# The JSON Data Format

**JSON** is short for _**"Javascript Object Notation"**_. Standardized By ECMA 404 & RFC 8259

**JSON formatted data is quintessentially a collection of tokens that are placed according to the rules stated in this document.**

<br>

## The JSON Token Set

The JSON token set includes six (6) **structural characters**, strings, numbers, and three literal names. Implementations that generate only objects or arrays where a JSON text is called for will be interoperable in the sense that all implementations will accept these as conforming JSON texts.



### These are the six structural characters:
begin-array = ws %x5B ws ; [ left square bracket
begin-object = ws %x7B ws ; { left curly bracket
end-array = ws %x5D ws ; ] right square bracket 
end-object = ws %x7D ws ; } right curly bracket 
name-separator = ws %x3A ws ; : colon value-separator = ws %x2C ws ; , comma Bray Standards Track [Page 5]RFC 8259 JSON December 2017 Insignificant whitespace is allowed before or after any of the six structural characters. ws = \*( 3. Values %x20 / ; Space %x09 / ; Horizontal tab %x0A / ; Line feed or New line %x0D ) ; Carriage return.
