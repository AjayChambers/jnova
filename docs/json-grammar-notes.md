# **JSON Grammar in Reference to JNOVA**

<!-- TODO: Check punctuation and assess the accuracy of the statements made. -->

The following documentation includes references to the _[JNOVA library & parser](https://github.com/AjayChambers/jnova)_, the ECMA JSON standard _[ECMA-404](https://ecma-international.org/publications-and-standards/standards/ecma-404/)_, the **IETF** defined standard _[RFC-8259](https://rfc-archive.org/getrfc.php?rfc=8259#gsc.tab=0)_, and the _[Unicode Encoding Format](https://www.unicode.org/versions/Unicode17.0.0/)_. The purpose of this document is to help readers better understand the JSON data format in respect to its ECMA-404 standard, and how JNOVA manages to follow the standard to enable users to work with, to create, and to write interchangeable JSON data that adheres to JSON's standards.

<br>

## JSON Grammar & Tokens

The tables below attempt to define the JSON grammar. The goal is not to create another JSON grammar, and the tables should NOT be interpreted as a JSON grammar. The tables should be interpreted as JNOVA's interpretation of the JSON grammar. JNOVA tokenizes JSON using a custom created lexical analysis algorithm. The tables help to describe the tokens that JNOVA attempts to create from JSON data during its analysis of any given JSON data source.

### Structural Tokens

|         TOKEN | UNICODE | VAL |   CHAR NAME   | ENUM |
| ------------: | :-----: | :-: | :-----------: | :--: |
|  ObjectOpened |  %x7B   |  {  | Curly Brace L |  1   |
|  ObjectClosed |  %x7D   |  }  | Curly Brace R |  2   |
|   ArrayOpened |  %x5B   |  [  | Sq. Bracket L |  3   |
|   ArrayClosed |  %x5D   |  ]  | Sq. Bracket R |  4   |
|   KV_Operator |  %x3A   |  :  |     Colon     |  5   |
| JsonDelimiter |  %x2C   |  ,  |     Comma     |  6   |

1. The abbreviation in char name 'Sq.' is short for 'square'.
2. ws under UTF-8 Fmt (format) is a reference to a single space. So the field "ws %x7B ws" would **NOT** be "{", rather, it would be " { "

---

## **Value Tokens**

A. Literal Tokens

| TOKEN | UNICODE          | VALUE |   CHAR NAME   |
| ----: | :--------------- | ----: | :-----------: |
|  True | %x74.72.75.65    |  true | Curly Brace L |
| False | %x66.61.6c.73.65 | false | Curly Brace R |
|  Null | %x6e.75.6c.6c    |  null | Sq. Bracket L |

B. Numeric Tokens

Numeric tokens contain a dynamic value, despite being challenged by the fact that numeric tokens cannot be defined using static values, JNOVA is still purposed with the task to tokenize JSON data, which included both dynamic string and number values. First lets consider what defines a number in JSON.

A number is made up of numbers, but not only numbers. Negative numbers have a negative/minus sign (or a **`-`**) prepended to them. Many people don't realize it, but signed numeric values can also have a '+' sign prepended to them. In other words, the characters `+4985` constitute a valid numeric value in JSON (which obviously equates to a positive value of 4,985). Any thing to consider is that the value 01 is invalid. Any number starting with zero, save the number 0, is not valid syntax, therefore, JNOVA has to check for that.

number = [ minus ] int [ frac ] [ exp ]

      decimal-point = %x2E       ; .

      digit1-9 = %x31-39         ; 1-9

      e = %x65 / %x45            ; e E

      exp = e [ minus / plus ] 1*DIGIT

      frac = decimal-point 1*DIGIT
