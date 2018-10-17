% 仿真时间区段
t = 0:0.01:5;
% 建立数学模型
Omega = 5;
Epsilon1 = 0.2;G1 = tf(Omega.*Omega,[1,2.*Epsilon1.*Omega,Omega.*Omega]);
Epsilon2 = 1;G2 = tf(Omega.*Omega,[1,2.*Epsilon2.*Omega,Omega.*Omega]);
Epsilon3 = 5;G3 = tf(Omega.*Omega,[1,2.*Epsilon3.*Omega,Omega.*Omega]);
Epsilon4 = -0.2;G4 = tf(Omega.*Omega,[1,2.*Epsilon4.*Omega,Omega.*Omega]);
Epsilon5 = -1;G5 = tf(Omega.*Omega,[1,2.*Epsilon5.*Omega,Omega.*Omega]);
% 系统响应
[y1,T1] = step(G1,t);
[y2,T2] = step(G2,t);
[y3,T3] = step(G3,t);
[y4,T4] = step(G4,t);
[y5,T5] = step(G5,t);
% 生成图形
hold on
plot(T1,y1,T2,y2,T3,y3,T4,y4,T5,y5);
hold off
