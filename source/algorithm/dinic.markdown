---
layout: page
title: "Dinic法"
comments: true
sharing: true
---

#### 基本情報
  
***

計算量 | {% m %}O(EV^2){% em %}
用途| 最大流を求める
  
E := 辺の数
V := 頂点数

#### 解説

***

基本的な部分では[Ford-Fulkerson](ford-fulkerson.html)と同じ.  
levelグラフ(ソースからの最短距離)を構築することで増加パスのうち最短のパスにフローを流す.  
そのような経路が存在しなくなったら残余ネットワークでもう一度構築する.  
それでも存在しなくなったら終了.  
Dinic法は一般に最悪ケースよりもかなり高速に動作する.  

#### コード

***

{% include_code algorithm/dinic.cpp %}


#### 問題

***  

{% for post in site.tags['max-flow'] %}
* [{{post.title | cdata_escape}}]({{post.url}})
{% endfor %}
