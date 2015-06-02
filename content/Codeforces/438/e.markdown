---
layout: post
title: "Codeforces 438E The Child and Binary Tree"
date: 2014-06-22T02:07:00+09:00
comments: true
category: Codeforces
tags: [fft, math]
---

[The Child and Binary Tree](http://codeforces.com/problemset/problem/438/E)

#### 問題概要

****

2分木の各ノードに重みを割り当てるとき, 合計の重さ1〜mのそれぞれになりうる木の数を求めよ.  
ただし各重さは`$\{ c_1, c_2, ..., c_n\} $`のいずれかで, 同じ重さは何度使っても良い.

#### 解法

****

FFTライブラリのverifyを兼ねて[editorial](http://codeforces.com/blog/entry/12513)見ながら解いた.  
ある重さの木の場合の数は根の重さとその2つの子の重さの場合によって決定する.  
よって木の重さがwになる場合の数f[w]は,  

<div> $ {\displaystyle
    \begin{eqnarray*}
    f[0] &=& 1\\
    f[w] &=& \sum_{i=1}^{n} \sum_{j=0}^{w-c_i} f[j]*f[w-c_i-j]\\
    \end{eqnarray*}
} $</div>

と表せる. またここで次数を重さとみた多項式を考えると

<div> $ {\displaystyle
    \begin{eqnarray*}
    F(z) &=& \sum_{k\geq 0} f[k]z^{k}\\
    C(z) &=& \sum_{k=1}^{n} z^{c_k}\\
    \end{eqnarray*}
} $</div>

1つ目は答えを係数に持つ多項式, 2つ目は使える重さの多項式が考えられる.  
ある重さの木の場合の数の条件からこの2つの多項式は以下の関係を持つことがわかる.  

<div> $ {\displaystyle
    \begin{eqnarray*}
    F(z) &=& C(z)F(z)^2+1
    \end{eqnarray*}
} $</div>

これを解くと

<div> $ {\displaystyle
    \begin{eqnarray*}
    F(z) &=& \frac{2}{1+\sqrt{1-4C(z)}}
    \end{eqnarray*}
} $</div>

となる. もう片方の解はf[0]が1であることを考えるとありえないことがわかる(`$ C(z)=2z-4z^{2} $` などを考えてみるとよい).  
  
あとはこれを実装すればよい. 多項式の平方根は  

<div> $ {\displaystyle
    \begin{eqnarray*}
    S_n(z)^2 \equiv F(z) && (mod \ z^n)
    \end{eqnarray*}
} $</div>

とすると

<div> $ {\displaystyle
    \begin{eqnarray*}
    S_{2n}(z) \equiv (S_n(z)+ F(z)S_n(z)^{-1})/2 && (mod \ z^{2n})
    \end{eqnarray*}
} $</div>

となるので順に計算すればよい.  
あとは多項式の積をFFT(modの制約から剰余環を使ったものがよい)を用いて計算すること.

#### コード

****

{{< includeCode "/Codeforces/438E.cpp" "cpp" >}}
