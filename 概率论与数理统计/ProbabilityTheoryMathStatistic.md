---
title:  概率论与数理统计基础
date:  2018-6-23 22:22:34
categories: 机械相关
tags: [概率论与数理统计,数学]
mathjax: true
---
---

基于《概率论与数理统计》（第三版），ISBN：978-7-04-044003-4；该文档不再更新。

本学期概率论与数理统计采用电脑阅卷形式，共15个选择题，6个大计算题。

2018©Fu_Qingchen，Markdown，LaTeX

# 概率论部分

### 事件的互斥、对立、独立关系

- 事件的互斥：$A\cap B=\varnothing$ ，就是 A、B 不能同时发生

- 事件的对立：$\overline{A}=\Omega-A$ ，就是这两个有且仅有一个发生

- 事件的独立：满足 $P(AB)=P(A)P(B)$ 的两个事件

  - 若$A,B$ 相互独立，那么 $\overline{A},\overline{B}$ 和 $A,B$ 之间也相互独立

  - 若 $A_1,A_2...A_n$ 相互独立，则将任意 m 个事件换成对立事件，形成的新的 n 个事件依然相互独立

  - 若 $A_1,A_2...A_n$ 相互独立，则 n 个事件中至少有 1 个发生的概率为

$$
P(\bigcup\limits_{i=1}^nA_i)=1-P(\prod\limits_{i=1}^{n}\overline{A_i})=1-\prod\limits_{i=1}^{n}[1-P(A_i)]
$$


### 事件概率的加法、减法、对偶律

- 加法：$P(A\cup B)=P(A)+P(B)-P(AB)$
- 减法： $P(A\overline B)=P(A)-P(AB)$
- 对偶律：$\overline{AB}=\overline A\cup\overline B,\overline{A\cup B}=\overline A\cap\overline B$

> 概率性质：（1）非负性$P(A)\geq0$（2）规范性$P(\Omega)=1$（3）有限可加性

### 古典概型

古典概型的两个特征：

- 试验的样本空间只有有限个元素
- 试验中每个基本事件发生概率相同

若事件 A 含有 k 个基本事件，样本空间有 n 个基本事件，则
$$
P(A)=\frac{k}n
$$

> 基本事件两两互斥

【例题】将 n 个球放入 N 个盒子中 (n<N)，设盒子的容量不限，求（1）每个盒子至多一球的概率（2）n  个盒子各放一球的概率

> （1）$P=\frac{N(N-1)...(N-n+1)}{N^n}$ （2）$P=\frac{C_N^nn!}{N^n}$

### 条件概率

事件 A 在事件 B 的条件下发生的概率为条件概率，记为 $P(A|B)$ ，有
$$
P(A|B)=\frac{P(AB)}{P(B)}
$$
化简可以得到乘法公式
$$
P(A|B)P(B)=P(AB)
$$

### 全概率公式、Bayes公式

样本空间的划分：设 $\Omega$ 为样本空间，$B_i$ 为样本空间的事件，若有：

- $B_iB_j=\varnothing,i\neq j$
- $\bigcup\limits_{i=1}^{n}B_i=\Omega$

则称 $B_i$ 为样本空间的一个划分

全概率公式：
$$
P(A)=\sum\limits_{i=1}^n P(A|B_i)P(B_i)
$$
Bayes公式：
$$
P(B_i|A)=\frac{P(AB_i)}{P(A)}=\frac{P(A|B_i)P(B_i)}{\sum\limits_{j=1}^nP(A|B_j)P(B_j)}
$$

> 一般来说：$A$ 为发生的事件，$B_i$ 未发生事件的各个原因

> **使用这两个公式，必须有：$B_1B_2=\varnothing,B_1\cup B_2=\Omega$ 之类的条件**

### 分布函数的定义、性质

随机变量 *X* 的分布函数为：$F(x)=P(X\leq x)$

具有以下性质：

- 单调不减
- 右连续
- $\lim\limits_{x\rightarrow-\infty}F(x)=0,\lim\limits_{x\rightarrow+\infty}F(x)=1$

> $P(x_1\leq X\leq x_2)=F(x_2)-F(x_1-0)$

### 密度函数的定义、性质

对于连续型随机变量 *X* ，若有 $F(x)=\int_{-\infty}^xf(t)dt$ ，则$f(x)$ 为概率密度函数

