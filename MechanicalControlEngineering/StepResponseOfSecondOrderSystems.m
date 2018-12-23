% 仿真时间区段
t = 0:0.01:3.5;
% 建立数学模型
Omega = 5;
Epsilon1 = 0.2;G1 = tf(Omega.*Omega,[1,2.*Epsilon1.*Omega,Omega.*Omega]);
[y1,T1] = step(G1,t);
% 生成图形
hold on
plot(T1,y1);
hold off
