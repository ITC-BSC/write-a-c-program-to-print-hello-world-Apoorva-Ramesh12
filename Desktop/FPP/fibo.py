Python 3.12.2 (tags/v3.12.2:6abddd9, Feb  6 2024, 21:26:36) [MSC v.1937 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> def fibo(n):
...   fibo = [0,1]
...   if n<=0:
...       return []
...   if n==1:
...       return [0,]
...   i=2;
...   while((k:=f[i-1]+f[i-2])<n):
...       f.append(k)
...       i+=1
...   return fibo
... 
>>> fibo(10)
Traceback (most recent call last):
  File "<pyshell#15>", line 1, in <module>
    fibo(10)
  File "<pyshell#14>", line 8, in fibo
    while((k:=f[i-1]+f[i-2])<n):
NameError: name 'f' is not defined
>>> def fibo(n):
...   fibo = [0,1]
...   if n<=0:
...       return []
...   if n==1:
...       return [0,]
...   i=2;
...   while((k:=fibo[i-1]+fibo[i-2])<n):
...       fibo.append(k)
...       i+=1
...   return fibo
... 
>>> fibo(10)
[0, 1, 1, 2, 3, 5, 8]
>>> fibo(100)
[0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
