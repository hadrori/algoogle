---
layout: page
title: "Union Find Tree"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(\alpha (N)){% em %}
用途 | データの集合の併合と同じ集合に属しているかの判定
  
N := 頂点数  
{% m %}\alpha{% em %} := アッカーマン関数の逆関数

  
#### 解説

***

Union Find木では共通の親を持つかどうかで同じ木に属しているか判定する.  
また, 2つの要素を併合する場合は片方の親の子にもう片方の木を入れる.  
偏りをなくすために木のランクを保存しておいてランクの高い方に小さい方を併合するようにする.  
親を見つけるときにその途中結果をメモする(親に直接つなぐ).

#### コード

***

{% include_code algorithm/union_find.cpp %}


#### 問題

***  
{% for post in site.tags['union-find'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