具有以下性质：

- $f(x)\geq0$
- $\int_{-\infty}^{+\infty}f(x)dx=1$
- $P(x_1\leq X\leq x_2)=\int_{x_1}^{x_2}f(x)dx$
- 若 *f(x)* 连续，则有 $F'(x)=f(x)$

### 一维常见的随机变量及其分布函数和分布律或密度函数，概率的计算

#### 离散型随机变量

| 名称及记号        | 分布律                              | 数学期望  | 方差        | 解释                                     |
| ----------------- | ----------------------------------- | --------- | ----------- | ---------------------------------------- |
| 两点分布          | $P(x=0)=1-p$ $P(x=1)=p$         | $p$       | $p(1-p)$    | 随机变量只能取0,1两个值                  |
| 二项分布 X~b(n,p) | $P(x=k)=C_n^kp^k(1-p)^{n-k}$      | $np$      | $np(1-p)$   | 将 E 独立重复n次，事件A出现 k 次概率     |
| 泊松分布 X~π(λ)   | $P(x=k)=\lambda^ke^{-\lambda}/k!$ | $\lambda$ | $\lambda$   |                                          |
| 几何分布 X~G(p)   | $P(x=k)=(1-p)^{k-1}p$             | $1/p$     | $(1-p)/p^2$ | 成功的概率为p，求首次成功次数为 k 的概率 |

> **泊松定理：$\lim\limits_{n\rightarrow\infty}C_n^kp^k(1-p)^{n-k}=\lambda^ke^{-\lambda}/k!$**（二项分布的泊松近似）

#### 连续性随机变量

| 名称及记号        | 密度函数                          | 数学期望 | 方差        | 分布函数 |
| ---- | ---- | ---- | ---- | ---- |
| 均匀分布 X~U(a,b) | $f(x)=1/(b-a),a\leq x\leq b$ | $(a+b)/2$ | $(b-a)^2/12$ | $F(x)=\frac{(x-a)}{(b-a)},a\leq x\leq b$ |
| 指数分布 X~E(λ) | $f(x)=\lambda e^{-\lambda x},x>0$ | $1/\lambda$ | $1/\lambda^2$ | $F(x)=1-e^{-\lambda x},x>0$ |
| 正态分布 X~N(μ,σ²) | $f(x)=\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{(x-\mu)^2}{2\sigma^2}}$ | $\mu$ | $\sigma^2$ | - |

> 对指数分布：$P(X>x)=e^{-\lambda x}$

> 对正态分布：① 若 X~N(μ,σ²) ，则 Y=(X-μ)/σ~N(0,1) ②

### 一维随机变量函数的分布的计算

> **注意取值范围，这是重难点**

设随机变量 *X* 有概率密度 $f_X(x)$ ，函数 $g(x)$ 处处可导且恒有 $g'(x)>0$ 或 小于0，则 $Y=g(X)$ 是连续型随机变量，其概率密度为：
$$
f_Y(y)=f_X[h(y)]|h'(y)|,\alpha<y<\beta
$$

- $h(x)​$ 为 $g(x)​$ 反函数
- $\alpha=\min(g(-\infty),g(+\infty)),\beta=\max(g(-\infty),g(+\infty))$ （其实 $\alpha<y<\beta$ 就是 $g(x)$ 值域）

> 这是单调的情况。对于非单调的情况，则需要进行分情况讨论，参考例题为课本P64例3

### 二维离散型随机变量

- 联合分布函数 $F(x,y)=P(X\leq x,Y\leq y)=\sum\limits_{i=1}^{+\infty}\sum\limits_{j=1}^{+\infty}p_{ij}$

  - $F(-\infty,-\infty)=F(-\infty,y)=F(x,-\infty)=0,F(+\infty,+\infty)=1$
  - 右连续
  - 对 x,y 单调不减

- 联合分布律 $P(x=i,y=j)=p_{ij},i,j=1,2...$

- 边缘分布函数 $F_X(x)=F(x,+\infty)=\sum\limits_{x_i\leq x}\sum\limits_{j=1}^{+\infty}p_{ij}$ 

- 边缘分布率 $p_{i\cdot}=\sum\limits_{j=1}^{+\infty}p_{ij}$

- 若 X,Y **独立**，有 $p_{ij}=p_{i\cdot}p_{\cdot j}$  

