a = 1 %by default all variables are double
b = uint16(a) %thats how you cast

help class % tells you all the types

c = [1 2 3] %vector

d = [1,2;3,4] % matrix
.................................................
%differance between matlab and other programing languages like
%java or C is that matlab is built up from ground up to be used with
% matricies and large data sets
%This makes matlab one of the most efficient programs for statistical 
%analysis 
a=3
b=[3,4,5;1,2,3]
c= 1:3
a*b
c*b' % transposing b 

..................................................
array = zeros(2,2,2) %this is how you allocate memory for a 2*2*2 matrix
                     %and you fill it by zeros of ones
                     %and you can access the slices in the third dimentsion
                     %as follows:
array(:,:,1) = [1,2;3,4]

% a general war to hold matricies is to hold them in a bigger matrix using
% {} notation

a = [1,2;3,4]
b = [4:8;4:8]
c = [3;3;3;3]
d = [2,2]

e = {a,b;c,d}

%and you can access each sub matrix:
e{1,1} %returns matrix a
...............................................

%data structure
%to create a data structure simply add the data field by using a .
s.name = 'John Doe'
s.address = '123 Fake st'

%adding additional data
s(2).name = 'Jane Row'
s(2).address = '124 Fake st'

%accesing data is like accesing a matrix
s(1,1).name
s(1,1)
................................................







