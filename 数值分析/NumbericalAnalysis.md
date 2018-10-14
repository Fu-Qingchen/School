---
title:  数值分析
date:  2018-6-25 22:06:15
categories: 计算机相关
tags: [MATLAB,Java,算法]
mathjax: true
---
---

# 绪论部分

- 数值计算环节误差主要来源于 **截断误差、舍入误差** 
- 绝对误差 $\delta[g(x^❀)]=|g'(x)|\delta(x^❀) $ 
- 相对误差 $\delta^❀=\delta/x^❀$ （由此可以推导出 $\delta^❀[g(x)]=|g'(x)|\delta(x^❀)/g(x^❀)$）

> $x^❀$ 为 $x$ 的近似值，$\delta(x^❀)=x^❀-x$

# 插值与拟合部分

- 对于（n+1）个节点，n 次插值多项式存在且唯一

  > 证明：各个节点处建立方程，系数行列式为 范德姆行列式，存在且唯一

  > 如果两个式子次数相同为 n，且对所有（n+1）个节点式子成立，那么这两个式子相等

- 拉格朗日插值基函数 $l_i(x)=\prod\limits_{i=0,i\neq k}^n (x-x_i)/(x_k-x_i)$ 

  - $\sum\limits_{i=0}^nx_i^kl_i(x)=x^k(k\leq n),=x^k-\prod\limits_{i=0}^n(x-x_i)(k>n)$ 
  - $l_i(x_i)=1$

- 拉格朗日插值多项式 $L_i(x)=\sum\limits_{i=0}^ny_il_i(x)$ 

  > 线性插值多项式：$L_1(x)=y_0\frac{x-x_1}{x_0-x_1}+y_1\frac{x-x_0}{x_1-x_0}$ 

- 拉格朗日插值多项式余项 $R_n(x)=\frac{f^{(n+1)}(\xi)}{(n+1)!}\prod\limits_{i=0}^n(x-x_i)$ 

- k阶插商：$f[x_0,x_1,...,x_k]=(f[x_0,x_1,...,x_{k-2},x_k]-f[x_0,x_1,...,x_{k-1}])/(x_k-x_{k-1})$ 

- 牛顿插值多项式：$N_n(x)=f(x_0)+f[x_0,x_1]\times(x-x_0)+...+f[x_0,x_1,...,x_n]\prod\limits_{i=0}^{n-1}(x-x_i)$ 

- 余项：$R_n(x)=f[x_0,x_1,...,x_n,x]\prod\limits_{i=0}^n(x-x_i)$ 

- 重复节点 k 阶插商 $f[x,x,...,x]=f^{(k)}(x)/k!$ 

- k 阶插商表

|      | 0阶   | 1阶      | ...  | n阶            |
| ---- | ----- | -------- | ---- | -------------- |
| x0   | f(x0) | f[x0,x1] | ...  | f[x0,x1,...xn] |
| x1   | f(x1) | f[x1,x2] | ...  |                |
| ...  | ...   | ...      | ...  |                |
| xn   | f(xn) |          | ...  |-                |

  > 埃尔米特插值多项式还可以用  `倒数 / (阶数)!` 代替插商

- 正则方程组

  设有 n 个节点的拟合函数为 $y=a_0+a_1x+...+a_mx^m$ ：

  - $a_on+a_1\sum\limits_{i=0}^nx_i^{1+0}+a_2\sum\limits_{i=0}^nx_i^{2+0}+...+a_m\sum\limits_{i=0}^nx_i^{m+0}=\sum\limits_{i=0}^ny_ix_i^{0}$
  - $a_o\sum\limits_{i=0}^nx_i^{0+1}+a_1\sum\limits_{i=0}^nx_i^{1+1}+a_2\sum\limits_{i=0}^nx_i^{2+1}+...+a_m\sum\limits_{i=0}^nx_i^{m+1}=\sum\limits_{i=0}^ny_ix_i^{1}$
  - $a_o\sum\limits_{i=0}^nx_i^{0+2}+a_1\sum\limits_{i=0}^nx_i^{1+2}+a_2\sum\limits_{i=0}^nx_i^{2+2}+...+a_m\sum\limits_{i=0}^nx_i^{m+2}=\sum\limits_{i=0}^ny_ix_i^{2}$
  - ...
  - $a_o\sum\limits_{i=0}^nx_i^{0+m}+a_1\sum\limits_{i=0}^nx_i^{1+2}+a_2\sum\limits_{i=0}^nx_i^{2+m}+...+a_m\sum\limits_{i=0}^nx_i^{m+m}=\sum\limits_{i=0}^ny_ix_i^{m}$ 

