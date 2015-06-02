---
layout: post
title: "ONTAK 2008 Leonardo's Numbers"
date: 2014-11-19T16:18:00+09:00
comments: true
category: ONTAK
tags: [math, matrix]
---

[Leonardo's Numbers](http://main.edu.pl/en/archive/ontak/2008/leo)

#### 問題概要

****

<div> $ {\displaystyle

L_{0} = L_{1} = 1\\
L_{i+1} = L_{i}+L_{i-1}+1

} $</div>

数列Lについて, 

<div> $ {\displaystyle

\sum_{i=0}^{n} L_{i}^{k}

} $</div>

を求めよ

#### 解法

****

<div> $ {\displaystyle

K_{i} = L_{i} + 1

} $</div>

と数列Kを定義すると

<div> $ {\displaystyle

K_{0} = K_{1} = 2\\
K_{i+1} = K_{i}+K_{i-1}

} $</div>

と数列Kを表現できる(Kの各値はそれぞれフィボナッチ数列の値を2倍したものになる).  
求めたい値はKを用いて

<div> $ {\displaystyle

\sum_{i=0}^{n}L_{i}^{k} = \sum_{i=0}^{n}(K_{i}-1)^{k} \\
 = \sum_{i=0}^{n}\sum_{j=0}^{k} {}_{k}C_{j} (-1)^{k-j} K_{i}^{j} \\
 = \sum_{j=0}^{k} {}_{k}C_{j} (-1)^{k-j} \sum_{i=0}^{n} K_{i}^{j} \\

} $</div>

組合せはパスカルの三角形を予め作っておくことでO(1)で求められる.  
つまり`$\sum_{i=0}^{n} K_{i}^{j}$`を高速に求められればそれをk回繰り返す(高々13回)ことで何とかなりそう.  
`$K_{i+1}$`は`$K_{i}, K_{i-1}$`に, それまでの和`$S_{i,k}$`は`$S_{i-1,k}, K_{i}$`に依存することに注意すると  
フィボナッチ数を求める時みたいに行列累乗で求められることがわかる.  
なぜなら

<div> $ {\displaystyle

K_{i+1}^{j}K_{i}^{k-j} = (K_{i}+K_{i-1})^{j}K_{i}^{k-j}\\
 = \sum_{l=0}^{j} {}_{j}C_{l} K_{i}^{k-j+l} K_{i-1}^{j-l}

} $</div>

となるから.  


<div> $ {\displaystyle

\left(
\begin{array}{cccccc}
        S_{i,k} \\
        K_{i+1}^{k} \\
        \vdots \\
        K_{i+1}^{j}K_{i}^{k-j} \\
        \vdots \\
        K_{i}^{k} \\
\end{array}
\right) = \left(
\begin{array}{cccccc}
        1 & 1 & 0 & \cdots & \cdots & \cdots & 0 \\
        0 & {}_{k}C_{0} & {}_{k}C_{1} & \cdots & \cdots & \cdots & {}_{k}C_{k} \\
        \vdots & \vdots & \vdots & \ddots & \vdots & \ddots & \vdots \\
        0 & {}_{k-j}C_{0} & {}_{k-j}C_{0} & \cdots & {}_{k-j}C_{k-j} & \cdots & 0 \\
        \vdots & \vdots & \vdots & \ddots & \vdots & \ddots & \vdots \\
        0 & {}_{0}C_{0} & 0 & \cdots & \cdots & \cdots & 0
\end{array}
\right) \left(
\begin{array}{cccccc}
        S_{i-1,k} \\
        K_{i}^{k} \\
        \vdots \\
        K_{i}^{j}K_{i-1}^{k-j} \\
        \vdots \\
        K_{i-1}^{k} \\
\end{array}
\right)
} $</div>

つまり

<div> $ {\displaystyle

\left(
\begin{array}{cccccc}
        S_{n,k} \\
        K_{n+1}^{k} \\
        \vdots \\
        K_{n+1}^{j}K_{n}^{k-j} \\
        \vdots \\
        K_{n}^{k} \\
\end{array}
\right) = \left(
\begin{array}{cccccc}
        1 & 1 & 0 & \cdots & \cdots & \cdots & 0 \\
        0 & {}_{k}C_{0} & {}_{k}C_{1} & \cdots & \cdots & \cdots & {}_{k}C_{k} \\
        \vdots & \vdots & \vdots & \ddots & \vdots & \ddots & \vdots \\
        0 & {}_{k-j}C_{0} & {}_{k-j}C_{0} & \cdots & {}_{k-j}C_{k-j} & \cdots & 0 \\
        \vdots & \vdots & \vdots & \ddots & \vdots & \ddots & \vdots \\
        0 & {}_{0}C_{0} & 0 & \cdots & \cdots & \cdots & 0
\end{array}
\right)^{n} \left(
\begin{array}{cccccc}
        2^{k} \\
        2^{k} \\
        \vdots \\
        2^{k} \\
        \vdots \\
        2^{k} \\
\end{array}
\right)
} $</div>

この計算は`$O(k^{3}\log n)$`ででき,  
全体では`$O(k^{4}\log n)$`となる.

#### コード

****

{{< includeCode "/ONTAK/2008/leo.cpp" "cpp" >}}
