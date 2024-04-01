Python 3.12.2 (tags/v3.12.2:6abddd9, Feb  6 2024, 21:26:36) [MSC v.1937 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> def cstolot(str):
...   lot = []
...   for i in str.split(';')
...   
SyntaxError: expected ':'
>>> def cstolot(str):
...   lot = []
...   for i in str.split(';'):
...       lot.append(tuple(i.split('=')))
...   return lot
... 
>>> cs="a=b;c=d;e=f;g=h"
>>> cstolot(cs)
[('a', 'b'), ('c', 'd'), ('e', 'f'), ('g', 'h')]
>>> cstolot(cs)
[('a', 'b'), ('c', 'd'), ('e', 'f'), ('g', 'h')]
>>> def lottocs(lot):
...     cs=""
...     for i in lot:
...         cs += "=".join(i)+";"
...         return cs.strip(';')
... 
...     
>>> def lottocs(lot):
...     return ";".join(["=".join(i) for i in lot])
... 
>>> lot = [('a', 'b'), ('c', 'd'), ('e', 'f'), ('g', 'h')]