- 在 $Y=y_j$ 条件下随机变量 X 的条件分布律 $P(X\leq x|Y=y_j)=\frac{p_{ij}}{p_{\cdot j}}$


### 二维连续型随机变量的密度函数，边缘密度

- 联合分布函数 $F(x,y)=P(X\leq x,Y\leq y)=\int_{-\infty}^x\int_{-\infty}^yf(u,v)dudv$
  - $\int_{-\infty}^{+\infty}\int_{-\infty}^{+\infty}f(x,y)dxdy=1$
  - 连续
  - 对 x,y 单调不减
  - 若 f(x,y) 在 (x,y) 处连续，有 $\frac{\partial^2F(x,y)}{\partial x\partial y}=f(x,y) $
- 边缘分布函数 $F_X(x)=F(x,+\infty)=\int_{-\infty}^{x}\int_{-\infty}^{+\infty}f(u,v)dudv$
- 边缘分布率 $f_X(x)=\int\limits_Rf(x,y)dy$  
- 若 X,Y **独立**，有 $f(x,y)=f_X(x)f_Y(y)$  
- 在 $Y=y$ 条件下随机变量 X 的条件分布函数 $F_{X|Y}(x|y)=P(X\leq x|Y=y)=\int_{-\infty}^x\frac{f(x,y)}{f_Y(y)}dy$  ,概率密度 $f_{X|Y}(x|y)=f(x,y)/f_Y(y)$

> 对于独立，还有以下性质：假设 X,Y 独立 ,若 h(x),g(x) 连续，那么 h(X),g(Y) 也独立

### 二维正态分布（各参数的意义，边缘分布）

$(X,Y)\sim(\mu_1,\mu_2,\sigma_1,\sigma_2,\rho)$

-  $\rho$ 为 X,Y 的相关系数
- 边缘概率密度函数 $f_X=\int_Re^{-(x-\mu_1)^2/2\sigma_1^2}/(\sqrt{2\pi}\sigma_1)$ (也是正态分布)

### 简单的二维随机变量函数的分布

#### 离散型

分布律为：
$$
P(Z=z_k)=\sum\limits_{g(x_i,y_j)=z_k}p_{ij}
$$
表示对任何满足 $g(x_i,y_j)=z_k$ 的一切 $(x_i,y_j)$ 的 $p_{ij}$ 求和

特别的，当 **Z=X+Y** 时，有
$$
P(Z=z_k)=\sum\limits_{i}P(X=x_i,Y=z_k-x_i)
$$
当 X,Y 独立时，有
$$
P(Z=z_k)=\sum\limits_{i}P(X=x_i)P(Y=z_k-x_i)
$$

#### 连续型

分布律为：
$$
F_Z(z)=P(Z\leq z)=\int\limits_{g(x,y)\leq z}f(x,y)dxdy
$$
表示对任何满足 $g(x_i,y_j)=z_k​$ 的一切 $(x_i,y_j)​$ 的 $p_{ij}​$ 求和

特别的，当 **Z=X+Y** 时，有
$$
f_Z(z)=\int\limits_{R}f(x,z-x)dx
$$
当 X,Y 独立时，有
$$
f_Z(z)=\int\limits_{R}f_X(x)f_Y(z-x)dx
$$
(上式为**卷积公式**)

> 这里可以引出一个推论：**有限个相互独立的正态分布的线性组合还是正态分布**

### 随机变量的数字特征

- **数学期望**：$E=\sum\limits_{i=1}^nxp_{i},E=\int\limits_R xf(x)dx$
  - $E(C)=C$
  - $E(\alpha X+\beta Y)=\alpha E(X)+\beta E(Y)$
  - 若 X,Y 相互**独立**，则 $E(XY)=E(X)E(Y)$
  - 随机变量函数的数学期望 $E[g(X)]=\sum\limits_{i=1}^ng(x_i)p_i=\int\limits_Rg(x)f(x)dx$ (课本上没有证明过程)，对二维的，也有 $E[g(X,Y)]=\sum\limits_{i=1}^\infty\sum\limits_{j=1}^\infty g(x_i,y_j)p_{ij}=\int\limits_R\int\limits_Rg(x,y)f(x,y)dx$
