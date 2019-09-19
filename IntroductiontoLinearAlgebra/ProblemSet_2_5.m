% Introduction to linear Algebra
% 2.5 Inverse Matrices
%% Problem36
A = hilb(6);
B = invhilb(6);
C = inv(A);
% disp(B-C)
%% Problem37
P = pascal(4);
% disp(inv(P));
L = abs(pascal(4,1));
% disp(P-L*L')
%% Problem38
A = ones(4);
b = rand(4,1);
disp(A\b)