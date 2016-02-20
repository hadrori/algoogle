---
layout: page
title: "高速フーリエ変換"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(N \log N){% em %}
用途 | フーリエ変換する
  
N := 変換する列の長さ(2冪)  
  
invを指定すると逆変換  


#### 解説

***

以下の離散フーリエ変換の正変換と逆変換をする.  
結構誤差る


{% math %}

F(t) = \sum_{x=0}^{N-1} f(x)e^{-i\frac{2\pi tx}{N}}\\
f(x) = \frac{1}{N} \sum_{t=0}^{N-1} F(t)e^{i\frac{2\pi tx}{N}}

{% endmath %}

畳み込みを利用したいときに使うことが多い  
fとgは周期Nの周期関数とすると

{% math %}

(f*g)(x) = \sum_{n=0}^{N-1} f(n)g(x-n)\\
F(f*g) = F(f)F(g)

{% endmath %}

畳み込みを使うと多項式f, gの掛け算が以下のようにかける

{% math %}

f = \sum_{i=0}^{N-1} a_{i} x^{i}\\
g = \sum_{i=0}^{N-1} b_{i} x^{i}\\
\sum^{2N-2}_{j=0} \left( \sum_{i=0}^{j} a_{i}b_{j-i} \right) x^{j}

{% endmath %}

#### コード

***

{% include_code algorithm/fft.cpp %}

#### 問題

***  

{% for post in site.tags['fft'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
