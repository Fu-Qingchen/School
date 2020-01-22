% Introduction to linear Algebra
% 2.1 Vectors and Linear Equations
%% Problem 23
A = [1 2;3 4];
x = [5 -2]';
b = [1 7]';
% disp(b - A*x)
%% Promble 24
A = eye(3);
v = [3:5]';
% disp(A*v);
%% Problem 25
A = ones(4);
v = ones(4,1);
B = eye(4) + ones(4);
w = zeros(4,1) + 2*ones(4,1);
% disp(B*w)
%% Problem 30
u = [0;1];
x = u;
k = 0:10;
A = [.8 .3; .2 .7];
for j = 1:10
    u = A*u;
    x = [x u];
end
plot(k,x)