---
type: algorithm
title: "高速フーリエ変換"
tags: [fft]
comments: true
sharing: true
---

#### 基本情報
  
***

 | 
|:--|:--|
計算量 | `$O(N \log N)$`
用途 | フーリエ変換する
  
N := 変換する列の長さ(2冪)  
  
invを指定すると逆変換  


#### 解説

***

以下の離散フーリエ変換の正変換と逆変換をする.  
結構誤差る


<div> $ {\displaystyle

F(t) = \sum_{x=0}^{N-1} f(x)e^{-i\frac{2\pi tx}{N}}\\
\displaystyle
f(x) = \frac{1}{N} \sum_{t=0}^{N-1} F(t)e^{i\frac{2\pi tx}{N}}

} $ </div>

畳み込みを利用したいときに使うことが多い  
fとgは周期Nの周期関数とすると

<div> $ {\displaystyle

(f*g)(x) = \sum_{n=0}^{N-1} f(n)g(x-n)\\
\displaystyle
F(f*g) = F(f)F(g)

} $ </div>

畳み込みを使うと多項式f, gの掛け算が以下のようにかける

<div> $ {\displaystyle

f = \sum_{i=0}^{N-1} a_{i} x^{i}\\
\displaystyle
g = \sum_{i=0}^{N-1} b_{i} x^{i}\\
\displaystyle
\sum^{2N-2}_{j=0} \left( \sum_{i=0}^{j} a_{i}b_{j-i} \right) x^{j}

} $ </div>

#### コード

***

{{< includeCode "/algorithm/fft.cpp" "cpp" >}}

#### 問題

***  
