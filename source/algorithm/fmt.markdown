---
layout: page
title: "高速剰余変換"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(N \log N){% em %}
用途 | 剰余環上でフーリエ変換する
  
N := 変換する列の長さ(2冪)  
  
invを指定すると逆変換  


#### 解説

***

基本的には[FFT](/algorithm/fft.html)と同じ.  
modがa\*2^k+1の形の時のみ使える.  
mod周りが面倒なのでmintクラスを使うことも考えたがパフォーマンスが倍ぐらい落ちるのでやめた.  

#### コード

***

{% include_code algorithm/fmt.cpp %}

#### 問題

***  

{% for post in site.tags['fft'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}