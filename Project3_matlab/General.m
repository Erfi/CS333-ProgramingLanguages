% a = 1 %by default all variables are double
% b = uint16(a) %thats how you cast
% 
% help class % tells you all the types
% 
% c = [1 2 3] %vector
% 
% d = [1,2;3,4] % matrix
% .................................................
% %differance between matlab and other programing languages like
% %java or C is that matlab is built up from ground up to be used with
% % matricies and large data sets
% %This makes matlab one of the most efficient programs for statistical 
% %analysis 
% a=3
% b=[3,4,5;1,2,3]
% c= 1:3
% a*b % if no variable assigned a variable "ans" is created by default
% c*b' % transposing b 
% 
% ..................................................
% array = zeros(2,2,2) %this is how you allocate memory for a 2*2*2 matrix
%                      %and you fill it by zeros or ones or rand
%                      %and you can access the slices in the third dimentsion
%                      %as follows:
% array(:,:,1) = [1,2;3,4]
% 
% % a general way to hold matricies is to hold them in a bigger matrix using
% % {} notation
% 
% a = [1,2;3,4]
% b = [4:8;4:8]
% c = [3;3;3;3]
% d = [2,2]
% 
% e = {a,b;c,d}
% 
% %and you can access each sub matrix:
% e{1,1} %returns matrix a
% ...............................................

%data structure
%to create a data structure simply add the data field by using a .
% s.name = 'John Doe'
% s.address = '123 Fake st'
% 
% %adding additional data
% s(2).name = 'Jane Row'
% s(2).address = '124 Fake st'
% 
% %accesing data is like accesing a matrix
% s(1,1).name
% s(1,1)
% ................................................
% 
% a = 'hello'; % put the semicolon if you dont want to see the result on the command line
% b = ' ';
% c = 'world';
% 
% strcat(a,b,c) %dor concatenating strings
% ...............................................
% % adding a '.' before an operation (+ _ / * = ) tells matlab to do that
% % operation piecewise
% ..............................................
% %control flow
% 
% % it uses indentation and end using 'end'
% a = [1,2,3;2,6,4;1,2,round(rand(1)*5)];
% if a(3,3) == 3
%     a = a';
% else
%     a = inv(a);
% end
% 
% %or using a switch statement
% 
% switch a(3,3)
%     case 3
%         a = a';
%     otherwise
%         a = inv(a);
% end
% ..........................................
% %round off errors and symbolic arithmetic 
% %sym() teats the number as rationals hence it takes much longer
% % they all should be of the same type in a n expression for it to work
% clear;
% a = sym(1/3); % to get rid of round off errors use a = sym(1/3)
% b = sym(1/12); % b = sym(1/12)
% n=50;
% y = [a,b]; for i=2:n, y = [y,2.25*y(i)-y(i-1)/2]; end;
% a=1;
% b=1/4;
% n=50;
% x = [a,b]; for i=2:n, x=[x, 2.25*x(i)-x(i-1)/2]; end;
% ind = 1:n+1;
% semilogy(ind,x,ind,y)
% ........................................
% %{
% use tic toc to measure the time it takes [in ms] for a part of a program
% tic
% ...
% program
% ...
% time = toc
% %}
% ........................................