# 数值积分与微分

- 机械求积公式 $\int_a^bf(x)dx=\sum\limits_{i=1}^nA_if(x_i)$ 

- 机械求积公式余项 $R_n[f]=Kf^{(m+1)}(\xi)$ （*m*为代数精度）

  > 其中 $K=\frac{1}{(m+1)!}[\int_a^bf(x)dx-\sum\limits_{i=1}^nA_if(x_i)]$ ，通常化简得 $K=\frac{1}{(m+1)!}[\frac{1}{m+2}(b^{m+2}-a^{m+2})-\sum\limits_{i=1}^nA_if(x_i)]$  

- 中矩形公式 $\int_a^bf(x)dx=f(\frac{a+b}2)(b-a),R_n[f]=\frac{f^{(2)}(\xi)}{24}(b-a)^3$ 

- 梯形公式 $\int_a^bf(x)dx=\frac{f(a)+f(b)}2(b-a),R_n[f]=-\frac{f^{(2)}}{12}(b-a)^3$ 

- 辛普森公式 $\int_a^bf(x)=\frac{f(a)+4f[(a+b)/2]+f(b)}6(b-a),R_n[f]=-\frac{f^{(4)}}{2880}(b-a)^5$ 

- 插值型机械求积公式 $\int_a^bf(x)dx=\sum\limits_{i=1}^n\int_a^bl_i(x)dxf(x_i),R_n[f]=\int_a^b\frac{f^{(n+1)}(\xi)}{(n+1)!}\prod\limits_{i=0}^n(x-x_i)$ 

- 梯形法递推公式 $T_{2n}(h)=\frac12T_n(h)+\frac {h_n}2[\sum\limits f(x_{k+\frac12})]$ 

- $S_n=\frac{4T_{2n}-T_n}3,C_n=\frac{16S_{2n}-S_n}{15},R_n=\frac{64C_{2n}-C_n}{63}$ 

- 高斯求积公式：在高斯求积公式中， 如果选择 n 个节点和求积公式，使其代数精度为 2m-1 ，这样的求积公式叫做高斯求积公式

  > 通常令 $f(x)=1,x,x^2,...,x^k$ ，带入 $\int_a^bf(x)dx=\sum\limits_{i=1}^nA_if(x_i)$ 得到方程组，求解得到 $A_i,x_i$

  > 两点高斯求积公式：$\int_{-1}^1f(x)dx=1\cdot f(\frac{-1}{\sqrt3})+1\cdot f(\frac{1}{\sqrt3})$

- 勒让德多项式 $P_n(x)=\frac{n!}{(2n!)}\frac{d^{n}}{dx^n}[(x^2-1)^n]$ 

  - 正交性：$\int_{-1}^1P_n^2(x)dx=\frac{2}{2n+1}$，勒让德多项式对一切次数低于 n 次的多项式正交
  - 奇偶性：n 为奇数，Pn(x) 为奇函数；n 为偶数，Pn(x) 为偶函数
  - $P_n(\pm1)=\frac{(\pm 2)^nn!}{(2n)!}$ 
  - 递推公式：$P_{n+1}(x)=xP_n(x)-\frac{n^2}{4n^2-1}P_{n-1}(x)$ 
  - Pn(x) 的 n 个零点在（-1,1）上而且都是单根

- 向前差商：$f'(a)=\frac{f(a+h)-f(a)}{h}$ ；中间差商：$f'(a)=\frac{f(a+h)-f(a-h)}{2h}$  

- 利用外推公式求导数$f'(a)$：

  - 先用中间差商法求，得到一个关于 *h* 的函数：$f'(a)=\frac{f(a+h)-f(a)}{h}$ ，记为 G_0(h)
  - 将步长二分，得到 G_0(h/2)，等等 
  - 对 G_0(h) 进行修正，得到 G_1(h) = [4G(h/2) - G(h)] / 3
  - 同理，得到 G_n

------

Learning By Sharing，2018©Fu_Qingchen，Markdown，LaTeX