---
layout: page
title: "関節点"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(V+E){% em %}
用途| 関節点を求める
  
V := 頂点数  
E := 辺の数

#### 解説

***

#### コード

***

{% include_code algorithm/articulation-point.cpp %}


#### 問題

***  

{% for post in site.tags['articulation-point'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
