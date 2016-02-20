---
layout: page
title: "彩色数"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(2^{N}N){% em %}
空間 | {% m %}O(N){% em %}
  
N := 頂点数

#### 解説

***

頂点数Nのグラフの彩色数を求める.  
試しに塗ってみるのではなく, 包除原理を用いることによって求める.  
[指数時間アルゴリズム入門](http://www.slideshare.net/wata_orz/ss-12131479)(P58)を参照のこと.  
  
自明な枝刈り探索によって指数の底を1.6ぐらいに落とせるらしい.  

#### コード

***

{% include_code algorithm/graph-coloring.cpp %}

#### 問題

***

{% for post in site.tags['graph-coloring'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