- **方差**：$D(X)=Var(X)=E[X-E(X)]^2=\sum\limits_{i=1}^\infty [x_i-E(X)]^2p_{i}=\int\limits_R[x-E(X)]f(x)dx$
  - $D(X)=E(X^2)-E^2(X)$
  - $D(C)=0$
  - $D(aX+Y)=a^2D(X)$
  - $D(X\pm Y)=D(X)+D(Y)+2E([X-E(X)][Y-E(Y)])$
- **协方差**：$cov(X,Y)=E([X-E(X)][Y-E(Y)])$
  - cov(X,Y) = E(XY) - E(X)E(Y)
  - cov(aX,bY) = abcov(X,Y)
  - cov(X,Y) = D(X±Y) - [D(X) + D(Y)]
  - 若 X,Y 相互独立，则 cov(X,Y) = 0
- **相关系数** $\rho_{XY}=cov(X,Y)/\sqrt{D(X)D(Y)}$
  - $|\rho_{XY}|\leq1$

### 不相关的几个等价条件

> **独立 一定 不相关，不相关 不一定 独立**

### 切比雪夫不等式

$$
P(|X-\mu|\leq\varepsilon)>1-\frac{\sigma^2}{\varepsilon^2}
$$

证明：
$$
P(|X-\mu|\geq\varepsilon)=\int\limits_{|x-\mu|\geq\varepsilon}f(x)dx\leq\int\limits_{|x-\mu|\geq\varepsilon}\frac{|x-\mu|^2}{\varepsilon^2}f(x)dx\leq\frac{1}{\varepsilon^2}\int\limits_R(x-\mu)^2f(x)dx=\frac{\sigma^2}{\varepsilon^2}
$$

### 大数定律样本矩收敛于相应的总体矩

若随机变量 Xi 的数学期望都存在，且满足 $\lim\limits_{n\rightarrow\infty}P(|\frac1n\sum\limits_{i=1}^nX_i-\frac1n\sum\limits_{i=1}^nE(X_i)|<\varepsilon)=1$ 被称为满足大数定理

- 伯努利大数定理：当 Xi~b(n,p) 时：
$$
\lim\limits_{n\rightarrow\infty}P(|\frac{n_A}n-p|<\varepsilon)=1
$$

- 切比雪夫大数定理：

$$
\lim\limits_{n\rightarrow\infty}P(|\overline X-\mu|<\varepsilon)=\lim\limits_{n\rightarrow\infty}P(|\frac1n\sum\limits_{i=1}^nX_i-\frac1n\sum\limits_{i=1}^nE(X_i)|<\varepsilon)=1
$$

- 辛勤大数定理：（独立同分布）

$$
\lim\limits_{n\rightarrow\infty}P(|\frac1n\sum\limits_{i=1}^nX_i-\mu|<\varepsilon)=1
$$

### 中心极限定理

- 独立同分布的随机变量和的标准化当量当 n 足够大时，服从正态分布，即

$$
\frac{\sum\limits_{i=0}^nX_i-n\mu}{\sqrt n\sigma}\sim N(0,1)
$$

- 棣莫弗-拉普拉斯中心极限定理

$$
P(a<X<b)=P(\frac{a-np}{\sqrt{np(1-p)}}\leq\frac{X-np}{\sqrt{np(1-p)}}\leq\frac{b-np}{\sqrt{np(1-p)}})\\
\approx\Phi(\frac{b-np}{\sqrt{np(1-p)}})-\Phi(\frac{a-np}{\sqrt{np(1-p)}})
$$

# 数理统计部分

- t 分布、$\chi^2$分布、F分布的构造及性质；F分布的分位数性质；
- 估计量的评选标准：无偏性和有效性；
- 参数的矩估计和极大似然估计（离散型和连续型）；
- 参数的区间估计（一个正态总体 $\mu$ 和 $\sigma^2$，单侧和双侧）
  - $\mu$ 已知：$(\overline X-u_{\alpha/2}\frac{\sigma}{\sqrt n},\overline X+u_{\alpha/2}\frac{\sigma}{\sqrt n})$
  - $\mu$ 未知：$(\overline X-t_{\alpha/2}(n-1)\frac{S}{\sqrt n},\overline X+t_{\alpha/2}(n-1)\frac{S}{\sqrt n})$
- 假设检验的思想，做法（一个正态总体，单侧及双侧）

------

Learning By Sharing，2018©Fu_Qingchen，Markdown，LaTeX