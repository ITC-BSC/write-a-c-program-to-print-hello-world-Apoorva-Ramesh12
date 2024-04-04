Python 3.12.2 (tags/v3.12.2:6abddd9, Feb  6 2024, 21:26:36) [MSC v.1937 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> def leap(year)
SyntaxError: expected ':'
>>> def leap(year):
...     return True if ((year%4==0 and year%100!=0) or y%400==0)
SyntaxError: expected 'else' after 'if' expression
>>> def leap(year):
...     return True if ((year%4==0 and year%100!=0) or y%400==0) else False
... 
>>> leap(2000)
Traceback (most recent call last):
  File "<pyshell#5>", line 1, in <module>
    leap(2000)
  File "<pyshell#4>", line 2, in leap
    return True if ((year%4==0 and year%100!=0) or y%400==0) else False
NameError: name 'y' is not defined
>>> def leap(year):
...     return True if ((year%4==0 and year%100!=0) or year%400==0) else False
... 
>>> leap(2000)
True
>>> leap(2016)
True
>>> leap(1600)
True
>>> leap(2100)
False
>>> leap(1700)
False
>>> leap(1800)
False
>>> def leapy(n):
...     return 1 if n%400==0 else 0 if n%100==0 else 1 if n%4==0 else 0
... 
>>> leapy(2100)
0
