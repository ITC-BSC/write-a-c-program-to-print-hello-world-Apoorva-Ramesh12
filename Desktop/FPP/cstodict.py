Python 3.12.2 (tags/v3.12.2:6abddd9, Feb  6 2024, 21:26:36) [MSC v.1937 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> def cstodict(cs):
...     dict = {}
...     for i in cs.split(';'):
...         key,value = i.split('=')
...         dict[key]=value
...     return dict
... 
>>> cs = "a=b;c=d;e=f;g=h"
>>> cstodict(cs)
{'a': 'b', 'c': 'd', 'e': 'f', 'g': 'h'}
